#ifndef METALEET_114_SOLUTION_HPP
#define METALEET_114_SOLUTION_HPP

#include <api/binary_tree.hpp>
#include <api/linked_list.hpp>

namespace metaleet {

// solve114 :: bnode -> llnode

template <class root, class tail>
struct _solve114_impl {
   using type = llnode<bnode_data<root>, typename _solve114_impl<bnode_left<root>, typename _solve114_impl<bnode_right<root>, tail>::type>::type>;
};

template <class tail>
struct _solve114_impl<bnode_end, tail> {
    using type = tail; 
};

template <class root>
using solve114 = typename _solve114_impl<root, llnode_end>::type;

}

#endif
