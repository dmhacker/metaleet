#include <catch.hpp>
#include <metal.hpp>

// sqr :: number -> number

template <class n>
using sqr = metal::mul<n, n>;

// solve :: number -> number

template <class n>
struct _solve_impl {

    // loop :: number -> number -> number
    
    template <class res, class idx, class guard = metal::greater<sqr<idx>, n>>
    struct _loop_impl {
        using type = typename _loop_impl<
            metal::min<res, metal::inc<typename _solve_impl<metal::sub<n, sqr<idx>>>::type>>,
            metal::inc<idx>>::type;
    };

    template <class res, class idx>
    struct _loop_impl<res, idx, metal::true_> {
        using type = res;
    };

    template <class res, class idx>
    using loop = typename _loop_impl<res, idx>::type;

    using type = loop<metal::number<5>, metal::number<1>>;
};

template <>
struct _solve_impl<metal::number<1>> {
    using type = metal::number<1>;
};

template <>
struct _solve_impl<metal::number<0>> {
    using type = metal::number<0>;
};

template <class n>
using solve = typename _solve_impl<n>::type;

// BEGIN TEST CASES

TEST_CASE("Test cases for problem #279")
{
    REQUIRE(solve<metal::number<7>>() == 4);
    REQUIRE(solve<metal::number<12>>() == 3);
    REQUIRE(solve<metal::number<13>>() == 2);
    REQUIRE(solve<metal::number<71>>() == 4);
    REQUIRE(solve<metal::number<100>>() == 1);
    REQUIRE(solve<metal::number<196>>() == 1);
    REQUIRE(solve<metal::number<263>>() == 4);
    REQUIRE(solve<metal::number<313>>() == 2);
    REQUIRE(solve<metal::number<364>>() == 3);
}

// END TEST CASES
