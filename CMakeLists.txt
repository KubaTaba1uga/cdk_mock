cmake_minimum_required(VERSION 3.10)
project(cdk_mock)

add_library(cdk_mock INTERFACE)

target_include_directories(cdk_mock INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Store source root path for add_mocked_test access
set(CDK_MOCK_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" CACHE INTERNAL "cdk_mock root")

# Expose add_mocked_test
set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH}" "${CMAKE_CURRENT_LIST_DIR}/cmake")
