#include <metaleet/solutions/121_buy_sell_stock.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #121")
{
    REQUIRE(solve121<metal::numbers<7, 1, 5, 3, 6, 4>>() == 5);
    REQUIRE(solve121<metal::numbers<7, 6, 4, 3, 1>>() == 0);
    REQUIRE(solve121<metal::numbers<1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9>>() == 9);
    REQUIRE(solve121<metal::numbers<9, 8, 7, 6, 5, 4, 4, 3, 2, 2, 1>>() == 0);
    REQUIRE(solve121<metal::numbers<397, 6621, 4997, 7506, 8918, 1662, 540, 2275,
                8758, 7434, 3750, 6101, 1359, 4268, 5815, 2771, 126, 478, 9253,
                9486, 446, 985, 1492, 1646, 3756, 7970, 8476, 3009, 7457, 8922,
                2980, 577, 2342, 4069, 8341, 4400, 2923, 2730, 2917, 105>>()
        == 9360);
}
