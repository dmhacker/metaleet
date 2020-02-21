#ifndef METALEET_21_SOLUTION_HPP
#define METALEET_21_SOLUTION_HPP

#include <common/linked_list.hpp>

namespace metaleet {

namespace detail21 {
    template <class head1, class head2>
    struct solve_impl {
        using type = metal::if_<
            metal::less<llnode_data<head1>, llnode_data<head2>>,
            llnode<llnode_data<head1>, typename solve_impl<llnode_next<head1>, head2>::type>,
            llnode<llnode_data<head2>, typename solve_impl<head1, llnode_next<head2>>::type>>;
    };

    template <>
    struct solve_impl<llnode_end, llnode_end> {
        using type = llnode_end;
    };

    template <class head1>
    struct solve_impl<head1, llnode_end> {
        using type = head1;
    };

    template <class head2>
    struct solve_impl<llnode_end, head2> {
        using type = head2;
    };
}

// solve21 :: llnode -> llnode -> llnode

template <class head1, class head2>
using solve21 = typename detail21::solve_impl<head1, head2>::type;

}

#endif
