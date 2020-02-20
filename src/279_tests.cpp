#include <catch.hpp>
#include <solutions/279_perfect_squares.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #279")
{
    REQUIRE(solve279<metal::number<7>>() == 4);
    REQUIRE(solve279<metal::number<12>>() == 3);
    REQUIRE(solve279<metal::number<13>>() == 2);
    REQUIRE(solve279<metal::number<71>>() == 4);
    REQUIRE(solve279<metal::number<100>>() == 1);
    REQUIRE(solve279<metal::number<196>>() == 1);
    REQUIRE(solve279<metal::number<263>>() == 4);
    REQUIRE(solve279<metal::number<313>>() == 2);
    REQUIRE(solve279<metal::number<364>>() == 3);
}
