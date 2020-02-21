#ifndef METALEET_6_SOLUTION_HPP
#define METALEET_6_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail6 {
    // fill_rows :: list<char> -> list<list<char>> -> list<list<char>>

    template <class seq, class rows, class sidx, class ridx, class down,
        class done = metal::same<metal::size<seq>, sidx>>
    struct fill_rows_impl {
        using type = typename fill_rows_impl<seq, append_at<rows, ridx, metal::at<seq, sidx>>,
            metal::inc<sidx>,
            metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>,
            metal::if_<metal::or_<
                           metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, ZERO>,
                           metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, metal::dec<metal::size<rows>>>>,
                metal::not_<down>, down>>::type;
    };

    template <class seq, class rows, class sidx, class ridx, class down>
    struct fill_rows_impl<seq, rows, sidx, ridx, down, metal::true_> {
        using type = rows;
    };

    template <class seq, class rows>
    using fill_rows = typename fill_rows_impl<seq, rows, ZERO, ZERO, metal::true_>::type;

    template <class seq, class num_rows>
    struct solve_impl {
        using type = metal::flatten<fill_rows<seq, metal::repeat<metal::list<>, num_rows>>>;
    };

    template <class seq>
    struct solve_impl<seq, ONE> {
        using type = seq;
    };
}

// solve6 :: list<char> -> number

template <class seq, class num_rows>
using solve6 = typename detail6::solve_impl<seq, num_rows>::type;

}

#endif
