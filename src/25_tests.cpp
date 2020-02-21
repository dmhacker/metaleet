#include <catch.hpp>
#include <solutions/25_reverse_nodes_in_k_group.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #25")
{
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<>>, metal::number<1>>, 
            list_to_llnode<metal::numbers<>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<>>, metal::number<100>>, 
            list_to_llnode<metal::numbers<>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<1, 2, 3, 4>>, metal::number<2>>, 
            list_to_llnode<metal::numbers<2, 1, 4, 3>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<3>>, 
            list_to_llnode<metal::numbers<3, 2, 1, 6, 5, 4>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<1, 2, 3, 4, 5>>, metal::number<3>>, 
            list_to_llnode<metal::numbers<3, 2, 1, 4, 5>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<2>>, 
            list_to_llnode<metal::numbers<2, 1, 4, 3, 6, 5>>>());
    REQUIRE(metal::same<solve25<list_to_llnode<metal::numbers<1, 2, 3, 4, 5>>, metal::number<2>>, 
            list_to_llnode<metal::numbers<2, 1, 4, 3, 5>>>());
}
