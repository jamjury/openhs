cmake_minimum_required(VERSION 3.8)
project(winstone)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/library.cpp include/library.h)
add_library(winstone ${SOURCE_FILES})

include_directories(include)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)