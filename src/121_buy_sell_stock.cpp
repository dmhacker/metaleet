#include <catch.hpp>
#include <metal.hpp>

template <class seq>
struct _solve_impl {
    using len = metal::size<seq>;

    template <class idx, class profit, class minimum>
    struct _for_loop_impl {
        using type = metal::if_<metal::less<metal::at<seq, idx>, minimum>,
            typename _for_loop_impl<metal::inc<idx>, profit, metal::at<seq, idx>>::type,
            typename _for_loop_impl<metal::inc<idx>, metal::max<profit, metal::sub<metal::at<seq, idx>, minimum>>, minimum>::type>;
    };

    template <class profit, class minidx>
    struct _for_loop_impl<len, profit, minidx> {
        using type = profit;
    };

    template <class idx, class profit, class minimum>
    using for_loop = typename _for_loop_impl<idx, profit, minimum>::type;

    using type = for_loop<metal::number<1>, metal::number<0>, metal::at<seq, metal::number<0>>>;
};

template <>
struct _solve_impl<metal::list<>> {
    using type = metal::number<0>;
};

template <class seq>
using solve = typename _solve_impl<seq>::type;

TEST_CASE("Test cases for problem #121")
{
    REQUIRE(solve<metal::numbers<7, 1, 5, 3, 6, 4>>() == 5);
    REQUIRE(solve<metal::numbers<7, 6, 4, 3, 1>>() == 0);
    REQUIRE(solve<metal::numbers<1, 2, 4, 2, 5, 7, 2, 4, 9, 0, 9>>() == 9);
    REQUIRE(solve<metal::numbers<9, 8, 7, 6, 5, 4, 4, 3, 2, 2, 1>>() == 0);
    REQUIRE(solve<metal::numbers<397, 6621, 4997, 7506, 8918, 1662, 540, 2275,
                8758, 7434, 3750, 6101, 1359, 4268, 5815, 2771, 126, 478, 9253,
                9486, 446, 985, 1492, 1646, 3756, 7970, 8476, 3009, 7457, 8922,
                2980, 577, 2342, 4069, 8341, 4400, 2923, 2730, 2917, 105>>()
        == 9360);
}
