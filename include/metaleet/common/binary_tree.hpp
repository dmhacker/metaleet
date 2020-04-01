#ifndef METALEET_BINARY_TREE_HPP
#define METALEET_BINARY_TREE_HPP

#include <metal.hpp>

namespace metaleet {

// A btnode stands for 'binary tree node' and supports the 
// construction of a binary tree.
//
// A btnode essentially stores its data and its left and right
// child nodes. It is similar to llnode, only that it stores two
// child nodes rather than btnode. In fact, a btnode can be converted
// to an llnode by assuming that one of the nodes is always equal to
// btnode_end.

template <class d, class l, class r>
struct btnode {
    using data = d;
    using left = l;
    using right = r;
};

// The btnode_end signifies the end of a binary tree.
// A btnode that has two btnode_end's as its children is considered
// to be a leaf in the binary tree.

using btnode_end = metal::false_;

// btnode_left :: btnode<a> -> btnode<a>

template <class n>
using btnode_left = typename n::left;

// btnode_right :: btnode<a> -> btnode<a>

template <class n>
using btnode_right = typename n::right;

// btnode_data :: btnode<a> -> a

template <class n>
using btnode_data = typename n::data;

}

#endif
