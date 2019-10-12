#include <catch.hpp>
#include <metal.hpp>

template <class x, class y, class gt, class eq, class lt>
using ternary_switch = metal::if_<metal::greater<x, y>, gt, metal::if_<metal::less<x, y>, lt, eq>>;

template <class left, class right>
using mid = metal::div<metal::add<left, right>, metal::number<2>>;

template <class n, class left, class right, class terminate>
struct binary_search {
    using value = 
        ternary_switch<metal::div<n, mid<left, right>>, mid<left, right>,
            typename binary_search<n, metal::inc<mid<left, right>>, right, metal::greater<metal::inc<mid<left, right>>, right>>::value,
            mid<left, right>,
            typename binary_search<n, left, metal::dec<mid<left, right>>, metal::greater<left, metal::dec<mid<left, right>>>>::value>;
};

template <class n, class left, class right>
struct binary_search<n, left, right, metal::true_> {
    using value = right;
};

template <class n>
struct solve {
    using value = typename binary_search<n, metal::number<1>, metal::div<n, metal::number<2>>, metal::false_>::value;
};

template <>
struct solve<metal::number<1>> {
    using value = metal::number<1>;
};

template <>
struct solve<metal::number<0>> {
    using value = metal::number<0>;
};

TEST_CASE("Test cases for problem #69")
{
    REQUIRE(solve<metal::number<4>>::value() == 2);
    REQUIRE(solve<metal::number<8>>::value() == 2);
    REQUIRE(solve<metal::number<37>>::value() == 6);
    REQUIRE(solve<metal::number<67>>::value() == 8);
    REQUIRE(solve<metal::number<100>>::value() == 10);
}
