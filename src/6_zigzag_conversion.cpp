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

// append_to_row :: list<list<char>> -> number -> char -> list<list<char>>

template <class accum, class rows, class ridx, class idx, class val, 
        class met = metal::same<idx, ridx>,
         class done = metal::same<idx, metal::size<rows>>>
struct _append_to_row_impl {
    using type = typename _append_to_row_impl<metal::append<accum, metal::at<rows, idx>>, rows, ridx, metal::inc<idx>, val>::type;
};

template <class accum, class rows, class ridx, class idx, class val, class met>
struct _append_to_row_impl<accum, rows, ridx, idx, val, met, metal::true_> {
    using type = accum;
};

template <class accum, class rows, class ridx, class idx, class val, class done>
struct _append_to_row_impl<accum, rows, ridx, idx, val, metal::true_, done> {
    using type = typename _append_to_row_impl<metal::append<accum, metal::append<metal::at<rows, idx>, val>>, rows, ridx, metal::inc<idx>, val>::type;
};

template <class rows, class ridx, class val>
using append_to_row = typename _append_to_row_impl<metal::list<>, rows, ridx, ZERO, val>::type;

// fill_rows :: list<char> -> list<list<char>> -> list<list<char>>

template <class seq, class rows, class sidx, class ridx, class down, 
         class done = metal::same<metal::size<seq>, sidx>>
struct _fill_rows_impl {
    using type = typename _fill_rows_impl<seq, append_to_row<rows, ridx, metal::at<seq, sidx>>, 
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
struct _solve_impl<seq, metal::number<1>> {
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
}

// END TEST CASES 
