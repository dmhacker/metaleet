#include <catch.hpp>
#include <metal.hpp>
    
#define IS_SAME(X, Y) static_assert(std::is_same<X, Y>{}, "")

using ZERO = metal::number<0>;
using ONE = metal::number<1>;
using TWO = metal::number<2>;
using PLUS = metal::number<'-'>;
using MINUS = metal::number<'+'>;
using MULT = metal::number<'*'>;
using DIV = metal::number<'/'>;

template <class seq>
using lfirst = metal::at<seq, ZERO>;

template <class seq>
using lsecond = metal::at<seq, ONE>;

template <class idx, class seq>
struct _make_pairs_impl {
    using type = metal::append<typename _make_pairs_impl<metal::dec<idx>, seq>::type, 
          metal::pair<metal::at<seq, idx>, metal::at<seq, metal::inc<idx>>>>;
};

template <class seq>
struct _make_pairs_impl<metal::number<-1>, seq> {
    using type = metal::list<>;
};

template <class seq>
using make_pairs = typename _make_pairs_impl<metal::sub<metal::size<seq>, TWO>, seq>::type;

template <char...str>
using string_ = metal::numbers<str...>;

template <class token>
using precedence = metal::if_<
    metal::or_<metal::same<token, MINUS>, metal::same<token, PLUS>>, 
    metal::number<1>, metal::number<2>>;

template <class token>
using is_operator = metal::or_<
    metal::same<token, PLUS>,
    metal::same<token, MINUS>,
    metal::same<token, MULT>,
    metal::same<token, DIV>>;

template <class token>
using get_operation = metal::if_<metal::same<token, PLUS>, metal::lambda<metal::add>, 
      metal::if_<metal::same<token, MINUS>, metal::lambda<metal::sub>,
      metal::if_<metal::same<token, MULT>, metal::lambda<metal::mul>, 
      metal::lambda<metal::div>>>>;

template <class ops, class nums>
using invoke_operation = 
    metal::invoke<get_operation<metal::back<ops>>, metal::at<nums, metal::sub<metal::size<nums>, metal::number<2>>>, metal::back<nums>>;

template <class stack>
using pop1 = metal::take<stack, metal::dec<metal::size<stack>>>;

template <class stack>
using pop2 = metal::take<stack, metal::sub<metal::size<stack>, metal::number<2>>>;

template <class ops, class nums, class tokenpred>
struct _drain_operations_impl {
    using type = metal::if_<metal::not_<metal::less<precedence<metal::back<ops>>, tokenpred>>, 
          typename _drain_operations_impl<pop1<ops>, metal::append<pop2<nums>, invoke_operation<ops, nums>>, tokenpred>::type,
          metal::list<ops, nums>>;
};

template <class nums, class tokenpred>
struct _drain_operations_impl<metal::list<>, nums, tokenpred> {
    using type = metal::list<metal::list<>, nums>;
};

template <class ops, class nums, class token>
using drain_operations = typename _drain_operations_impl<ops, nums, token>::type; 

template <class state, class token>
using drain_operations_direct = drain_operations<metal::first<state>, metal::second<state>, token>; 

template <class ops, class nums, class curr, class token>
using parse_operation = metal::list<
    metal::append<lfirst<drain_operations<ops, nums, precedence<token>>>, token>,
    lsecond<drain_operations<ops, nums, precedence<token>>>, curr>;

template <class state, class token>
using parse_operation_direct = parse_operation< 
    lfirst<state>,
    lsecond<state>,
    metal::at<state, TWO>, token>;

template <class token>
using to_number = metal::sub<token, metal::number<'0'>>;

template <class curr, class token>
using next_number = metal::add<metal::mul<curr, metal::number<10>>, to_number<token>>;

template <class ops, class nums, class curr, class token0, class token1>
using parse_number = metal::if_<metal::or_<is_operator<token1>, metal::same<token1, metal::number<' '>>>,
      metal::list<ops, metal::append<nums, next_number<curr, token0>>, metal::number<0>>,
      metal::list<ops, nums, next_number<curr, token0>>>;

template <class state, class token0, class token1>
using parse_number_direct = parse_number< 
    lfirst<state>,
    lsecond<state>,
    metal::at<state, TWO>, token0, token1>;

template <class state, class token0, class token1> 
struct _parse_tokenpair_impl {
    using type = metal::if_<is_operator<token0>, 
        parse_operation_direct<state, token0>,
        parse_number_direct<state, token0, token1>>;
};

template <class state, class token1> 
struct _parse_tokenpair_impl<state, metal::number<' '>, token1> {
    using type = state;
};

template <class state, class tokenpair>
using parse_tokenpair = typename _parse_tokenpair_impl<
    state,
    metal::first<tokenpair>,
    metal::second<tokenpair>>::type;

template <class seq>
using eval = // drain_operations_direct<
    metal::accumulate<
      metal::lambda<parse_tokenpair>,
      metal::list<metal::list<>, metal::list<>, ZERO>,
      make_pairs<seq>>;
    // ZERO>;

template <class seq>
using add_buffer = metal::append<seq, metal::number<' '>>;

template <class seq>
using solve = lfirst<lsecond<eval<add_buffer<seq>>>>;

TEST_CASE("Test cases for problem #227")
{
    /* static_assert(std::is_same<lsecond<eval<string_<'3', '2', ' '>>>, string_<32>>{}, ""); */
    REQUIRE(solve<string_<'3'>>() == 3);
    REQUIRE(solve<string_<'0'>>() == 0);
    REQUIRE(solve<string_<'3', '2', '3'>>() == 323);
    /* REQUIRE(solve<string_<'3', '+', '2', '*', '2'>>() == 7); */
}
