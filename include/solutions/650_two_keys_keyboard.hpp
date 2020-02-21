#ifndef METALEET_650_SOLUTION_HPP
#define METALEET_650_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

// inner :: number -> number -> number -> pair<number>

template <class ans, class n, class d, 
    class guard = metal::same<metal::mod<n, d>, ZERO>>
struct _inner_impl {
    using type = typename _inner_impl<metal::add<ans, d>, 
        metal::div<n, d>, d>::type;
};

template <class ans, class n, class d>
struct _inner_impl<ans, n, d, metal::false_> {
    using type = metal::pair<ans, n>;
};

template <class ans, class n, class d>
using inner = typename _inner_impl<ans, n, d>::type;

// outer :: number -> number -> number -> list<number> (3)

template <class ans, class n, class d,
         class guard = metal::greater<n, ONE>>
struct _outer_impl {
    using type = typename _outer_impl<metal::first<inner<ans, n, d>>, 
        metal::second<inner<ans, n, d>>, metal::inc<d>>::type;
};

template <class ans, class n, class d>
struct _outer_impl<ans, n, d, metal::false_> {
    using type = metal::list<ans, n, d>; 
};

template <class ans, class n, class d>
using outer = typename _outer_impl<ans, n, d>::type;

// solve650 :: number -> number

template <class n>
struct _solve650_impl {
    using type = metal::at<outer<ZERO, n, TWO>, ZERO>;
};

/*
// My original solution does not work on clang-9!
// However, it does compile correctly on g++ for some reason.

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
struct _solve650_impl<ONE> {
    using type = ZERO;
};
*/

template <class n>
using solve650 = typename _solve650_impl<n>::type;

}

#endif
