#include <metaleet/solutions/650_two_keys_keyboard.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #650")
{
    REQUIRE(solve650<metal::number<1>>() == 0);
    REQUIRE(solve650<metal::number<3>>() == 3);
    REQUIRE(solve650<metal::number<8>>() == 6);
    REQUIRE(solve650<metal::number<10>>() == 7);
    REQUIRE(solve650<metal::number<50>>() == 12);
    REQUIRE(solve650<metal::number<71>>() == 71);
    REQUIRE(solve650<metal::number<100>>() == 14);
}
