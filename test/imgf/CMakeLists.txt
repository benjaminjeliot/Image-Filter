# Copyright (c) 2024 Jim Eliot

add_executable(test-runner InputPortTest.cpp OutputPortTest.cpp
                           ScalarDoubleAddNodeTest.cpp)

target_compile_features(test-runner PRIVATE cxx_std_17)

target_link_libraries(test-runner PRIVATE imgfilter GTest::gtest
                                          GTest::gtest_main)

gtest_discover_tests(test-runner)
