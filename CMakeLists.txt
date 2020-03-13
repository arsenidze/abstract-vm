cmake_minimum_required(VERSION 3.8)

project(a-vm-with-tests)

enable_testing()

#find_package(Boost REQUIRED)

#include_directories(include)

add_subdirectory("src" "build/src")
add_subdirectory("test" "build/test")