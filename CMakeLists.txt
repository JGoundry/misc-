cmake_minimum_required(VERSION 3.31)
project(misc++ LANGUAGES CXX)

# Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Testing
enable_testing()
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.17.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

# Targets
add_library(heap INTERFACE)
target_include_directories(heap INTERFACE src/heap)

add_executable(test_heap tests/heap/test_heap.cpp)
target_link_libraries(test_heap PRIVATE heap GTest::gtest GTest::gtest_main)

# Ctest discovery
gtest_discover_tests(test_heap)
