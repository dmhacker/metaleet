#ifndef METALEET_322_COIN_CHANGE_HPP
#define METALEET_322_COIN_CHANGE_HPP

#include <metal.hpp>

namespace metaleet {

// solve322 :: list<number> -> number -> number

template <class coins, class amount, class is_neg_amount>
struct _solve322_impl {

    // coin_loop :: number -> number -> number -> number

    template<class change, class coin, class subchange>
    struct _coin_loop_impl {
        using type = metal::if_<metal::same<change, metal::number<-1>>, metal::inc<subchange>, 
              metal::min<metal::inc<subchange>, change>>; 
    };

    template<class change, class coin>
    struct _coin_loop_impl<change, coin, metal::number<-1>> {
        using type = change;
    };

    template<class change, class coin>
    using coin_loop = typename _coin_loop_impl<change, coin, 
          typename _solve322_impl<coins, metal::sub<amount, coin>, metal::less<amount, coin>>::type>::type;

    using type = metal::accumulate<metal::lambda<coin_loop>, metal::number<-1>, coins>;
};

template <class coins, class is_neg_amount>
struct _solve322_impl<coins, metal::number<0>, is_neg_amount> {
    using type = metal::number<0>;
};

template <class coins, class amount>
struct _solve322_impl<coins, amount, metal::true_> {
    using type = metal::number<-1>;
};

template <class coins, class amount>
using solve322 = typename _solve322_impl<coins, amount, metal::less<amount, metal::number<0>>>::type;

}

#endif
