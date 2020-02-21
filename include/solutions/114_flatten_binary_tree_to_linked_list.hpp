#ifndef METALEET_114_SOLUTION_HPP
#define METALEET_114_SOLUTION_HPP

#include <common/binary_tree.hpp>
#include <common/linked_list.hpp>

namespace metaleet {

// solve114 :: btnode -> llnode

template <class root, class tail>
struct _solve114_impl {
   using type = llnode<btnode_data<root>, 
         typename _solve114_impl<btnode_left<root>, 
         typename _solve114_impl<btnode_right<root>, tail>::type>::type>;
};

template <class tail>
struct _solve114_impl<btnode_end, tail> {
    using type = tail; 
};

template <class root>
using solve114 = typename _solve114_impl<root, llnode_end>::type;

}

#endif
