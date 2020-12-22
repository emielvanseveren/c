cmake_minimum_required(VERSION 3.17)
project(. C)

set(CMAKE_C_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wconversion -lm")

add_executable(. reeks6/46.c)
target_link_libraries(. m)
