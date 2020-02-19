#include <metal.hpp>

namespace metaleet {

// solve650 :: number -> number

template <class n>
struct _solve650_impl {

    // subproblem :: number -> number -> number

    template <class idx, class end>
    struct _subproblem_impl {
        using type = metal::if_<metal::mod<end, idx>,
            typename _subproblem_impl<metal::inc<idx>, end>::type,
            metal::min<metal::add<typename _solve650_impl<idx>::type, metal::div<end, idx>>, typename _subproblem_impl<metal::inc<idx>, end>::type>>;
    };

    template <class end>
    struct _subproblem_impl<end, end> {
        using type = end;
    };

    template <class idx, class end>
    using subproblem = typename _subproblem_impl<idx, end>::type;

    using type = subproblem<metal::number<2>, n>;
};

template <>
struct _solve650_impl<metal::number<1>> {
    using type = metal::number<0>;
};

template <class n>
using solve650 = typename _solve650_impl<n>::type;

}
