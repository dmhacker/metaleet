#ifndef METALEET_121_SOLUTION_HPP
#define METALEET_121_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail121 {
    template <class seq>
    struct _solve {

        // loop :: number -> number -> number -> number

        template <class idx, class profit, class minimum>
        struct _loop {
            using type = metal::if_<metal::less<metal::at<seq, idx>, minimum>,
                typename _loop<metal::inc<idx>, profit, metal::at<seq, idx>>::type,
                typename _loop<metal::inc<idx>, metal::max<profit, metal::sub<metal::at<seq, idx>, minimum>>, minimum>::type>;
        };

        template <class profit, class minidx>
        struct _loop<metal::size<seq>, profit, minidx> {
            using type = profit;
        };

        using type = typename _loop<ONE, ZERO, metal::at<seq, ZERO>>::type;
    };

    template <>
    struct _solve<metal::list<>> {
        using type = ZERO;
    };
}

// solve121 :: list<number> -> number

template <class seq>
using solve121 = typename detail121::_solve<seq>::type;

}

#endif
