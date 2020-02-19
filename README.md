# metaleet 

[![Build Status](https://travis-ci.com/dmhacker/metaleet.svg?branch=master)](https://travis-ci.com/dmhacker/metaleet)

Yep, these Leetcode solutions *run in constant time!

<sup>*but they don't necessarily compile in constant time.</sup>

This repository is collection of solutions to common Leetcode problems, but all of
them have been rewritten as templated metaprograms in C++.
[Templates in C++ are Turing complete](https://en.wikipedia.org/wiki/Template_metaprogramming) and allow the execution of any algorithm 
at compile-time. 

The [metal](https://github.com/brunocodutra/metal) library is used to provide convenient containers like lists, maps, 
and libraries, as well as operations on those containers and integral types.

`constexpr`-based solutions are not allowed. This would defeat the
purpose of using only templates to achieve compile-time solutions; people could
just copy-paste their existing C++ solutions into a `constexpr` function.

## Build Process 

Run the following commands to execute an out-of-source build:

```
mkdir build
cd build
cmake ..
make -j{NPROC}
```

It is recommended to set {NPROC} to a value greater than 1 because it allows
multiple solutions to be built at once. The test cases included in the solutions
have been designed to not take an obscene amount of time compilation-wise - remember
that with larger test cases, the more time the compiler will take to calculate
solutions, depending on the time complexity of the algorithm.

## Testing

Testing can either be done at compile-time or at run-time or both. metal gives the 
`IS_SAME` macro as a way of producing compile-time checks to make sure that 
types match. The [Catch2](https://github.com/catchorg/Catch2) framework is then used to test the value of returned
types (specifically integral types) at run-time. As such, every solution contains
a test case:

```
TEST_CASE("Test cases for problem #...") {
    REQUIRE(solve<...>() == ...);
}
```
