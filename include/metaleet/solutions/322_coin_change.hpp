#ifndef METALEET_322_SOLUTION_HPP
#define METALEET_322_SOLUTION_HPP

#include <common/unified.hpp>

namespace metaleet {

namespace detail322 {
    template <class coins, class amount, class is_neg_amount>
    struct _solve {
        // coin_loop :: number -> number -> number -> number

        template <class change, class coin, class subchange>
        struct _coin_loop {
            using type = metal::if_<metal::same<change, metal::number<-1>>, metal::inc<subchange>,
                metal::min<metal::inc<subchange>, change>>;
        };

        template <class change, class coin>
        struct _coin_loop<change, coin, metal::number<-1>> {
            using type = change;
        };

        template <class change, class coin>
        using coin_loop = typename _coin_loop<change, coin,
            typename _solve<coins, metal::sub<amount, coin>, metal::less<amount, coin>>::type>::type;

        using type = metal::accumulate<metal::lambda<coin_loop>, metal::number<-1>, coins>;
    };

    template <class coins, class is_neg_amount>
    struct _solve<coins, ZERO, is_neg_amount> {
        using type = ZERO;
    };

    template <class coins, class amount>
    struct _solve<coins, amount, metal::true_> {
        using type = metal::number<-1>;
    };
}

// solve322 :: list<number> -> number -> number

template <class coins, class amount>
using solve322 = typename detail322::_solve<coins, amount, metal::less<amount, ZERO>>::type;

}

#endif
