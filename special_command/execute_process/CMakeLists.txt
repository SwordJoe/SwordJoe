cmake_minimum_required(VERSION 3.10)
project(test)

set(MYVAR "null")

execute_process(COMMAND ls
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                RESULT_VARIABLE RET
                INPUT_FILE INPUT
                OUTPUT_VARIABLE OUTPUT
                )

#execute_process(COMMAND python3 )


message(STATUS "RESULT_VARIABLE:${RET}")
# message(STATUS ${INPUT})
# message(STATUS ${OUTPUT})