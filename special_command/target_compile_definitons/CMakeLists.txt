cmake_minimum_required(VERSION 3.12)
project(test)

add_library(add SHARED 3rdparty/add.cpp)

set(flag false CACHE BOOL "Debug flag")

message(${flag})

set(flag true CACHE BOOL "TEST")
message(${flag})



# if(${flag})
#     target_compile_definitions(add PRIVATE _DEBUG_)
# endif()
# message(${flag})

# add_executable(${PROJECT_NAME} src/main.cpp)
# target_include_directories(${PROJECT_NAME} PUBLIC 3rdparty)
# target_link_libraries(${PROJECT_NAME} add)