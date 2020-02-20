#ifndef METALEET_BINARY_TREE_HPP
#define METALEET_BINARY_TREE_HPP

#include <metal.hpp>

namespace metaleet {

template <class d, class l, class r>
struct bnode {
    using data = d;
    using left = l;
    using right = r;
};

using bnode_end = metal::false_;

template <class n>
using bnode_left = typename n::left;

template <class n>
using bnode_right = typename n::right;

template <class n>
using bnode_data = typename n::data;

}

#endif
