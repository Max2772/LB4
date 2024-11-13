cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(SOURCE_FILES main.cpp funcs.cpp)

add_subdirectory(googletest)

add_executable(app main.cpp)
add_executable(test tests/tests.cpp)
target_link_libraries(test gtest gtest_main)

