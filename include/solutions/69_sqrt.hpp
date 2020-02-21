#ifndef METALEET_69_SOLUTION_HPP
#define METALEET_69_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

// ternary_switch :: number -> number -> a -> a -> a

template <class x, class y, class gt, class eq, class lt>
using ternary_switch = metal::if_<metal::greater<x, y>, gt, metal::if_<metal::less<x, y>, lt, eq>>;

// mid :: number -> number -> number

template <class left, class right>
using mid = metal::div<metal::add<left, right>, TWO>;

// binary_search :: number -> number -> number -> number

template <class n, class left, class right, class guard = metal::greater<left, right>>
struct _binary_search_impl {
    using type = ternary_switch<metal::div<n, mid<left, right>>, mid<left, right>,
        typename _binary_search_impl<n, metal::inc<mid<left, right>>, right>::type,
        mid<left, right>,
        typename _binary_search_impl<n, left, metal::dec<mid<left, right>>>::type>;
};

template <class n, class left, class right>
struct _binary_search_impl<n, left, right, metal::true_> {
    using type = right;
};

template <class n, class left, class right>
using binary_search = typename _binary_search_impl<n, left, right>::type;

// solve69 :: number -> number

template <class n>
struct _solve69_impl {
    using type = binary_search<n, ONE, metal::div<n, TWO>>;
};

template <>
struct _solve69_impl<ONE> {
    using type = ONE;
};

template <class n>
using solve69 = typename _solve69_impl<n>::type;

}

#endif
