cmake_minimum_required(VERSION 3.0)
project(subgraph_matching)

add_compile_options(-O3)
add_compile_options(-Wall)
add_compile_options(-std=c++11)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES src/*)

add_subdirectory(main)
