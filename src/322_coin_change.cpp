#include <catch.hpp>
#include <metal.hpp>

template <class coins, class amount, class is_neg_amount>
struct _solve_base_impl {
    template<class change, class coin, class subchange>
    struct _for_each_coin_impl {
        using type = metal::if_<metal::same<change, metal::number<-1>>, metal::inc<subchange>, 
              metal::min<metal::inc<subchange>, change>>; 
    };

    template<class change, class coin>
    struct _for_each_coin_impl<change, coin, metal::number<-1>> {
        using type = change;
    };

    template<class change, class coin>
    using for_each_coin = typename _for_each_coin_impl<change, coin, 
          typename _solve_base_impl<coins, metal::sub<amount, coin>, metal::less<amount, coin>>::type>::type;

    using type = metal::accumulate<metal::lambda<for_each_coin>, metal::number<-1>, coins>;
};

template <class coins, class is_neg_amount>
struct _solve_base_impl<coins, metal::number<0>, is_neg_amount> {
    using type = metal::number<0>;
};

template <class coins, class amount>
struct _solve_base_impl<coins, amount, metal::true_> {
    using type = metal::number<-1>;
};

template <class coins, class amount>
using solve = typename _solve_base_impl<coins, amount, metal::less<amount, metal::number<0>>>::type;

TEST_CASE("Test cases for problem #322")
{
    REQUIRE(solve<metal::numbers<1, 2, 5>, metal::number<11>>() == 3);
    REQUIRE(solve<metal::numbers<2>, metal::number<3>>() == -1);
    REQUIRE(solve<metal::numbers<474, 83, 404, 3>, metal::number<264>>() == 8);
    REQUIRE(solve<metal::numbers<384, 324, 196, 481>, metal::number<285>>() == -1);
}
