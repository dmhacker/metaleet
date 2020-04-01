#ifndef METALEET_968_SOLUTION_HPP
#define METALEET_968_SOLUTION_HPP

#include <metaleet/common/binary_tree.hpp>
#include <metaleet/common/unified.hpp>

namespace metaleet {

namespace detail968 {
    // covering :: btnode<a> -> bool -> number

    template <class node, class covered>
    struct _covering {
    };

    template <class node, class covered>
    using covering = typename _covering<node, covered>::type;

    template <>
    struct _covering<btnode_end, metal::false_> {
        using type = ZERO;
    };

    template <>
    struct _covering<btnode_end, metal::true_> {
        using type = ZERO;
    };

    template <class node>
    struct _covering<node, metal::true_> {
        using type = metal::min<
            metal::inc<metal::add<
                covering<btnode_left<node>, metal::true_>,
                covering<btnode_right<node>, metal::true_>>>,
            metal::add<
                covering<btnode_left<node>, metal::false_>,
                covering<btnode_right<node>, metal::false_>>>;
    };

    template <class node>
    struct _covering<node, metal::false_> {
        // left :: number -> number

        template <class accum, class guard = metal::same<btnode_left<node>, btnode_end>>
        struct _left {
            using type = metal::min<accum,
                metal::inc<metal::add<
                    covering<btnode_left<btnode_left<node>>, metal::true_>,
                    covering<btnode_right<btnode_left<node>>, metal::true_>,
                    covering<btnode_right<node>, metal::false_>>>>;
        };

        template <class accum>
        struct _left<accum, metal::true_> {
            using type = accum;
        };

        template <class accum>
        using left = typename _left<accum>::type;

        // right :: number -> number
        
        template <class accum, class guard = metal::same<btnode_right<node>, btnode_end>>
        struct _right {
            using type = metal::min<accum,
                metal::inc<metal::add<
                    covering<btnode_left<btnode_right<node>>, metal::true_>,
                    covering<btnode_right<btnode_right<node>>, metal::true_>,
                    covering<btnode_left<node>, metal::false_>>>>;
        };

        template <class accum>
        struct _right<accum, metal::true_> {
            using type = accum;
        };

        template <class accum>
        using right = typename _right<accum>::type;

        using type = right<left<metal::inc<metal::add<
            covering<btnode_left<node>, metal::true_>,
            covering<btnode_right<node>, metal::true_>>>>>;
    };
}

// solve968 :: btnode<a> -> number

template <class root>
using solve968 = detail968::covering<root, metal::false_>;

}

#endif
