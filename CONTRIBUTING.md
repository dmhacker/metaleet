# Contributing

We welcome four types of improvements to the repository.

1. Adding a new Leetcode solution (see "Solution Addition Process").
2. Modifying an existing Leetcode solution (see "Solution Improvement Process").
3. Extending the API with new data structures or functions (see "API Extension Process").
4. Modifying the existing API (see "API Improvement Process"). 

## Solution Addition Process

1. Find a Leetcode problem that is not already in the repository.
2. Create and edit the file "src/${PROBLEM_NUMBER}_${PROBLEM_TITLE}.cpp". See **src/** for examples.
3. Implement its solution as a templated metaprogram. The entry function should be called `solve<...>`.
4. Create a block called `TEST_CASES("Test cases for problem #{PROBLEM_NUMBER}") { ... }`.
5. Inside the `TEST_CASES`, add run-time `REQUIRE` checks to ensure that the actual output
from `solve` matches expected output. Note that this may require evaluation of the type
returned from `solve`, which can be done by calling the type with `operator()`, assuming
that `solve` returns an integral number type. For lists, you may use metaleet's linked list
library to convert a `metal::list<>` into a metaleet `llnode<>` and then into a `std::vector`.
6. Open a PR so it can be reviewed before merging to master.

## Solution Improvement Process

1. Find the file corresponding to the Leetcode problem that you wish to modify.
2. Edit the solution and add your changes.
3. Ensure that the previous/remaining test cases still work for the problem. 
4. Open a PR so that it can be reviewed before merging to master. 
5. Inside the PR, add a sufficient description explaining why your changes are warranted 
(e.g speed improvements, caught bug, etc.)

## API Extension Process

1. 

## API Improvement Process

1. 

## Code Standards 
