# Defines a test with optional function mocking using linker wrapping.
#
# Usage:
#   add_mocked_test(
#       NAME <test_target_name>           # Required: name of the test target (must match an existing executable target)
#       COMMAND <exe> [args...]           # Required: test command and arguments passed to add_test()
#       MOCKED_TESTS <func1> <func2> ...  # Optional: functions to wrap using -Wl,--wrap=<func>
#   )
#
# Notes:
# - The target <test_target_name> must already be created using add_executable().
# - Each function listed in MOCKED_TESTS will be passed as a linker option:
#     -Wl,--wrap=<func>
# - This is useful for linking against custom mocks of standard or internal functions.

include_guard(GLOBAL)

function(add_mocked_test)
    message(STATUS "=== add_mocked_test loaded ===")

    set(one_value_keywords NAME)
    set(multi_value_keywords MOCKED_TESTS)

    cmake_parse_arguments(
        MOCK_ARGS
        ""
        "${one_value_keywords}"
        "${multi_value_keywords}"
        ${ARGN}
    )

    if(NOT MOCK_ARGS_NAME)
        message(FATAL_ERROR "add_mocked_test: NAME argument is required.")
    endif()

    if(MOCK_ARGS_UNPARSED_ARGUMENTS)
        add_test(NAME ${MOCK_ARGS_NAME} ${MOCK_ARGS_UNPARSED_ARGUMENTS})
    else()
        message(FATAL_ERROR "add_mocked_test: you must specify COMMAND <exe> [...].")
    endif()

    if(MOCK_ARGS_MOCKED_TESTS)
        set(WRAP_FLAGS "")
        foreach(func IN LISTS MOCK_ARGS_MOCKED_TESTS)
            list(APPEND WRAP_FLAGS "-Wl,--wrap=${func}")
        endforeach()
        target_link_options(${MOCK_ARGS_NAME} PRIVATE ${WRAP_FLAGS})
    endif()
    
    if(NOT DEFINED C_MINILIB_MOCK_SOURCE_DIR)
      message(FATAL_ERROR "C_MINILIB_MOCK_SOURCE_DIR not set. Ensure c_minilib_mock was properly included.")
    endif()

    set(MOCK_INCLUDE_DIR "${C_MINILIB_MOCK_SOURCE_DIR}/include")

    message(STATUS "Using include path: ${MOCK_INCLUDE_DIR}")
    
    target_include_directories(${MOCK_ARGS_NAME} PRIVATE ${MOCK_INCLUDE_DIR})

    target_compile_options(${MOCK_ARGS_NAME} PRIVATE -O0 -fno-inline -DENABLE_MOCKS)
endfunction()
