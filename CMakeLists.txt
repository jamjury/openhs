cmake_minimum_required(VERSION 3.8)
project(winstone)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/events/Event.h src/Player.h src/events/mana/GainMana.cpp src/events/mana/GainMana.h src/events/mana/GainEmptyMana.cpp src/events/mana/GainEmptyMana.h src/Player.cpp)
add_library(winstone ${SOURCE_FILES})

include_directories(src)

add_subdirectory(googletest EXCLUDE_FROM_ALL)
add_subdirectory(test)