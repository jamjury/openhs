add_executable(runTests test_mana.cpp)

target_link_libraries(runTests gtest_main winstone)