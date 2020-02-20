#include <catch.hpp>
#include <solutions/322_coin_change.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #322")
{
    REQUIRE(solve322<metal::numbers<1, 2, 5>, metal::number<11>>() == 3);
    REQUIRE(solve322<metal::numbers<2>, metal::number<3>>() == -1);
    REQUIRE(solve322<metal::numbers<474, 83, 404, 3>, metal::number<264>>() == 8);
    REQUIRE(solve322<metal::numbers<384, 324, 196, 481>, metal::number<285>>() == -1);
}
