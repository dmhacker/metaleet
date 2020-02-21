#ifndef METALEET_121_SOLUTION_HPP
#define METALEET_121_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail121 {
    template <class seq>
    struct solve_impl {

        // loop :: number -> number -> number -> number

        template <class idx, class profit, class minimum>
        struct loop_impl {
            using type = metal::if_<metal::less<metal::at<seq, idx>, minimum>,
                typename loop_impl<metal::inc<idx>, profit, metal::at<seq, idx>>::type,
                typename loop_impl<metal::inc<idx>, metal::max<profit, metal::sub<metal::at<seq, idx>, minimum>>, minimum>::type>;
        };

        template <class profit, class minidx>
        struct loop_impl<metal::size<seq>, profit, minidx> {
            using type = profit;
        };

        using type = typename loop_impl<ONE, ZERO, metal::at<seq, ZERO>>::type;
    };

    template <>
    struct solve_impl<metal::list<>> {
        using type = ZERO;
    };
}

// solve121 :: list<number> -> number

template <class seq>
using solve121 = typename detail121::solve_impl<seq>::type;

}

#endif
