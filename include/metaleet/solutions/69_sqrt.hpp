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
    struct _bsearch {
        using type = ternary_switch<metal::div<n, average<left, right>>, average<left, right>,
            typename _bsearch<n, metal::inc<average<left, right>>, right>::type,
            average<left, right>,
            typename _bsearch<n, left, metal::dec<average<left, right>>>::type>;
    };

    template <class n, class left, class right>
    struct _bsearch<n, left, right, metal::true_> {
        using type = right;
    };

    template <class n, class left, class right>
    using bsearch = typename _bsearch<n, left, right>::type;

    template <class n>
    struct _solve {
        using type = bsearch<n, ONE, metal::div<n, TWO>>;
    };

    template <>
    struct _solve<ONE> {
        using type = ONE;
    };
}

// solve69 :: number -> number

template <class n>
using solve69 = typename detail69::_solve<n>::type;

}

#endif
