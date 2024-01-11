cmake_minimum_required(VERSION 3.10)
project(json_test)

# include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup()

# add_executable(${PROJECT_NAME} main.cc)

# target_link_libraries(${PROJECT_NAME} PRIVATE ${CONAN_LIBS})


set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_BINARY_DIR}")




find_package(jsoncpp REQUIRED)

add_executable(${PROJECT_NAME} main.cc)

target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp::jsoncpp)

set(my_path "/test")
message(STATUS "======${my_path}======")
set(my_path ${my_path} "${CMAKE_BINARY_DIR}")
message(STATUS "======${my_path}======")

set(arg "a" "b" "c" "d")
message(STATUS "======${arg}======")
set(arg ${arg} "e" "100")
message(STATUS "======${arg}======")