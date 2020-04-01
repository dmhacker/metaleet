#include <metaleet/solutions/662_maximum_width_of_binary_tree.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #662")
{
    REQUIRE(solve662<btnode_end>() == 0);
    REQUIRE(solve662<btnode<metal::number<1>, btnode_end, btnode_end>>() == 1);
    REQUIRE(solve662<btnode<metal::number<1>,
                btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode_end>,
                btnode<metal::number<4>, btnode_end, btnode_end>>>()
        == 2);
    REQUIRE(solve662<btnode<metal::number<1>,
                btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode_end>,
                btnode<metal::number<4>, btnode<metal::number<5>, btnode_end, btnode_end>, btnode_end>>>()
        == 3);
    REQUIRE(solve662<btnode<metal::number<1>,
                btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode<metal::number<4>, btnode_end, btnode_end>>,
                btnode<metal::number<5>, btnode_end, btnode<metal::number<6>, btnode_end, btnode_end>>>>()
        == 4);
    REQUIRE(solve662<btnode<metal::number<1>,
                btnode<metal::number<2>, btnode<metal::number<3>, btnode<metal::number<4>, btnode_end, btnode_end>, btnode_end>, btnode_end>,
                btnode<metal::number<5>, btnode_end, btnode<metal::number<6>, btnode_end, btnode<metal::number<7>, btnode_end, btnode_end>>>>>()
        == 8);
}
