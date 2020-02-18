#include <catch.hpp>
#include <metal.hpp>
#include <iostream>

// string_ is an alias for metal::numbers that only takes in char values. 

template <char... str>
using string_ = metal::numbers<str...>;

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
    using type = typename _fill_rows_impl<seq, append_to_row<rows, ridx, metal::at<seq, sidx>>, metal::inc<sidx>, 
          metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, 
          metal::if_<metal::or_<
              metal::same<ridx, ZERO>, 
                metal::same<ridx, metal::dec<metal::size<rows>>>>, 
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
    REQUIRE(metal::same<solve<string_<>, metal::number<100>>, string_<>>());
    REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<1>>, string_<'A', 'B', 'C', 'D', 'E'>>());
    REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<2>>, string_<'A', 'C', 'E', 'B', 'D'>>());
    /* REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<3>>, string_<'A', 'E', 'B', 'D', 'C'>>()); */
    /* REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<4>>, string_<'A', 'B', 'C', 'E', 'D'>>()); */
    /* REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, string_<'A', 'B', 'C', 'D', 'E'>>()); */
    /* REQUIRE(metal::same<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<6>>, string_<'A', 'B', 'C', 'D', 'E'>>()); */
    std::cerr << static_cast<char>(metal::at<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, ZERO>()) << std::endl;
    std::cerr << static_cast<char>(metal::at<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, metal::number<1>>()) << std::endl;
    std::cerr << static_cast<char>(metal::at<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, metal::number<2>>()) << std::endl;
    std::cerr << static_cast<char>(metal::at<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, metal::number<3>>()) << std::endl;
    // std::cerr << static_cast<char>(metal::at<solve<string_<'A', 'B', 'C', 'D', 'E'>, metal::number<5>>, metal::number<4>>()) << std::endl;
}

// END TEST CASES 
