#ifndef METALEET_114_SOLUTION_HPP
#define METALEET_114_SOLUTION_HPP

#include <metaleet/common/binary_tree.hpp>
#include <metaleet/common/linked_list.hpp>

namespace metaleet {

namespace detail114 {
    template <class root, class tail>
    struct _solve {
        using type = llnode<btnode_data<root>,
            typename _solve<btnode_left<root>,
                typename _solve<btnode_right<root>, tail>::type>::type>;
    };

    template <class tail>
    struct _solve<btnode_end, tail> {
        using type = tail;
    };
}

// solve114 :: btnode<a> -> llnode<a>

template <class root>
using solve114 = typename detail114::_solve<root, llnode_end>::type;

}

#endif
