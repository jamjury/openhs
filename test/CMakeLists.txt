add_executable(runTests TestManaEvents.cpp)

target_link_libraries(runTests gtest_main winstone)