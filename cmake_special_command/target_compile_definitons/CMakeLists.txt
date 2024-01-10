cmake_minimum_required(VERSION 3.12)
project(test)

add_library(add SHARED 3rdparty/add.cpp)

set(flag)

if(${flag})
    #如果flag为true，则设置编译选项为_DEBUG_，这样在编译libadd.so的时候，会在add库的源代码中加入_DEBUG_宏定义
    target_compile_definitions(add PRIVATE _DEBUG_)
endif()
message(${flag})

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC 3rdparty)
target_link_libraries(${PROJECT_NAME} add)