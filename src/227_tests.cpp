#include <catch.hpp>

#include <227_basic_calculator_ii.hpp>

TEST_CASE("Test cases for problem #227")
{
    REQUIRE(metaleet::solve227<metal::numbers<'3'>>() == 3);
    REQUIRE(metaleet::solve227<metal::numbers<'0'>>() == 0);
    REQUIRE(metaleet::solve227<metal::numbers<'3', '2', '3'>>() == 323);
    REQUIRE(metaleet::solve227<metal::numbers<'1', '1'>>() == 11);
    REQUIRE(metaleet::solve227<metal::numbers<'1', '+', '1'>>() == 2);
    REQUIRE(metaleet::solve227<metal::numbers<'3', '+', '2', '*', '2'>>() == 7);
    REQUIRE(metaleet::solve227<metal::numbers<'3', '/', '2'>>() == 1);
    REQUIRE(metaleet::solve227<metal::numbers<'3', '+', '5', '/', '2'>>() == 5);
    REQUIRE(metaleet::solve227<metal::numbers<'5', '/', '5', '+', '2'>>() == 3);
}
