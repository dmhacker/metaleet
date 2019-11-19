# Contributing

We welcome four types of improvements to the repository.

1. Adding a new Leetcode solution (see "Solution Addition Process").
2. Modifying an existing Leetcode solution (see "Solution Improvement Process").
3. Extending the API with new data structures or functions (see "API Addition Process").
4. Modifying the existing API (see "API Improvement Process"). 

## Solution Addition Process

1. Find a Leetcode problem that is not already in the repository.
2. Create and edit the file "src/${PROBLEM_NUMBER}_${PROBLEM_TITLE}.cpp". See **src/** for examples.
3. Implement its solution as a templated metaprogram. The entry function should be called `solve<...>`.
4. Create a block called `TEST_CASES("Test cases for problem #{PROBLEM_NUMBER}") { ... }`.
5. Inside the `TEST_CASES`, add run-time `REQUIRE` checks to ensure that the actual output
from `solve` matches expected output. 
    1. Note that this may require evaluation of the type
    returned from `solve`, which can be done by calling the type with `operator()`, assuming
    that `solve` returns an integral number type. 
    2. For lists, you may use metaleet's linked list
    library to convert a `metal::list<>` into a metaleet `llnode<>` and then into a `std::vector`.
6. Open a PR so it can be reviewed before merging to master.

## Solution Improvement Process

1. Find the file in **src/** corresponding to the Leetcode problem that you wish to modify.
2. Edit the solution and add your changes.
3. Ensure that the previous/remaining test cases still work for the problem. 
4. Open a PR so that it can be reviewed before merging to master. 
5. Inside the PR, add a note explaining why your changes are warranted 
(e.g speed improvements, etc.)

## API Addition Process

1. Determine what data structures and/or functions are missing from metaleet's API.
2. Create a file encapsulating your additions in the **include/** directory. It should be header-only.
3. Open a PR so that it can be reviewed before merging to master.
4. Inside the PR, add a note explaining why this is a necessary addition to the API.

## API Improvement Process

1. Find the API header file in **include/** that you wish to amend.
2. Edit the file and add your changes.
3. Open a PR so that it can be reviewed before merging to master.
4. Inside the PR, add a note explaining why this is a necessary modification to the API.

## Code Standards 

There are some general guidelines that are recommended but are not necessarily enforced. 
* Use `using type = ...` to indicate that a templated struct returns a particular type.
* Hide the `typename _<...> type` syntax used to evaluate return types of templated structs.
    * For example, say we have 
    ```cpp
    template<class num> 
    _increment_impl { 
        using type = metal::inc<num>; 
    }
    ```
    * We could use `typename _increment_impl<metal::number<0>>::type` to evaluate this.
    * However, we prefer creating an alias via `using` and then call that instead:
    ```
    template <class num>
    using increment = typename _increment_impl<num>::type; 
    ...
    increment<metal::number<0>>
    ...
    ```
    * This should help make code more readable. 
* Templated structs should take in C++ types and return C++ types. They should not take in `int` values
and return `int` values. Everything must be a C++ type. 
    * If you wish to use numbers, consider using their integral type representations `metal::number<>`.
    Note that metal's number representation is itself aliased to `std::integral_constant<>`.
* For any functions (templated structs), add a comment explaining the method's type signature.
    * The comment should be a Haskell-like type signature declaration: ${NAME} :: ${ARG1} -> ... -> ${ARGI} -> ${RETTYPE}
    * It will not be immediately obvious to any human reading your code because templates can take in any type
    and return any type. Ideally, those types should all fit into certain generalized groups of types.
    * For example, the `increment` function above takes in a `metal::number<...>` type and 
    returns `metal::number<...>` type.
    * Therefore, its type declaration would be: increment :: number -> number 
* Avoid nesting structs whenever possible and shoot for making everything top-level. 
* Make use of the [metal library](http://brunocodutra.github.io/metal/) and the [linked lists library](https://github.com/dmhacker/metaleet/blob/master/include/linked_lists.hpp) whenever possible.
