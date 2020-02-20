#ifndef METALEET_6_SOLUTION_HPP
#define METALEET_6_SOLUTION_HPP

#include <api/common.hpp>

namespace metaleet {

// append_at :: list<list<X>> -> number -> X -> list<list<X>>

template <class rows, class ridx, class val>
using append_at = metal::insert<metal::erase<rows, ridx, metal::inc<ridx>>, ridx, metal::append<metal::at<rows, ridx>, val>>;

// fill_rows :: list<char> -> list<list<char>> -> list<list<char>>

template <class seq, class rows, class sidx, class ridx, class down,
    class done = metal::same<metal::size<seq>, sidx>>
struct _fill_rows_impl {
    using type = typename _fill_rows_impl<seq, append_at<rows, ridx, metal::at<seq, sidx>>,
        metal::inc<sidx>,
        metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>,
        metal::if_<metal::or_<
                       metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, ZERO>,
                       metal::same<metal::if_<down, metal::inc<ridx>, metal::dec<ridx>>, metal::dec<metal::size<rows>>>>,
            metal::not_<down>, down>>::type;
};

template <class seq, class rows, class sidx, class ridx, class down>
struct _fill_rows_impl<seq, rows, sidx, ridx, down, metal::true_> {
    using type = rows;
};

template <class seq, class rows>
using fill_rows = typename _fill_rows_impl<seq, rows, ZERO, ZERO, metal::true_>::type;

// solve6 :: list<char> -> number

template <class seq, class num_rows>
struct _solve6_impl {
    using type = metal::flatten<fill_rows<seq, metal::repeat<metal::list<>, num_rows>>>;
};

template <class seq>
struct _solve6_impl<seq, ONE> {
    using type = seq;
};

template <class seq, class num_rows>
using solve6 = typename _solve6_impl<seq, num_rows>::type;

}

#endif
