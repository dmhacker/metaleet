cmake_minimum_required (VERSION 3.7)
project(metaleet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_definitions(${PROBLEM})
add_compile_options("-ftemplate-depth=10000000")

file(GLOB sources 
    "src/*.cpp"
)
foreach(source ${sources})
    get_filename_component(tmp ${source} NAME)
    string(REPLACE ".cpp" "" execname ${tmp})
    add_executable(${execname} ${source})
endforeach()
