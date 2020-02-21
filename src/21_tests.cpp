#include <catch.hpp>
#include <solutions/21_merge_two_sorted_lists.hpp>

using namespace metaleet;

TEST_CASE("Test cases for problem #21")
{
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<>>, 
            list_to_llnode<metal::numbers<>>>, list_to_llnode<metal::numbers<>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<1>>, 
            list_to_llnode<metal::numbers<1>>>, list_to_llnode<metal::numbers<1, 1>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<5>>, 
            list_to_llnode<metal::numbers<4>>>, list_to_llnode<metal::numbers<4, 5>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<4>>, 
            list_to_llnode<metal::numbers<5>>>, list_to_llnode<metal::numbers<4, 5>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<3, 4, 5, 5, 10>>, 
            list_to_llnode<metal::numbers<1, 2, 3, 100>>>, list_to_llnode<metal::numbers<1, 2, 3, 3, 4, 5, 5, 10, 100>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            list_to_llnode<metal::numbers<>>>, list_to_llnode<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            list_to_llnode<metal::numbers<>>>, list_to_llnode<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(metal::same<solve21<list_to_llnode<metal::numbers<123, 1234, 544985, 4589217>>, 
            list_to_llnode<metal::numbers<324, 2134, 4321, 341234>>>, list_to_llnode<metal::numbers<123, 324, 1234, 2134, 4321, 341234, 544985, 4589217>>>());
}
