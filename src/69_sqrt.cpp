#include <catch.hpp>
#include <metal.hpp>

// ternary_switch :: number -> number -> a -> a -> a

template <class x, class y, class gt, class eq, class lt>
using ternary_switch = metal::if_<metal::greater<x, y>, gt, metal::if_<metal::less<x, y>, lt, eq>>;

// mid :: number -> number -> number

template <class left, class right>
using mid = metal::div<metal::add<left, right>, metal::number<2>>;

// binary_search :: number -> number -> number -> number

template <class n, class left, class right, class guard = metal::greater<left, right>>
struct _binary_search_impl {
    using value = 
        ternary_switch<metal::div<n, mid<left, right>>, mid<left, right>,
            typename _binary_search_impl<n, metal::inc<mid<left, right>>, right>::value,
            mid<left, right>,
            typename _binary_search_impl<n, left, metal::dec<mid<left, right>>>::value>;
};

template <class n, class left, class right>
struct _binary_search_impl<n, left, right, metal::true_> {
    using value = right;
};

template <class n, class left, class right>
using binary_search = typename _binary_search_impl<n, left, right>::value;

// solve :: number -> number

template <class n>
struct solve {
    using value = binary_search<n, metal::number<1>, metal::div<n, metal::number<2>>>;
};

template <>
struct solve<metal::number<1>> {
    using value = metal::number<1>;
};

template <>
struct solve<metal::number<0>> {
    using value = metal::number<0>;
};

// BEGIN TEST CASES

TEST_CASE("Test cases for problem #69")
{
    REQUIRE(solve<metal::number<4>>::value() == 2);
    REQUIRE(solve<metal::number<8>>::value() == 2);
    REQUIRE(solve<metal::number<37>>::value() == 6);
    REQUIRE(solve<metal::number<67>>::value() == 8);
    REQUIRE(solve<metal::number<100>>::value() == 10);
}

// END TEST CASES
