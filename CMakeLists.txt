cmake_minimum_required(VERSION 3.17)
project(c C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -lm")

add_executable(c reeks4/26.c)