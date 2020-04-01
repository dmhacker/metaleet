#include <metaleet/solutions/227_basic_calculator_ii.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #227")
{
    REQUIRE(solve227<metal::numbers<'3'>>() == 3);
    REQUIRE(solve227<metal::numbers<'0'>>() == 0);
    REQUIRE(solve227<metal::numbers<'3', '2', '3'>>() == 323);
    REQUIRE(solve227<metal::numbers<'1', '1'>>() == 11);
    REQUIRE(solve227<metal::numbers<'1', '+', '1'>>() == 2);
    REQUIRE(solve227<metal::numbers<'3', '+', '2', '*', '2'>>() == 7);
    REQUIRE(solve227<metal::numbers<'3', '/', '2'>>() == 1);
    REQUIRE(solve227<metal::numbers<'3', '+', '5', '/', '2'>>() == 5);
    REQUIRE(solve227<metal::numbers<'5', '/', '5', '+', '2'>>() == 3);
}
