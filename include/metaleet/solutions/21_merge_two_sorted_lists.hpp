#ifndef METALEET_21_SOLUTION_HPP
#define METALEET_21_SOLUTION_HPP

#include <common/linked_list.hpp>

namespace metaleet {

namespace detail21 {
    template <class head1, class head2>
    struct _solve {
        using type = metal::if_<
            metal::less<llnode_data<head1>, llnode_data<head2>>,
            llnode<llnode_data<head1>, typename _solve<llnode_next<head1>, head2>::type>,
            llnode<llnode_data<head2>, typename _solve<head1, llnode_next<head2>>::type>>;
    };

    template <>
    struct _solve<llnode_end, llnode_end> {
        using type = llnode_end;
    };

    template <class head1>
    struct _solve<head1, llnode_end> {
        using type = head1;
    };

    template <class head2>
    struct _solve<llnode_end, head2> {
        using type = head2;
    };
}

// solve21 :: llnode -> llnode -> llnode

template <class head1, class head2>
using solve21 = typename detail21::_solve<head1, head2>::type;

}

#endif
