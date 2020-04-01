#ifndef METALEET_55_SOLUTION_HPP
#define METALEET_55_SOLUTION_HPP

#include <metaleet/common/linked_list.hpp>

namespace metaleet {

namespace detail55 {
    template <class seq>
    struct _solve {
        // loop :: number -> number -> number

        template <class idx, class old_value>
        struct _loop {
            using type = typename _loop<metal::dec<idx>,
                metal::if_<metal::greater<old_value, metal::add<idx, metal::at<seq, idx>>>, old_value, idx>>::type;
        };

        template <class old_value>
        struct _loop<metal::number<-1>, old_value> {
            using type = old_value;
        };

        using type = metal::not_<typename _loop<metal::dec<metal::dec<metal::size<seq>>>,
              metal::dec<metal::size<seq>>>::type>;
    };

    template <>
    struct _solve<metal::list<>> {
        using type = metal::false_;
    };
}

// solve55 :: list<number> -> bool

template <class seq>
using solve55 = typename detail55::_solve<seq>::type;

}

#endif
