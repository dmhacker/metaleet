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
using llnode_next = typename n::nxt;

template <class n>
using llnode_data = typename n::data;

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

template <class head, class accum>
struct _llist_length_impl {
    using type = typename _llist_length_impl<llnode_next<head>, metal::inc<accum>>::type;
};

template <class accum>
struct _llist_length_impl<llnode_end, accum> {
    using type = accum; 
};

template <class head>
using llist_length = _llist_length_impl<head, metal::number<0>>;

template <class head>
inline void _llist_to_vector(std::vector<int> & accum) {
    accum.push_back(llnode_data<head>());
    _llist_to_vector<llnode_next<head>>(accum);
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
