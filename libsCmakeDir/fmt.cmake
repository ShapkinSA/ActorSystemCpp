set(FMT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/fmt)

if(NOT EXISTS ${FMT_DIR}/libfmt.a)
    message("BUILDING FMT")

    execute_process(COMMAND cmake .
            WORKING_DIRECTORY ${FMT_DIR}
    )

    execute_process(COMMAND make -j8
            WORKING_DIRECTORY ${FMT_DIR}
    )

    message("BUILDING FMT IS FINISHED")
endif()
