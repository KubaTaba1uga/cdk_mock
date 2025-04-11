cmake_minimum_required(VERSION 3.10)
project(c_minilib_mock)

add_library(c_minilib_mock INTERFACE)

target_include_directories(c_minilib_mock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Add -DDEBUG for all targets using this lib
target_compile_definitions(c_minilib_mock INTERFACE DEBUG)

# Store source root path for add_mocked_test access
set(C_MINILIB_MOCK_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "c_minilib_mock root")

# Expose add_mocked_test
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/cmake")
