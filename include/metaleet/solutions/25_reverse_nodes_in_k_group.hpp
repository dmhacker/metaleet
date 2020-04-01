#ifndef METALEET_25_SOLUTION_HPP
#define METALEET_25_SOLUTION_HPP

#include <metaleet/common/linked_list.hpp>
#include <metaleet/common/unified.hpp>

namespace metaleet {

namespace detail25 {
    // has_minimum_length :: llnode<a> -> number -> bool

    template <class head, class k>
    struct _has_minimum_length {
        using type = typename _has_minimum_length<llnode_next<head>, metal::dec<k>>::type;
    };

    template <>
    struct _has_minimum_length<llnode_end, ZERO> {
        using type = metal::true_;
    };

    template <class head>
    struct _has_minimum_length<head, ZERO> {
        using type = metal::true_;
    };

    template <class k>
    struct _has_minimum_length<llnode_end, k> {
        using type = metal::false_;
    };

    template <class head, class k>
    using has_minimum_length = typename _has_minimum_length<head, k>::type;

    // kth_node :: llnode<a> -> number -> llnode<a>

    template <class head, class k>
    struct _kth_node {
        using type = typename _kth_node<llnode_next<head>, metal::dec<k>>::type;
    };

    template <>
    struct _kth_node<llnode_end, ZERO> {
        using type = llnode_end;
    };

    template <class head>
    struct _kth_node<head, ZERO> {
        using type = head;
    };

    template <class k>
    struct _kth_node<llnode_end, k> {
        using type = llnode_end;
    };

    template <class head, class k>
    using kth_node = typename _kth_node<head, k>::type;

    // reverse_to_kth :: llnode<a> -> llnode<a> -> number -> llnode<a>

    template <class accum, class head, class k>
    struct _reverse_to_kth {
        using type = typename _reverse_to_kth<llnode<llnode_data<head>, accum>, llnode_next<head>, metal::dec<k>>::type;
    };

    template <class accum, class head>
    struct _reverse_to_kth<accum, head, ZERO> {
        using type = accum;
    };

    template <class accum, class head, class k>
    using reverse_to_kth = typename _reverse_to_kth<accum, head, k>::type;

    template <class head, class k,
        class guard = has_minimum_length<head, k>>
    struct _solve {
        using type = reverse_to_kth<
            typename _solve<kth_node<head, k>, k, has_minimum_length<kth_node<head, k>, k>>::type,
            head, k>;
    };

    template <class head, class k>
    struct _solve<head, k, metal::false_> {
        using type = head;
    };
}

// solve25 :: llnode<a> -> number -> llnode<a>

template <class head, class k>
using solve25 = typename detail25::_solve<head, k>::type;

}

#endif
