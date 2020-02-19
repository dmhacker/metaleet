#ifndef METALEET_121_BUY_SELL_STOCK_HPP
#define METALEET_121_BUY_SELL_STOCK_HPP

#include <metal.hpp>

namespace metaleet {

// solve121 :: list<number> -> number

template <class seq>
struct _solve121_impl {

    // loop :: number -> number -> number -> number

    template <class idx, class profit, class minimum>
    struct _loop_impl {
        using type = metal::if_<metal::less<metal::at<seq, idx>, minimum>,
            typename _loop_impl<metal::inc<idx>, profit, metal::at<seq, idx>>::type,
            typename _loop_impl<metal::inc<idx>, metal::max<profit, metal::sub<metal::at<seq, idx>, minimum>>, minimum>::type>;
    };

    template <class profit, class minidx>
    struct _loop_impl<metal::size<seq>, profit, minidx> {
        using type = profit;
    };

    template <class idx, class profit, class minimum>
    using loop = typename _loop_impl<idx, profit, minimum>::type;

    using type = loop<metal::number<1>, metal::number<0>, metal::at<seq, metal::number<0>>>;
};

template <>
struct _solve121_impl<metal::list<>> {
    using type = metal::number<0>;
};

template <class seq>
using solve121 = typename _solve121_impl<seq>::type;

}

#endif
