#include <catch.hpp>
#include <solutions/25_reverse_nodes_in_k_group.hpp>

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
