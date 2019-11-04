#include <catch.hpp>
#include <linked_lists.hpp>

template <class head1, class head2>
struct _solve_impl {
    using type = metal::if_<
        metal::less<data_llnode<head1>, data_llnode<head2>>, 
        llnode<data_llnode<head1>, typename _solve_impl<next_llnode<head1>, head2>::type>,
        llnode<data_llnode<head2>, typename _solve_impl<head1, next_llnode<head2>>::type> 
    >;
};

template <>
struct _solve_impl<llnode_end, llnode_end> {
    using type = llnode_end;
};

template <class head1>
struct _solve_impl<head1, llnode_end> {
    using type = head1;
};

template <class head2>
struct _solve_impl<llnode_end, head2> {
    using type = head2;
};

template <class head1, class head2>
using solve = typename _solve_impl<head1, head2>::type;

TEST_CASE("Test cases for problem #21")
{
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1>>, 
            list_to_llist<metal::numbers<1>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<5>>, 
            list_to_llist<metal::numbers<4>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<4>>, 
            list_to_llist<metal::numbers<5>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<3, 4, 5, 5, 10>>, 
            list_to_llist<metal::numbers<1, 2, 3, 100>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 2, 3, 3, 4, 5, 5, 10, 100>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<123, 1234, 544985, 4589217>>, 
            list_to_llist<metal::numbers<324, 2134, 4321, 341234>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<123, 324, 1234, 2134, 4321, 341234, 544985, 4589217>>>());
}
