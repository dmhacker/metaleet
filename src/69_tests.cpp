#include <catch.hpp>
#include <solutions/69_sqrt.hpp>

TEST_CASE("Test cases for problem #69")
{
    REQUIRE(metaleet::solve69<metal::number<0>>() == 0);
    REQUIRE(metaleet::solve69<metal::number<1>>() == 1);
    REQUIRE(metaleet::solve69<metal::number<2>>() == 1);
    REQUIRE(metaleet::solve69<metal::number<4>>() == 2);
    REQUIRE(metaleet::solve69<metal::number<8>>() == 2);
    REQUIRE(metaleet::solve69<metal::number<37>>() == 6);
    REQUIRE(metaleet::solve69<metal::number<67>>() == 8);
    REQUIRE(metaleet::solve69<metal::number<100>>() == 10);
}
