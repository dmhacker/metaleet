#ifndef METALEET_968_SOLUTION_HPP
#define METALEET_968_SOLUTION_HPP

#include <common/binary_tree.hpp>
#include <common/unified.hpp>

namespace metaleet {

namespace detail968 {
    // covering :: btnode<a> -> bool -> number

    template <class node, class covered>
    struct covering_impl {
    };

    template <class node, class covered>
    using covering = typename covering_impl<node, covered>::type;

    template <>
    struct covering_impl<btnode_end, metal::false_> {
        using type = ZERO;
    };

    template <>
    struct covering_impl<btnode_end, metal::true_> {
        using type = ZERO;
    };

    template <class node>
    struct covering_impl<node, metal::true_> {
        using type = metal::min<
            metal::inc<metal::add<
                covering<btnode_left<node>, metal::true_>,
                covering<btnode_right<node>, metal::true_>>>,
            metal::add<
                covering<btnode_left<node>, metal::false_>,
                covering<btnode_right<node>, metal::false_>>>;
    };

    template <class node>
    struct covering_impl<node, metal::false_> {
        // left :: number -> number

        template <class accum, class guard = metal::same<btnode_left<node>, btnode_end>>
        struct left_impl {
            using type = metal::min<accum,
                metal::inc<metal::add<
                    covering<btnode_left<btnode_left<node>>, metal::true_>,
                    covering<btnode_right<btnode_left<node>>, metal::true_>,
                    covering<btnode_right<node>, metal::false_>>>>;
        };

        template <class accum>
        struct left_impl<accum, metal::true_> {
            using type = accum;
        };

        template <class accum>
        using left = typename left_impl<accum>::type;

        // right :: number -> number
        
        template <class accum, class guard = metal::same<btnode_right<node>, btnode_end>>
        struct right_impl {
            using type = metal::min<accum,
                metal::inc<metal::add<
                    covering<btnode_left<btnode_right<node>>, metal::true_>,
                    covering<btnode_right<btnode_right<node>>, metal::true_>,
                    covering<btnode_left<node>, metal::false_>>>>;
        };

        template <class accum>
        struct right_impl<accum, metal::true_> {
            using type = accum;
        };

        template <class accum>
        using right = typename right_impl<accum>::type;

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
