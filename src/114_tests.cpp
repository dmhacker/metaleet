#include <catch.hpp>
#include <solutions/114_flatten_binary_tree_to_linked_list.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #114")
{
    REQUIRE(metal::same<solve114<bnode_end>, llnode_end>());
    REQUIRE(metal::same<solve114<bnode<metal::number<1>, 
            bnode<metal::number<2>, bnode<metal::number<3>, bnode_end, bnode_end>, bnode<metal::number<4>, bnode_end, bnode_end>>, 
            bnode<metal::number<5>, bnode_end, bnode<metal::number<6>, bnode_end, bnode_end>>>>, 
            list_to_llist<metal::numbers<1, 2, 3, 4, 5, 6>>>());
}
