#ifndef METALEET_69_SOLUTION_HPP
#define METALEET_69_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail69 {
    // ternary_switch :: number -> number -> a -> a -> a

    template <class x, class y, class gt, class eq, class lt>
    using ternary_switch = metal::if_<metal::greater<x, y>, gt, metal::if_<metal::less<x, y>, lt, eq>>;

    // bsearch :: number -> number -> number -> number

    template <class n, class left, class right, class guard = metal::greater<left, right>>
    struct bsearch_impl {
        using type = ternary_switch<metal::div<n, average<left, right>>, average<left, right>,
            typename bsearch_impl<n, metal::inc<average<left, right>>, right>::type,
            average<left, right>,
            typename bsearch_impl<n, left, metal::dec<average<left, right>>>::type>;
    };

    template <class n, class left, class right>
    struct bsearch_impl<n, left, right, metal::true_> {
        using type = right;
    };

    template <class n, class left, class right>
    using bsearch = typename bsearch_impl<n, left, right>::type;

    template <class n>
    struct solve_impl {
        using type = bsearch<n, ONE, metal::div<n, TWO>>;
    };

    template <>
    struct solve_impl<ONE> {
        using type = ONE;
    };
}

// solve69 :: number -> number

template <class n>
using solve69 = typename detail69::solve_impl<n>::type;

}

#endif
