cmake_minimum_required(VERSION 3.16)
project("C++ Exercises")

link_directories("/usr/local/lib")
include_directories("/usr/local/include")

add_library(complex SHARED complex.cpp)
add_executable(complex_tests_runner complex_tests.cpp)
target_link_libraries(complex_tests_runner complex gtest gtest_main)
add_custom_target(test_complex
        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/complex_tests_runner
        DEPENDS complex_tests_runner)