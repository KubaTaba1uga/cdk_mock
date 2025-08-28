cmake_minimum_required(VERSION 3.10)
project(minimal_mock_example C)

set(CMAKE_C_STANDARD 99)

include(FetchContent)

# Fetch cdk_mock from GitHub
FetchContent_Declare(
  cdk_mock
  GIT_REPOSITORY https://github.com/KubaTaba1uga/cdk_mock.git
  GIT_TAG apply_small_improvements
)

FetchContent_MakeAvailable(cdk_mock)

add_executable(example_1 main.c lib.c)
target_link_libraries(example_1 PRIVATE cdk_mock)

# Your test target, but remember to always put test files first, otherwise
#  linker will pick orginal function instead of wrapped one.
# Remember to split mocked functions from main. If you put mocked function
#  in the same translation unit, then linker cannot do anything, and wrapping
#  doesn't work.
add_executable(example_1_test mock_lib.c main.c lib.c)
target_link_libraries(example_1_test PRIVATE cdk_mock)

# Include is required if you want to use `add_mocked_test` function.
include("${CDK_MOCK_SOURCE_DIR}/cmake/setup.cmake")
add_mocked_test(
    NAME example_1_test
    COMMAND example_1_test
    MOCKED_TESTS foo
)
