#include <catch.hpp>

#include <6_zigzag_conversion.hpp>
#include <21_merge_two_sorted_lists.hpp>
#include <25_reverse_nodes_in_k_group.hpp>
#include <55_jump_game.hpp>
#include <69_sqrt.hpp>
#include <121_buy_sell_stock.hpp>
#include <227_basic_calculator_ii.hpp>
#include <279_perfect_squares.hpp>
#include <322_coin_change.hpp>
#include <650_two_keys_keyboard.hpp>

template<char... cs>
constexpr auto operator ""_raw()
    -> metal::numbers<cs...> {
    return {};
}

TEST_CASE("Test cases for problem #6")
{
    REQUIRE(metal::same<metaleet::solve6<metal::numbers<>, metal::number<100>>, 
            metal::numbers<>>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<1>>, 
            decltype(12345_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<2>>, 
            decltype(13524_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<3>>, 
            decltype(15243_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<4>>, 
            decltype(12354_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<5>>, 
            decltype(12345_raw)>()); 
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<6>>, 
            decltype(12345_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(1234567890_raw), metal::number<3>>, 
            decltype(1592468037_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(1234567890_raw), metal::number<4>>, 
            decltype(1726835940_raw)>());
}

TEST_CASE("Test cases for problem #21")
{
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<1>>, 
            list_to_llist<metal::numbers<1>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<5>>, 
            list_to_llist<metal::numbers<4>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<4>>, 
            list_to_llist<metal::numbers<5>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<3, 4, 5, 5, 10>>, 
            list_to_llist<metal::numbers<1, 2, 3, 100>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 2, 3, 3, 4, 5, 5, 10, 100>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(llist_to_vector<metaleet::solve21<list_to_llist<metal::numbers<123, 1234, 544985, 4589217>>, 
            list_to_llist<metal::numbers<324, 2134, 4321, 341234>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<123, 324, 1234, 2134, 4321, 341234, 544985, 4589217>>>());
}

TEST_CASE("Test cases for problem #25")
{
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<>>, metal::number<1>>>()
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<>>, metal::number<100>>>()
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<1, 2, 3, 4>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<3>>>()
            == llist_to_vector<list_to_llist<metal::numbers<3, 2, 1, 6, 5, 4>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<1, 2, 3, 4, 5>>, metal::number<3>>>()
            == llist_to_vector<list_to_llist<metal::numbers<3, 2, 1, 4, 5>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3, 6, 5>>>());
    REQUIRE(llist_to_vector<metaleet::solve25<list_to_llist<metal::numbers<1, 2, 3, 4, 5>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3, 5>>>());
}

TEST_CASE("Test cases for problem #55")
{
    REQUIRE(metaleet::solve55<metal::numbers<2, 3, 1, 1, 4>>() == true);
    REQUIRE(metaleet::solve55<metal::numbers<3, 2, 1, 0, 4>>() == false);
    REQUIRE(metaleet::solve55<metal::numbers<
                1, 2, 2, 6, 3, 6, 1, 8, 9, 4, 7, 6, 5, 6, 8, 2, 6, 1, 3, 6, 6, 6, 3, 2, 4, 9, 4, 5,
                9, 8, 2, 2, 1, 6, 1, 6, 2, 2, 6, 1, 8, 6, 8, 3, 2, 8, 5, 8, 0, 1, 4, 8, 7, 9, 0, 3,
                9, 4, 8, 0, 2, 2, 5, 5, 8, 6, 3, 1, 0, 2, 4, 9, 8, 4, 4, 2, 3, 2, 2, 5, 5, 9, 3, 2,
                8, 5, 8, 9, 1, 6, 2, 5, 9, 9, 3, 9, 7, 6, 0, 7, 8, 7, 8, 8, 3, 5, 0>>()
        == true);
    REQUIRE(metaleet::solve55<metal::numbers<
                2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1,
                2, 2, 6, 4, 2, 4, 3, 0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4,
                6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9, 8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1,
                9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6>>()
        == false);
}

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

TEST_CASE("Test cases for problem #121")
{
    REQUIRE(metaleet::solve121<metal::numbers<7, 1, 5, 3, 6, 4>>() == 5);
    REQUIRE(metaleet::solve121<metal::numbers<7, 6, 4, 3, 1>>() == 0);
    REQUIRE(metaleet::solve121<metal::numbers<1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9>>() == 9);
    REQUIRE(metaleet::solve121<metal::numbers<9, 8, 7, 6, 5, 4, 4, 3, 2, 2, 1>>() == 0);
    REQUIRE(metaleet::solve121<metal::numbers<397, 6621, 4997, 7506, 8918, 1662, 540, 2275,
                8758, 7434, 3750, 6101, 1359, 4268, 5815, 2771, 126, 478, 9253,
                9486, 446, 985, 1492, 1646, 3756, 7970, 8476, 3009, 7457, 8922,
                2980, 577, 2342, 4069, 8341, 4400, 2923, 2730, 2917, 105>>()
        == 9360);
}

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

TEST_CASE("Test cases for problem #279")
{
    REQUIRE(metaleet::solve279<metal::number<7>>() == 4);
    REQUIRE(metaleet::solve279<metal::number<12>>() == 3);
    REQUIRE(metaleet::solve279<metal::number<13>>() == 2);
    REQUIRE(metaleet::solve279<metal::number<71>>() == 4);
    REQUIRE(metaleet::solve279<metal::number<100>>() == 1);
    REQUIRE(metaleet::solve279<metal::number<196>>() == 1);
    REQUIRE(metaleet::solve279<metal::number<263>>() == 4);
    REQUIRE(metaleet::solve279<metal::number<313>>() == 2);
    REQUIRE(metaleet::solve279<metal::number<364>>() == 3);
}

TEST_CASE("Test cases for problem #322")
{
    REQUIRE(metaleet::solve322<metal::numbers<1, 2, 5>, metal::number<11>>() == 3);
    REQUIRE(metaleet::solve322<metal::numbers<2>, metal::number<3>>() == -1);
    REQUIRE(metaleet::solve322<metal::numbers<474, 83, 404, 3>, metal::number<264>>() == 8);
    REQUIRE(metaleet::solve322<metal::numbers<384, 324, 196, 481>, metal::number<285>>() == -1);
}

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
