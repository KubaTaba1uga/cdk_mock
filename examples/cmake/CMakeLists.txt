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

include("${c_minilib_mock_SOURCE_DIR}/cmake/setup.cmake")

# Your test target, but remember to always put test files first, otherwise
#  linker will pick orginal function instead of wrapped one.
# Remember to split mocked functions from main. If you put mocked function
#  in the same compilation unit, than linker cannot do anything, and wrapping
#  doesn't work.
add_executable(mytest test_main.c main.c lib.c)

# Define the mocked test
add_mocked_test(
    NAME mytest
    COMMAND mytest
    MOCKED_TESTS foo
)
