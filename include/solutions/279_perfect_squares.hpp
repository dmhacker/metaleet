#ifndef METALEET_279_SOLUTION_HPP
#define METALEET_279_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail279 {
    template <class n>
    struct solve_impl {
        // loop :: number -> number -> number

        template <class res, class idx, class guard = metal::greater<sqr<idx>, n>>
        struct loop_impl {
            using type = typename loop_impl<
                metal::min<res, metal::inc<typename solve_impl<metal::sub<n, sqr<idx>>>::type>>,
                metal::inc<idx>>::type;
        };

        template <class res, class idx>
        struct loop_impl<res, idx, metal::true_> {
            using type = res;
        };

        using type = typename loop_impl<metal::number<5>, ONE>::type;
    };

    template <>
    struct solve_impl<ONE> {
        using type = ONE;
    };

    template <>
    struct solve_impl<ZERO> {
        using type = ZERO;
    };
}

// solve279 :: number -> number

template <class n>
using solve279 = typename detail279::solve_impl<n>::type;

}

#endif
