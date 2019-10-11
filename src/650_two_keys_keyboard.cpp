#include <metal.hpp>
#include <catch.hpp>

template <class n>
struct solve {
    template <class idx, class end>
    struct subproblem {
        using value = metal::if_<metal::mod<end, idx>, 
              typename subproblem<metal::inc<idx>, end>::value, 
              metal::min<metal::add<typename solve<idx>::value, metal::div<end, idx>>, typename subproblem<metal::inc<idx>, end>::value>>;
    };

    template <class end>
    struct subproblem<end, end> {
        using value = end;
    };

    using value = typename subproblem<metal::number<2>, n>::value;
};

template <>
struct solve<metal::number<1>> {
    using value = metal::number<0>;
};

TEST_CASE("Leetcode test cases") {
    REQUIRE(solve<metal::number<1>>::value() == 0);
    REQUIRE(solve<metal::number<3>>::value() == 3);
    REQUIRE(solve<metal::number<8>>::value() == 6);
    REQUIRE(solve<metal::number<10>>::value() == 7);
    REQUIRE(solve<metal::number<50>>::value() == 12);
    REQUIRE(solve<metal::number<71>>::value() == 71);
    REQUIRE(solve<metal::number<100>>::value() == 14);
}
