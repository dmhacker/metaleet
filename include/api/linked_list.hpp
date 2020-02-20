#ifndef METALEET_LINKED_LIST_HPP
#define METALEET_LINKED_LIST_HPP

#include <metal.hpp>
#include <vector>

namespace metaleet {

// A llnode stands for 'linked list node' and allows for
// the construction of a singly linked list.
//
// Any given node stores both its data and the next node
// in the linked list. Accessing both these fields can be
// done using llnode_next and llnode_data.

template <class d, class n>
struct llnode {
    using data = d;
    using nxt = n;
};

// The llnode_end signifies the end of a null linked list.
// If a llnode points to llnode_end as its next pointer,
// then that llnode is a tail node.

using llnode_end = metal::false_;

// llnode_next :: llnode<a> -> llnode<a>

template <class n>
using llnode_next = typename n::nxt;

// llnode_data :: llnode<a> -> a

template <class n>
using llnode_data = typename n::data;

// list_to_llist :: list<a> -> llnode<a>
// Converts a metal::list into a its equivalent linked list representation.

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

// llist_length :: llnode<a> -> number
// Given a top-level linked list node, returns the number of nodes attached it to it.

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

}

#endif
