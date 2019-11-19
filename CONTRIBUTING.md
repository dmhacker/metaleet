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


