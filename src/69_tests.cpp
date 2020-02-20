#include <catch.hpp>
#include <solutions/69_sqrt.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #69")
{
    REQUIRE(solve69<metal::number<0>>() == 0);
    REQUIRE(solve69<metal::number<1>>() == 1);
    REQUIRE(solve69<metal::number<2>>() == 1);
    REQUIRE(solve69<metal::number<4>>() == 2);
    REQUIRE(solve69<metal::number<8>>() == 2);
    REQUIRE(solve69<metal::number<37>>() == 6);
    REQUIRE(solve69<metal::number<67>>() == 8);
    REQUIRE(solve69<metal::number<100>>() == 10);
}
