#ifndef METALEET_25_SOLUTION_HPP
#define METALEET_25_SOLUTION_HPP

#include <common/linked_list.hpp>
#include <common/unified.hpp>

namespace metaleet {

namespace detail25 {
    // has_minimum_length :: llnode -> number -> bool

    template <class head, class k>
    struct has_minimum_length_impl {
        using type = typename has_minimum_length_impl<llnode_next<head>, metal::dec<k>>::type;
    };

    template <>
    struct has_minimum_length_impl<llnode_end, ZERO> {
        using type = metal::true_;
    };

    template <class head>
    struct has_minimum_length_impl<head, ZERO> {
        using type = metal::true_;
    };

    template <class k>
    struct has_minimum_length_impl<llnode_end, k> {
        using type = metal::false_;
    };

    template <class head, class k>
    using has_minimum_length = typename has_minimum_length_impl<head, k>::type;

    // kth_node :: llnode -> number -> llnode

    template <class head, class k>
    struct kth_node_impl {
        using type = typename kth_node_impl<llnode_next<head>, metal::dec<k>>::type;
    };

    template <>
    struct kth_node_impl<llnode_end, ZERO> {
        using type = llnode_end;
    };

    template <class head>
    struct kth_node_impl<head, ZERO> {
        using type = head;
    };

    template <class k>
    struct kth_node_impl<llnode_end, k> {
        using type = llnode_end;
    };

    template <class head, class k>
    using kth_node = typename kth_node_impl<head, k>::type;

    // reverse_to_kth :: llnode -> llnode -> number -> llnode

    template <class accum, class head, class k>
    struct reverse_to_kth_impl {
        using type = typename reverse_to_kth_impl<llnode<llnode_data<head>, accum>, llnode_next<head>, metal::dec<k>>::type;
    };

    template <class accum, class head>
    struct reverse_to_kth_impl<accum, head, ZERO> {
        using type = accum;
    };

    template <class accum, class head, class k>
    using reverse_to_kth = typename reverse_to_kth_impl<accum, head, k>::type;

    template <class head, class k,
        class guard = has_minimum_length<head, k>>
    struct solve_impl {
        using type = reverse_to_kth<
            typename solve_impl<kth_node<head, k>, k, has_minimum_length<kth_node<head, k>, k>>::type,
            head, k>;
    };

    template <class head, class k>
    struct solve_impl<head, k, metal::false_> {
        using type = head;
    };
}

// solve25 :: llnode -> number -> llnode

template <class head, class k>
using solve25 = typename detail25::solve_impl<head, k>::type;

}

#endif
