cmake_minimum_required (VERSION 3.2.0)

project(super-simple-stock-market VERSION 0.0.0 LANGUAGES C CXX)

add_subdirectory(src)
enable_testing()
add_subdirectory(unit-tests)
