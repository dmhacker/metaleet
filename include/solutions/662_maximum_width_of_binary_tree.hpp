#ifndef METALEET_662_SOLUTION_HPP
#define METALEET_662_SOLUTION_HPP

#include <common/binary_tree.hpp>
#include <common/unified.hpp>

namespace metaleet {

namespace detail662 {
    // merge_bounds :: map<number, pair<number, number>> -> number -> number -> map<number, pair<number, number>>

    template <class bounds, class level, class position,
        class guard = metal::has_key<bounds, level>>
    struct merge_bounds_impl {
        using type = metal::insert_key<metal::erase_key<bounds, level>, level,
            metal::pair<metal::min<
                            metal::first<metal::at_key<bounds, level>>,
                            position>,
                metal::max<
                    metal::second<metal::at_key<bounds, level>>,
                    position>>>;
    };

    template <class bounds, class level, class position>
    struct merge_bounds_impl<bounds, level, position, metal::false_> {
        using type = metal::insert_key<bounds, level, metal::pair<position, position>>;
    };

    template <class bounds, class level, class position>
    using merge_bounds = typename merge_bounds_impl<bounds, level, position>::type;

    // get_bounds :: btnode<a> -> map<number, pair<number, number>>

    template <class node, class level, class position, class accum>
    struct get_bounds_impl {
        using type = typename get_bounds_impl<btnode_right<node>,
            metal::inc<level>, metal::inc<metal::mul<position, TWO>>,
            typename get_bounds_impl<btnode_left<node>,
                metal::inc<level>, metal::mul<position, TWO>,
                merge_bounds<accum, level, position>>::type>::type;
    };

    template <class level, class position, class accum>
    struct get_bounds_impl<btnode_end, level, position, accum> {
        using type = accum;
    };

    template <class root>
    using get_bounds = typename get_bounds_impl<root, ZERO, ZERO, metal::map<>>::type;

    // get_difference :: pair<number, number> -> number

    template <class accum, class pair>
    using get_difference = metal::max<accum,
        metal::inc<metal::sub<metal::second<metal::second<pair>>,
            metal::first<metal::second<pair>>>>>;

    // max_difference :: map<number, pair<number, number>> -> number

    template <class positions>
    using max_difference = metal::accumulate<metal::lambda<get_difference>, ZERO, positions>;
}

// solve662 :: btnode<a> -> number

template <class root>
using solve662 = detail662::max_difference<detail662::get_bounds<root>>;

}

#endif
