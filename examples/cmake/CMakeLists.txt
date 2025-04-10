cmake_minimum_required(VERSION 3.10)
project(minimal_mock_example C)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

# Fetch c_minilib_mock from GitHub
FetchContent_Declare(
  c_minilib_mock
  GIT_REPOSITORY https://github.com/KubaTaba1uga/c_minilib_mock.git
  GIT_TAG master
)

FetchContent_MakeAvailable(c_minilib_mock)

# Include the mocking CMake function from the fetched project
include(add_mocked_test)

# Your test target
add_executable(mytest src/main.c test/test_main.c)

# Define the mocked test
add_mocked_test(
    NAME mytest
    COMMAND mytest
    MOCKED_TESTS foo
)
