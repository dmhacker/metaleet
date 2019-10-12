#include <catch.hpp>
#include <metal.hpp>

template <class n>
struct _solve_impl {
    template <class idx, class end>
    struct _subproblem_impl {
        using type = metal::if_<metal::mod<end, idx>,
            typename _subproblem_impl<metal::inc<idx>, end>::type,
            metal::min<metal::add<typename _solve_impl<idx>::type, metal::div<end, idx>>, typename _subproblem_impl<metal::inc<idx>, end>::type>>;
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
struct _solve_impl<metal::number<1>> {
    using type = metal::number<0>;
};

template <class n>
using solve = typename _solve_impl<n>::type;

TEST_CASE("Test cases for problem #650")
{
    REQUIRE(solve<metal::number<1>>() == 0);
    REQUIRE(solve<metal::number<3>>() == 3);
    REQUIRE(solve<metal::number<8>>() == 6);
    REQUIRE(solve<metal::number<10>>() == 7);
    REQUIRE(solve<metal::number<50>>() == 12);
    REQUIRE(solve<metal::number<71>>() == 71);
    REQUIRE(solve<metal::number<100>>() == 14);
}
