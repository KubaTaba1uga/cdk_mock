cmake_minimum_required(VERSION 3.10)
project(c_minilib_mock)

# Library
add_library(c_minilib_mock INTERFACE)
target_include_directories(c_minilib_mock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# === Expose add_mocked_test() ===
# Make function available to parent projects that FetchContent this one
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/cmake")

