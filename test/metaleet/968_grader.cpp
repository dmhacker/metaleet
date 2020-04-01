#include <metaleet/solutions/968_binary_tree_cameras.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #968")
{
    REQUIRE(solve968<btnode_end>() == 0);
    REQUIRE(solve968<btnode<ZERO, btnode_end, btnode_end>>() == 1);
    REQUIRE(solve968<btnode<ZERO,
                btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode_end>,
                btnode<ZERO, btnode_end, btnode_end>>>()
        == 2);
    REQUIRE(solve968<btnode<ZERO,
                btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode_end>,
                btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode_end>>>()
        == 2);
    REQUIRE(solve968<btnode<ZERO,
                btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode<ZERO, btnode_end, btnode_end>>,
                btnode<ZERO, btnode_end, btnode<ZERO, btnode_end, btnode_end>>>>()
        == 2);
    REQUIRE(solve968<btnode<ZERO, btnode_end,
                btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>,
                    btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode<ZERO, btnode_end, btnode_end>>>>>()
        == 2);
    REQUIRE(solve968<btnode<ZERO,
                btnode<ZERO, btnode<ZERO, btnode<ZERO, btnode_end, btnode_end>, btnode_end>, btnode_end>,
                btnode<ZERO, btnode_end, btnode<ZERO, btnode_end, btnode<ZERO, btnode_end, btnode_end>>>>>()
        == 3);
    REQUIRE(solve968<btnode<ZERO, btnode_end,
                btnode<ZERO, btnode_end,
                    btnode<ZERO, btnode_end,
                        btnode<ZERO, btnode_end,
                            btnode<ZERO, btnode_end,
                                btnode<ZERO, btnode_end, btnode_end>>>>>>>()
        == 2);
    REQUIRE(solve968<btnode<ZERO, btnode_end,
                btnode<ZERO, btnode_end,
                    btnode<ZERO, btnode_end,
                        btnode<ZERO, btnode_end,
                            btnode<ZERO, btnode_end,
                                btnode<ZERO, btnode_end,
                                    btnode<ZERO, btnode_end, btnode_end>>>>>>>>()
        == 3);
}
