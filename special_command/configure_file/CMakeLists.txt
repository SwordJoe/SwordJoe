cmake_minimum_required(VERSION 3.10)
project(test)

add_executable(${PROJECT_NAME} main.cc)

set(var "TT" CACHE STRING "TEST FOR CONFIGURE_FILE")

configure_file(head.h.in head.h)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_BINARY_DIR})


