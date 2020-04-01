#ifndef METALEET_227_SOLUTION_HPP
#define METALEET_227_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail227 {
    // make_pairs :: list<a> -> list<pair<a, a>>

    template <class idx, class seq>
    struct _make_pairs {
        using type = metal::append<typename _make_pairs<metal::dec<idx>, seq>::type,
            metal::pair<metal::at<seq, idx>, metal::at<seq, metal::inc<idx>>>>;
    };

    template <class seq>
    struct _make_pairs<metal::number<-1>, seq> {
        using type = metal::list<>;
    };

    template <class seq>
    using make_pairs = typename _make_pairs<metal::sub<metal::size<seq>, TWO>, seq>::type;

    // As clarification, the 'char' type is simply a number acting as a character.
    // precedence :: char -> number

    template <class token>
    using precedence = metal::if_<
        metal::or_<metal::same<token, MINUS>, metal::same<token, PLUS>>,
        metal::number<1>, metal::if_<metal::or_<metal::same<token, MULT>, metal::same<token, DIV>>, metal::number<2>, metal::number<0>>>;

    // is_operator :: char -> bool

    template <class token>
    using is_operator = metal::greater<precedence<token>, ZERO>;

    // get_operation :: char -> (number -> number -> number)

    template <class token>
    using get_operation = metal::if_<metal::same<token, PLUS>, metal::lambda<metal::add>,
        metal::if_<metal::same<token, MINUS>, metal::lambda<metal::sub>,
            metal::if_<metal::same<token, MULT>, metal::lambda<metal::mul>,
                metal::lambda<metal::div>>>>;

    // invoke_operation :: list<char> -> list<number> -> number

    template <class ops, class nums>
    using invoke_operation = metal::invoke<get_operation<metal::back<ops>>, metal::at<nums, metal::sub<metal::size<nums>, TWO>>, metal::back<nums>>;

    // drain_operations :: list<char> -> list<number> -> number -> list<list<char>, list<number>>

    template <class ops, class nums, class tokenpred>
    struct _drain_operations {
        using type = metal::if_<geq<precedence<metal::back<ops>>, tokenpred>,
            typename _drain_operations<
                pop1<ops>,
                metal::append<pop2<nums>, invoke_operation<ops, nums>>,
                tokenpred>::type,
            metal::list<ops, nums>>;
    };

    template <class nums, class tokenpred>
    struct _drain_operations<metal::list<>, nums, tokenpred> {
        using type = metal::list<metal::list<>, nums>;
    };

    template <class ops, class nums, class tokenpred>
    using drain_operations = typename _drain_operations<ops, nums, tokenpred>::type;

    // drain_operations_direct :: list<list<char>, list<number>> -> number -> list<list<char>, list<number>>

    template <class state, class tokenpred>
    using drain_operations_direct = typename _drain_operations<lfirst<state>, lsecond<state>, tokenpred>::type;

    // parse_operation :: list<char> -> list<number> -> char -> list<list<char>, list<number>, char>

    template <class ops, class nums, class curr, class token>
    using parse_operation = metal::list<
        metal::append<lfirst<drain_operations<ops, nums, precedence<token>>>, token>,
        lsecond<drain_operations<ops, nums, precedence<token>>>,
        curr>;

    // parse_operation_direct :: list<list<char>, list<number>, char> -> list<list<char>, list<number>, char>

    template <class state, class token>
    using parse_operation_direct = parse_operation<
        lfirst<state>,
        lsecond<state>,
        metal::at<state, TWO>,
        token>;

    // to_number :: char -> number

    template <class token>
    using to_number = metal::sub<token, metal::number<'0'>>;

    // next_number :: number -> char -> number

    template <class curr, class token>
    using next_number = metal::add<metal::mul<curr, metal::number<10>>, to_number<token>>;

    // parse_number :: list<char> -> list<number> -> number -> char -> char -> list<list<char>, list<number>, number>

    template <class ops, class nums, class curr, class token0, class token1>
    using parse_number = metal::if_<metal::or_<is_operator<token1>, metal::same<token1, metal::number<' '>>>,
        metal::list<ops, metal::append<nums, next_number<curr, token0>>, metal::number<0>>,
        metal::list<ops, nums, next_number<curr, token0>>>;

    // parse_number_direct :: list<list<char>, list<number>, number> -> char -> char -> list<list<char>, list<number>, number>

    template <class state, class token0, class token1>
    using parse_number_direct = parse_number<
        lfirst<state>,
        lsecond<state>,
        metal::at<state, TWO>, token0, token1>;

    // parse_tokenpair :: list<list<char>, list<number>, number> -> pair<char, char> -> list<list<char>, list<number>, number>

    template <class state, class token0, class token1, class is_op0>
    struct _parse_tokenpair {
        using type = state;
    };

    template <class state, class token1, class is_op0>
    struct _parse_tokenpair<state, metal::number<' '>, token1, is_op0> {
        using type = state;
    };

    template <class state, class token0, class token1>
    struct _parse_tokenpair<state, token0, token1, metal::true_> {
        using type = parse_operation_direct<state, token0>;
    };

    template <class state, class token0, class token1>
    struct _parse_tokenpair<state, token0, token1, metal::false_> {
        using type = parse_number_direct<state, token0, token1>;
    };

    template <class state, class tokenpair>
    using parse_tokenpair = typename _parse_tokenpair<
        state,
        metal::first<tokenpair>,
        metal::second<tokenpair>,
        is_operator<metal::first<tokenpair>>>::type;

    // eval :: list<char> -> list<list<char>, list<number>, number>

    template <class seq>
    using eval = drain_operations_direct<
        metal::accumulate<metal::lambda<parse_tokenpair>,
            metal::list<metal::list<>, metal::list<>, ZERO>,
            make_pairs<metal::append<seq, metal::number<' '>>>>,
        ZERO>;
}

// solve227 :: list<char> -> number

template <class seq>
using solve227 = lfirst<lsecond<detail227::eval<seq>>>;

}

#endif
