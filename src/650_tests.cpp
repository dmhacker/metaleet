#include <catch.hpp>
#include <solutions/650_two_keys_keyboard.hpp>

TEST_CASE("Test cases for problem #650")
{
    REQUIRE(metaleet::solve650<metal::number<1>>() == 0);
    REQUIRE(metaleet::solve650<metal::number<3>>() == 3);
    REQUIRE(metaleet::solve650<metal::number<8>>() == 6);
    REQUIRE(metaleet::solve650<metal::number<10>>() == 7);
    REQUIRE(metaleet::solve650<metal::number<50>>() == 12);
    REQUIRE(metaleet::solve650<metal::number<71>>() == 71);
    REQUIRE(metaleet::solve650<metal::number<100>>() == 14);
}
