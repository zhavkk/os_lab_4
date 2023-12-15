cmake_minimum_required(VERSION 3.10)

project(OS_lab4)

set(CMAKE_C_STANDARD 11)

add_library(realization1 SHARED realization1.c)
add_library(realization2 SHARED realization2.c)

add_executable(first main_1.c)
target_link_libraries(first PRIVATE realization1 m)

add_executable(second main_2.c)
target_link_libraries(second PRIVATE realization2 m)