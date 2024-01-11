cmake_minimum_required(VERSION 3.10)
project(cvtest)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_BINARY_DIR}")
# find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME} main.cpp func.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE CONAN_PKG::opencv)