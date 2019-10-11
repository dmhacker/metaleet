#include <iostream>

template<int n>
struct MinSteps {
    template <int i, int result>
    struct DPLoop {
        static constexpr int minimum = (n % i != 0) ? 
                DPLoop<i + 1, result>::minimum :  
                DPLoop<i + 1, result <= (MinSteps<i>::value + n / i) ? 
                        result : (MinSteps<i>::value + n / i)>::minimum;
    };

    template <int result>
    struct DPLoop<n, result> {
        static constexpr int minimum = result;
    };

    static constexpr int value = DPLoop<2, n>::minimum;
};


template <>
struct MinSteps<1> {
    static constexpr int value = 0;
};

int main() {
    std::cerr << MinSteps<ARGUMENT_1>::value << std::endl;
}
