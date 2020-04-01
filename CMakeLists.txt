cmake_minimum_required (VERSION 3.7)
project(metaleet)

include(cmake/Catch.cmake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options("-ftemplate-depth=10000000")

file(GLOB_RECURSE sources 
    "test/*.cpp"
)

add_executable(tests ${sources})
target_include_directories(tests PRIVATE "include")

include(CTest)
catch_discover_tests(tests)
