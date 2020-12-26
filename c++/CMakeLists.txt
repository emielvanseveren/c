cmake_minimum_required(VERSION 3.17)
project(c++)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_HEADERS
        reeks4/breuk.h)
set(PROJECT_SOURCES
        reeks4/breuk.cpp
        reeks4/20.cpp
        )
add_executable(c++ ${PROJECT_SOURCES} ${PROJECT_HEADERS})