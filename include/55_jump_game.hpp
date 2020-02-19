#ifndef METALEET_55_JUMP_GAME_HPP
#define METALEET_55_JUMP_GAME_HPP

#include <metal.hpp>

namespace metaleet {

// solve55 :: list<number> -> bool

template <class seq>
struct _solve55_impl {

    // loop :: number -> number -> number 
    
    template <class idx, class old_value>
    struct _loop_impl {
        using type = typename _loop_impl<metal::dec<idx>,
            metal::if_<metal::greater<old_value, metal::add<idx, metal::at<seq, idx>>>, old_value, idx>>::type;
    };

    template <class old_value>
    struct _loop_impl<metal::number<-1>, old_value> {
        using type = old_value;
    };

    template <class idx, class old_value>
    using loop = typename _loop_impl<idx, old_value>::type;

    using type = metal::not_<loop<metal::dec<metal::dec<metal::size<seq>>>, metal::dec<metal::size<seq>>>>;
};

template <>
struct _solve55_impl<metal::list<>> {
    using type = metal::false_;
};

template <class seq>
using solve55 = typename _solve55_impl<seq>::type;

}

#endif
