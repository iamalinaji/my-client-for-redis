cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

set(lib 
    test.cpp
    Server.h
    Connection.h 
    Connection.cpp 
    Command.h 
)

add_library(mylib ${lib}) 
target_include_directories(mylib PUBLIC hiredis/)
target_link_libraries(mylib PUBLIC hiredis)
target_link_directories(mylib PUBLIC hiredis/)

add_executable(${PROJECT_NAME} test.cpp )

add_subdirectory(hiredis)

target_link_libraries(${PROJECT_NAME} PUBLIC mylib)

