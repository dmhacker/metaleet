#ifndef METALEET_650_SOLUTION_HPP
#define METALEET_650_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail650 {
    // inner :: number -> number -> number -> pair<number>

    template <class ans, class n, class d,
        class guard = metal::same<metal::mod<n, d>, ZERO>>
    struct _inner {
        using type = typename _inner<metal::add<ans, d>,
            metal::div<n, d>, d>::type;
    };

    template <class ans, class n, class d>
    struct _inner<ans, n, d, metal::false_> {
        using type = metal::pair<ans, n>;
    };

    template <class ans, class n, class d>
    using inner = typename _inner<ans, n, d>::type;

    // outer :: number -> number -> number -> list<number> (3)

    template <class ans, class n, class d,
        class guard = metal::greater<n, ONE>>
    struct _outer {
        using type = typename _outer<metal::first<inner<ans, n, d>>,
            metal::second<inner<ans, n, d>>, metal::inc<d>>::type;
    };

    template <class ans, class n, class d>
    struct _outer<ans, n, d, metal::false_> {
        using type = metal::list<ans, n, d>;
    };

    template <class ans, class n, class d>
    using outer = typename _outer<ans, n, d>::type;
}

// solve650 :: number -> number

template <class n>
using solve650 = lfirst<detail650::outer<ZERO, n, TWO>>;

/*
// My original solution does not work on clang!
// However, it does compile correctly on g++ for some reason.

namespace detail650 {
    template <class n>
    struct _solve {

        // subproblem :: number -> number -> number

        template <class idx, class end>
        struct _subproblem {
            using type = metal::if_<metal::mod<end, idx>,
                typename _subproblem<metal::inc<idx>, end>::type,
                metal::min<metal::add<typename _solve<idx>::type, metal::div<end, idx>>, typename _subproblem<metal::inc<idx>, end>::type>>;
        };

        template <class end>
        struct _subproblem<end, end> {
            using type = end;
        };

        using type = typename _subproblem<TWO, n>::type;
    };

    template <>
    struct _solve<ONE> {
        using type = ZERO;
    };
}

// solve650 :: number -> number

template <class n>
using solve650 = typename detail650::_solve<n>::type;
*/

}

#endif
