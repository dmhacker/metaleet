#ifndef METALEET_21_MERGE_TWO_SORTED_LISTS_HPP
#define METALEET_21_MERGE_TWO_SORTED_LISTS_HPP

#include <linked_lists.hpp>

namespace metaleet {

// solve21 :: llnode -> llnode -> llnode

template <class head1, class head2>
struct _solve21_impl {
    using type = metal::if_<
        metal::less<llnode_data<head1>, llnode_data<head2>>, 
        llnode<llnode_data<head1>, typename _solve21_impl<llnode_next<head1>, head2>::type>,
        llnode<llnode_data<head2>, typename _solve21_impl<head1, llnode_next<head2>>::type> 
    >;
};

template <>
struct _solve21_impl<llnode_end, llnode_end> {
    using type = llnode_end;
};

template <class head1>
struct _solve21_impl<head1, llnode_end> {
    using type = head1;
};

template <class head2>
struct _solve21_impl<llnode_end, head2> {
    using type = head2;
};

template <class head1, class head2>
using solve21 = typename _solve21_impl<head1, head2>::type;

}

#endif
