add_executable(runTests TestManaEvents.cpp TestTriggers.cpp TestZone.cpp)

target_link_libraries(runTests gtest_main openhs)
