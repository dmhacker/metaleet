#ifndef METALEET_279_SOLUTION_HPP
#define METALEET_279_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

// sqr :: number -> number

template <class n>
using sqr = metal::mul<n, n>;

// solve :: number -> number

template <class n>
struct _solve279_impl {

    // loop :: number -> number -> number

    template <class res, class idx, class guard = metal::greater<sqr<idx>, n>>
    struct _loop_impl {
        using type = typename _loop_impl<
            metal::min<res, metal::inc<typename _solve279_impl<metal::sub<n, sqr<idx>>>::type>>,
            metal::inc<idx>>::type;
    };

    template <class res, class idx>
    struct _loop_impl<res, idx, metal::true_> {
        using type = res;
    };

    template <class res, class idx>
    using loop = typename _loop_impl<res, idx>::type;

    using type = loop<metal::number<5>, ONE>;
};

template <>
struct _solve279_impl<ONE> {
    using type = ONE;
};

template <>
struct _solve279_impl<ZERO> {
    using type = ZERO;
};

template <class n>
using solve279 = typename _solve279_impl<n>::type;

}

#endif
