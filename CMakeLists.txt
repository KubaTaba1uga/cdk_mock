# Usage example:
#    add_mocked_test(
#        NAME MyTest
#        COMMAND MyTestExe arg1 arg2
#        MOCKED_TESTS funcA funcB
#        
#    )


function(add_mocked_test)
    set(one_value_keywords NAME)
    set(multi_value_keywords MOCKED_TESTS)

    cmake_parse_arguments(
        MOCK_ARGS
        "${one_value_keywords}"
        "${multi_value_keywords}"
        ${ARGN}
    )

    # Validate
    if(NOT MOCK_ARGS_NAME)
        message(FATAL_ERROR "add_mocked_test: NAME argument is required.")
    endif()

    if(MOCK_ARGS_UNPARSED_ARGUMENTS)
        add_test(NAME ${MOCK_ARGS_NAME} ${MOCK_ARGS_UNPARSED_ARGUMENTS})
    else()
        message(FATAL_ERROR 
          "You must specify arguments for add_test (e.g., COMMAND <exe> [...]).")
    endif()



    if(MOCK_ARGS_MOCKED_TESTS)
        message(STATUS "Mocked functions: ${MOCK_ARGS_MOCKED_TESTS}")
    endif()
endfunction()
