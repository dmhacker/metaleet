#include <metaleet/solutions/114_flatten_binary_tree_to_linked_list.hpp>

#include <catch.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #114")
{
    REQUIRE(metal::same<solve114<btnode_end>, llnode_end>());
    REQUIRE(metal::same<solve114<btnode<metal::number<1>, btnode_end, btnode_end>>, 
            llnode<metal::number<1>, llnode_end>>());
    REQUIRE(metal::same<solve114<btnode<metal::number<1>, 
            btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode_end>, 
            btnode<metal::number<4>, btnode_end, btnode_end>>>, 
            list_to_llnode<metal::numbers<1, 2, 3, 4>>>());
    REQUIRE(metal::same<solve114<btnode<metal::number<1>, 
            btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode<metal::number<4>, btnode_end, btnode_end>>, 
            btnode<metal::number<5>, btnode_end, btnode<metal::number<6>, btnode_end, btnode_end>>>>, 
            list_to_llnode<metal::numbers<1, 2, 3, 4, 5, 6>>>());
    REQUIRE(metal::same<solve114<btnode<metal::number<1>, 
            btnode<metal::number<2>, btnode<metal::number<3>, btnode_end, btnode_end>, btnode<metal::number<4>, btnode_end, btnode_end>>, 
            btnode<metal::number<5>, btnode<metal::number<6>, btnode_end, btnode_end>, btnode<metal::number<7>, btnode_end, btnode_end>>>>, 
            list_to_llnode<metal::numbers<1, 2, 3, 4, 5, 6, 7>>>());
}
