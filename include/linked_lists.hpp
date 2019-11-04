#ifndef METALEET_LINKED_LISTS_HPP
#define METALEET_LINKED_LISTS_HPP

#include <metal.hpp>
#include <vector>

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
    using type = llnode<metal::front<nums>, typename _list_to_llist_impl<metal::drop<nums, metal::number<1>>>::type>;
};

template <>
struct _list_to_llist_impl<metal::numbers<>> {
    using type = llnode_end;
};

template <class lst>
using list_to_llist = typename _list_to_llist_impl<lst>::type;

template <class head>
inline void _llist_to_vector(std::vector<int> & accum) {
    accum.push_back(data_llnode<head>());
    _llist_to_vector<next_llnode<head>>(accum);
}

template <>
inline void _llist_to_vector<llnode_end>(std::vector<int> & accum) {}

template <class head>
inline std::vector<int> llist_to_vector() {
    std::vector<int> result; 
    _llist_to_vector<head>(result);
    return result;
}

#endif
