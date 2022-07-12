cmake_minimum_required(VERSION 3.12)

project(trash_bin CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(trash_bin INTERFACE)
target_include_directories(trash_bin INTERFACE include)

add_executable(test1 tests/test1.cpp)
set_property(TARGET test1 PROPERTY CXX_STANDARD 20)
target_link_libraries(test1 PRIVATE trash_bin)

target_compile_options(test1 PRIVATE -g)

enable_testing()
add_test(NAME test1
         COMMAND test1)
 