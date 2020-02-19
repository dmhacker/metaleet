#include <catch.hpp>
#include <metal.hpp>
#include <linked_lists.hpp>

// has_minimum_length :: llnode -> number -> bool 

template <class head, class k>
struct _has_minimum_length_impl {
    using type = typename _has_minimum_length_impl<llnode_next<head>, metal::dec<k>>::type;
};

template <>
struct _has_minimum_length_impl<llnode_end, metal::number<0>> {
    using type = metal::true_;
};

template <class head>
struct _has_minimum_length_impl<head, metal::number<0>> {
    using type = metal::true_;
};

template <class k>
struct _has_minimum_length_impl<llnode_end, k> {
    using type = metal::false_;
};

template <class head, class k>
using has_minimum_length = typename _has_minimum_length_impl<head, k>::type;

// kth_node :: llnode -> number -> llnode 

template <class head, class k>
struct _kth_node_impl {
    using type = typename _kth_node_impl<llnode_next<head>, metal::dec<k>>::type;
};

template <>
struct _kth_node_impl<llnode_end, metal::number<0>> {
    using type = llnode_end;
};

template <class head>
struct _kth_node_impl<head, metal::number<0>> {
    using type = head;
};

template <class k>
struct _kth_node_impl<llnode_end, k> {
    using type = llnode_end;
};

template <class head, class k>
using kth_node = typename _kth_node_impl<head, k>::type;

// reverse_to_kth :: llnode -> llnode -> number -> llnode 

template <class accum, class head, class k>
struct _reverse_to_kth_impl {
    using type = typename _reverse_to_kth_impl<llnode<llnode_data<head>, accum>, llnode_next<head>, metal::dec<k>>::type;
};

template <class accum, class head>
struct _reverse_to_kth_impl<accum, head, metal::number<0>> {
    using type = accum;
};

template <class accum, class head, class k>
using reverse_to_kth = typename _reverse_to_kth_impl<accum, head, k>::type;

// solve :: llnode -> number -> llnode

template <class head, class k, 
        class guard = has_minimum_length<head, k>>
struct _solve_impl {
    using type = reverse_to_kth<
        typename _solve_impl<kth_node<head, k>, k, has_minimum_length<kth_node<head, k>, k>>::type,
        head, k>;
};

template <class head, class k>
struct _solve_impl<head, k, metal::false_> {
    using type = head;
};

template <class head, class k>
using solve = typename _solve_impl<head, k>::type;

// BEGIN TEST CASES

TEST_CASE("Test cases for problem #25")
{
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<>>, metal::number<1>>>()
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<>>, metal::number<100>>>()
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 2, 3, 4>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<3>>>()
            == llist_to_vector<list_to_llist<metal::numbers<3, 2, 1, 6, 5, 4>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 2, 3, 4, 5>>, metal::number<3>>>()
            == llist_to_vector<list_to_llist<metal::numbers<3, 2, 1, 4, 5>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 2, 3, 4, 5, 6>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3, 6, 5>>>());
    REQUIRE(llist_to_vector<solve<list_to_llist<metal::numbers<1, 2, 3, 4, 5>>, metal::number<2>>>()
            == llist_to_vector<list_to_llist<metal::numbers<2, 1, 4, 3, 5>>>());
}

// END TEST CASES
