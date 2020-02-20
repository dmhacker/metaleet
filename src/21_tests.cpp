#include <catch.hpp>
#include <solutions/21_merge_two_sorted_lists.hpp>

TEST_CASE("Test cases for problem #21")
{
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<>>, 
            metaleet::list_to_llist<metal::numbers<>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<1>>, 
            metaleet::list_to_llist<metal::numbers<1>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<1, 1>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<5>>, 
            metaleet::list_to_llist<metal::numbers<4>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<4>>, 
            metaleet::list_to_llist<metal::numbers<5>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<3, 4, 5, 5, 10>>, 
            metaleet::list_to_llist<metal::numbers<1, 2, 3, 100>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<1, 2, 3, 3, 4, 5, 5, 10, 100>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            metaleet::list_to_llist<metal::numbers<>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(metaleet::llist_to_vector<metaleet::solve21<metaleet::list_to_llist<metal::numbers<123, 1234, 544985, 4589217>>, 
            metaleet::list_to_llist<metal::numbers<324, 2134, 4321, 341234>>>>() 
            == metaleet::llist_to_vector<metaleet::list_to_llist<metal::numbers<123, 324, 1234, 2134, 4321, 341234, 544985, 4589217>>>());
}
