#ifndef METALEET_114_SOLUTION_HPP
#define METALEET_114_SOLUTION_HPP

#include <common/binary_tree.hpp>
#include <common/linked_list.hpp>

namespace metaleet {

namespace detail114 {
    template <class root, class tail>
    struct solve_impl {
        using type = llnode<btnode_data<root>,
            typename solve_impl<btnode_left<root>,
                typename solve_impl<btnode_right<root>, tail>::type>::type>;
    };

    template <class tail>
    struct solve_impl<btnode_end, tail> {
        using type = tail;
    };
}

// solve114 :: btnode<a> -> llnode<a>

template <class root>
using solve114 = typename detail114::solve_impl<root, llnode_end>::type;

}

#endif
