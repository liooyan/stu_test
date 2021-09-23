cmake_minimum_required(VERSION 3.20)
project(stu_test C)

add_subdirectory(1)
add_subdirectory(2)

set(CMAKE_C_STANDARD 99)
add_executable(stu_test main.c )

