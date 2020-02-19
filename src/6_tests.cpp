#include <catch.hpp>

#include <6_zigzag_conversion.hpp>

template<char... cs>
constexpr auto operator ""_raw()
    -> metal::numbers<cs...> {
    return {};
}

TEST_CASE("Test cases for problem #6")
{
    REQUIRE(metal::same<metaleet::solve6<metal::numbers<>, metal::number<100>>, 
            metal::numbers<>>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<1>>, 
            decltype(12345_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<2>>, 
            decltype(13524_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<3>>, 
            decltype(15243_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<4>>, 
            decltype(12354_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<5>>, 
            decltype(12345_raw)>()); 
    REQUIRE(metal::same<metaleet::solve6<decltype(12345_raw), metal::number<6>>, 
            decltype(12345_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(1234567890_raw), metal::number<3>>, 
            decltype(1592468037_raw)>());
    REQUIRE(metal::same<metaleet::solve6<decltype(1234567890_raw), metal::number<4>>, 
            decltype(1726835940_raw)>());
}
