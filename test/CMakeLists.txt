add_executable(runTests TestPlayerMana.cpp TestTriggers.cpp TestZone.cpp)

target_link_libraries(runTests gtest_main openhs)
