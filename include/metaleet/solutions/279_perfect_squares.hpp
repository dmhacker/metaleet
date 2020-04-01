#ifndef METALEET_279_SOLUTION_HPP
#define METALEET_279_SOLUTION_HPP

#include <metaleet/common/unified.hpp>

namespace metaleet {

namespace detail279 {
    template <class n>
    struct _solve {
        // loop :: number -> number -> number

        template <class res, class idx, class guard = metal::greater<sqr<idx>, n>>
        struct _loop {
            using type = typename _loop<
                metal::min<res, metal::inc<typename _solve<metal::sub<n, sqr<idx>>>::type>>,
                metal::inc<idx>>::type;
        };

        template <class res, class idx>
        struct _loop<res, idx, metal::true_> {
            using type = res;
        };

        using type = typename _loop<metal::number<5>, ONE>::type;
    };

    template <>
    struct _solve<ONE> {
        using type = ONE;
    };

    template <>
    struct _solve<ZERO> {
        using type = ZERO;
    };
}

// solve279 :: number -> number

template <class n>
using solve279 = typename detail279::_solve<n>::type;

}

#endif
