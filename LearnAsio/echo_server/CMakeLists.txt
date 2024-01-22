cmake_minimum_required(VERSION 3.10)
project(server)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_BINARY_PATH}")
find_package(Boost REQUIRED)


# execute_process(COMMAND conan install ${CMAKE_CURRENT_SOURCE_DIR}/conanfile.txt --build missing -if ${CMAKE_CURRENT_BINARY_DIR})
include(${CMAKE_CURRENT_BINARY_DIR}/conanbuildinfo.cmake)
# conan_basic_setup(TARGETS)

add_executable(${PROJECT_NAME} 
    src/server.cc
    src/Session.cc)


target_link_libraries(${PROJECT_NAME} PUBLIC CONAN_PKG::boost_system)