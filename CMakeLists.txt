function(add_mocked_test)
    # We'll parse "mocked_tests" as a multi-value keyword:
    #   add_mocked_test(
    #     mocked_tests funcA;funcB
    #     NAME MyTest
    #     COMMAND MyTestExe arg1 arg2
    #     ...
    #   )
    #
    # Everything else goes straight to add_test().
    set(options)                   # No boolean/option keywords
    set(one_value_keywords)        # No single-value keywords
    set(multi_value_keywords MOCKED_TESTS)  # Our custom keyword

    cmake_parse_arguments(
        MOCK_ARGS                 # Output variable prefix
        "${options}"
        "${one_value_keywords}"
        "${multi_value_keywords}"
        ${ARGN}                   # All arguments passed to function
    )

    # The leftover, unparsed arguments are for add_test().
    if(MOCK_ARGS_UNPARSED_ARGUMENTS)
        add_test(${MOCK_ARGS_UNPARSED_ARGUMENTS})
    else()
        message(FATAL_ERROR 
          "You must specify arguments for add_test (e.g., NAME <test_name> COMMAND <exe> [...]).")
    endif()

    # Print the mocked functions for reference
    if(MOCK_ARGS_MOCKED_TESTS)
        message(STATUS "Mocked functions: ${MOCK_ARGS_MOCKED_TESTS}")
    endif()
endfunction()
