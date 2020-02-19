#include <catch.hpp>
#include <metal.hpp>
#include <iostream>


// Parse number literals as a metal::list<>

template<char... cs>
constexpr auto operator ""_raw()
    -> metal::numbers<cs...> {
    return {};
}

// Section for easily-reusable constants

using ZERO = metal::number<0>;
using ONE = metal::number<1>;

// append_at :: list<list<X>> -> number -> X -> list<list<X>>

template <class rows, class ridx, class val>
using append_at = metal::insert<metal::erase<rows, ridx, metal::inc<ridx>>, ridx, metal::append<metal::at<rows, ridx>, val>>;

// fill_rows :: list<char> -> list<list<char>> -> list<list<char>>

template <class seq, class rows, class sidx, class ridx, class down, 
         class done = metal::same<metal::size<seq>, sidx>>
struct _fill_rows_impl {
    using type = typename _fill_rows_impl<seq, append_at<rows, ridx, metal::at<seq, sidx>>, 
        metal::inc<sidx>,
          metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, 
          metal::if_<metal::or_<
              metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, ZERO>, 
                metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, metal::dec<metal::size<rows>>>>, 
                metal::not_<down>, down>>::type;
};

template <class seq, class rows, class sidx, class ridx, class down>
struct _fill_rows_impl<seq, rows, sidx, ridx, down, metal::true_> {
    using type = rows;
};

template<class seq, class rows>
using fill_rows = typename _fill_rows_impl<seq, rows, ZERO, ZERO, metal::true_>::type;

// solve :: list<char> -> number

template<class seq, class num_rows>
struct _solve_impl {
    using type = metal::flatten<fill_rows<seq, metal::repeat<metal::list<>, num_rows>>>;
};

template<class seq>
struct _solve_impl<seq, ONE> {
    using type = seq;
};

template <class seq, class num_rows>
using solve = typename _solve_impl<seq, num_rows>::type;

// BEGIN TEST CASES

TEST_CASE("Test cases for problem #6")
{
    REQUIRE(metal::same<solve<metal::numbers<>, metal::number<100>>, metal::numbers<>>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<1>>, decltype(12345_raw)>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<2>>, decltype(13524_raw)>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<3>>, decltype(15243_raw)>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<4>>, decltype(12354_raw)>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<5>>, decltype(12345_raw)>());
    REQUIRE(metal::same<solve<decltype(12345_raw), metal::number<6>>, decltype(12345_raw)>());
    REQUIRE(metal::same<solve<decltype(1234567890_raw), metal::number<3>>, decltype(1592468037_raw)>());
    REQUIRE(metal::same<solve<decltype(1234567890_raw), metal::number<4>>, decltype(1726835940_raw)>());
}

// END TEST CASES 
