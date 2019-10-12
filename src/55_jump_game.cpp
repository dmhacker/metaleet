#include <catch.hpp>
#include <metal.hpp>

template <class seq>
struct solve {
    template <class idx, class old_value>
    struct for_loop {
        using value = typename for_loop<metal::dec<idx>, 
              metal::if_<metal::greater<old_value, metal::add<idx, metal::at<seq, idx>>>, old_value, idx>>::value; 
    };

    template <class old_value>
    struct for_loop<metal::number<-1>, old_value> {
        using value = old_value; 
    };

    using value = metal::not_<typename for_loop<metal::dec<metal::dec<metal::size<seq>>>, metal::dec<metal::size<seq>>>::value>;
};

template <>
struct solve<metal::list<>> {
    using value = metal::false_;
};

TEST_CASE("Leetcode test cases for #55")
{
    REQUIRE(solve<metal::numbers<2, 3, 1, 1, 4>>::value() == true);
    REQUIRE(solve<metal::numbers<3, 2, 1, 0, 4>>::value() == false);
    REQUIRE(solve<metal::numbers<
            1,2,2,6,3,6,1,8,9,4,7,6,5,6,8,2,6,1,3,6,6,6,3,2,4,9,4,5,
            9,8,2,2,1,6,1,6,2,2,6,1,8,6,8,3,2,8,5,8,0,1,4,8,7,9,0,3,
            9,4,8,0,2,2,5,5,8,6,3,1,0,2,4,9,8,4,4,2,3,2,2,5,5,9,3,2,
            8,5,8,9,1,6,2,5,9,9,3,9,7,6,0,7,8,7,8,8,3,5,0>>::value() == true);
    REQUIRE(solve<metal::numbers<
            2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,
            2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,
            6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,
            9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6>>::value() == false);
}
