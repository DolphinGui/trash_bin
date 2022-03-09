cmake_minimum_required(VERSION 3.12)

project(trash_bin CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(test1 tests/test1.cpp)
set_property(TARGET test1 PROPERTY CXX_STANDARD 20)
target_include_directories(test1 PUBLIC include)

enable_testing()
add_test(NAME test1
         COMMAND test1)
 