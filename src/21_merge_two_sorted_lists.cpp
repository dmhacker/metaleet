#include <catch.hpp>
#include <metal.hpp>

#include <vector>

using ONE = metal::number<1>;

template <class d, class n>
struct llnode {
    using data = d;
    using nxt = n;
};

using llnode_end = metal::false_;

template <class n>
using next_llnode = typename n::nxt;

template <class n>
using data_llnode = typename n::data;

template <class nums>
struct _list_to_llist_impl {
    using type = llnode<metal::front<nums>, typename _list_to_llist_impl<metal::drop<nums, ONE>>::type>;
};

template <>
struct _list_to_llist_impl<metal::numbers<>> {
    using type = llnode_end;
};

template <class lst>
using list_to_llist = typename _list_to_llist_impl<lst>::type;

template <class head>
void _llist_to_vector(std::vector<int> & accum) {
    accum.push_back(data_llnode<head>());
    _llist_to_vector<next_llnode<head>>(accum);
}

template <>
void _llist_to_vector<llnode_end>(std::vector<int> & accum) {}

template <class head>
std::vector<int> llist_to_vector() {
    std::vector<int> result; 
    _llist_to_vector<head>(result);
    return result;
}

template <class head1, class head2>
struct _merge_impl {
    using type = metal::if_<
        metal::less<data_llnode<head1>, data_llnode<head2>>, 
        llnode<data_llnode<head1>, typename _merge_impl<next_llnode<head1>, head2>::type>,
        llnode<data_llnode<head2>, typename _merge_impl<head1, next_llnode<head2>>::type> 
    >;
};

template <>
struct _merge_impl<llnode_end, llnode_end> {
    using type = llnode_end;
};

template <class head1>
struct _merge_impl<head1, llnode_end> {
    using type = head1;
};

template <class head2>
struct _merge_impl<llnode_end, head2> {
    using type = head2;
};

template <class head1, class head2>
using merge = typename _merge_impl<head1, head2>::type;

TEST_CASE("Test cases for problem #21")
{
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<1>>, 
            list_to_llist<metal::numbers<1>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<5>>, 
            list_to_llist<metal::numbers<4>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<4>>, 
            list_to_llist<metal::numbers<5>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<4, 5>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<3, 4, 5, 5, 10>>, 
            list_to_llist<metal::numbers<1, 2, 3, 100>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 2, 3, 3, 4, 5, 5, 10, 100>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>, 
            list_to_llist<metal::numbers<>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<1, 1, 1, 1, 1, 1, 1, 1>>>());
    REQUIRE(llist_to_vector<merge<list_to_llist<metal::numbers<123, 1234, 544985, 4589217>>, 
            list_to_llist<metal::numbers<324, 2134, 4321, 341234>>>>() 
            == llist_to_vector<list_to_llist<metal::numbers<123, 324, 1234, 2134, 4321, 341234, 544985, 4589217>>>());
}
