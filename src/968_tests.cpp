#include <catch.hpp>
#include <solutions/968_binary_tree_cameras.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #968")
{
    REQUIRE(solve968<btnode_end>() == 0);
    REQUIRE(solve968<btnode<metal::number<1>, btnode_end, btnode_end>>() == 1);
    REQUIRE(solve968<btnode<metal::number<1>,
                btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode_end>,
                btnode<metal::number<4>, btnode_end, btnode_end>>>()
        == 2);
    /* REQUIRE(solve662<btnode<metal::number<1>, */
    /*             btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode_end>, */
    /*             btnode<metal::number<4>, btnode<metal::number<5>, btnode_end, btnode_end>, btnode_end>>>() */
    /*     == 3); */
    /* REQUIRE(solve662<btnode<metal::number<1>, */
    /*             btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode<metal::number<4>, btnode_end, btnode_end>>, */
    /*             btnode<metal::number<5>, btnode_end, btnode<metal::number<6>, btnode_end, btnode_end>>>>() */
    /*     == 4); */
    /* REQUIRE(solve662<btnode<metal::number<1>, */
    /*             btnode<metal::number<2>, btnode<metal::number<3>, btnode<metal::number<4>, btnode_end, btnode_end>, btnode_end>, btnode_end>, */
    /*             btnode<metal::number<5>, btnode_end, btnode<metal::number<6>, btnode_end, btnode<metal::number<7>, btnode_end, btnode_end>>>>>() */
    /*     == 8); */
}
