#include <catch.hpp>

#include <21_merge_two_sorted_lists.hpp>

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
