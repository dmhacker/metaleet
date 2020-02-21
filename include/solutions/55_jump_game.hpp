#ifndef METALEET_55_SOLUTION_HPP
#define METALEET_55_SOLUTION_HPP

#include <common/linked_list.hpp>

namespace metaleet {

namespace detail55 {
    template <class seq>
    struct solve_impl {
        // loop :: number -> number -> number

        template <class idx, class old_value>
        struct loop_impl {
            using type = typename loop_impl<metal::dec<idx>,
                metal::if_<metal::greater<old_value, metal::add<idx, metal::at<seq, idx>>>, old_value, idx>>::type;
        };

        template <class old_value>
        struct loop_impl<metal::number<-1>, old_value> {
            using type = old_value;
        };

        using type = metal::not_<typename loop_impl<metal::dec<metal::dec<metal::size<seq>>>,
              metal::dec<metal::size<seq>>>::type>;
    };

    template <>
    struct solve_impl<metal::list<>> {
        using type = metal::false_;
    };
}

// solve55 :: list<number> -> bool

template <class seq>
using solve55 = typename detail55::solve_impl<seq>::type;

}

#endif
