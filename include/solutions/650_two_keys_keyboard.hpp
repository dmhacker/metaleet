#ifndef METALEET_650_SOLUTION_HPP
#define METALEET_650_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail650 {
    // inner :: number -> number -> number -> pair<number>

    template <class ans, class n, class d,
        class guard = metal::same<metal::mod<n, d>, ZERO>>
    struct inner_impl {
        using type = typename inner_impl<metal::add<ans, d>,
            metal::div<n, d>, d>::type;
    };

    template <class ans, class n, class d>
    struct inner_impl<ans, n, d, metal::false_> {
        using type = metal::pair<ans, n>;
    };

    template <class ans, class n, class d>
    using inner = typename inner_impl<ans, n, d>::type;

    // outer :: number -> number -> number -> list<number> (3)

    template <class ans, class n, class d,
        class guard = metal::greater<n, ONE>>
    struct outer_impl {
        using type = typename outer_impl<metal::first<inner<ans, n, d>>,
            metal::second<inner<ans, n, d>>, metal::inc<d>>::type;
    };

    template <class ans, class n, class d>
    struct outer_impl<ans, n, d, metal::false_> {
        using type = metal::list<ans, n, d>;
    };

    template <class ans, class n, class d>
    using outer = typename outer_impl<ans, n, d>::type;
}

// solve650 :: number -> number

template <class n>
using solve650 = lfirst<detail650::outer<ZERO, n, TWO>>;

/*
// My original solution does not work on clang-9!
// However, it does compile correctly on g++ for some reason.

namespace detail650 {
    template <class n>
    struct solve_impl {

        // subproblem :: number -> number -> number

        template <class idx, class end>
        struct subproblem_impl {
            using type = metal::if_<metal::mod<end, idx>,
                typename subproblem_impl<metal::inc<idx>, end>::type,
                metal::min<metal::add<typename solve_impl<idx>::type, metal::div<end, idx>>, typename subproblem_impl<metal::inc<idx>, end>::type>>;
        };

        template <class end>
        struct subproblem_impl<end, end> {
            using type = end;
        };

        using type = typename subproblem_impl<TWO, n>::type;
    };

    template <>
    struct solve_impl<ONE> {
        using type = ZERO;
    };
}

// solve650 :: number -> number

template <class n>
using solve650 = typename detail650::solve_impl<n>::type;
*/

}

#endif
