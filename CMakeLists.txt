cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

set(sources redis.hpp server.hpp Connection.hpp Connection.cpp DataBase.cpp DataBase.hpp Command.hpp parse.hpp
    runcommand.cpp runcommand.hpp )

add_library(mylib STATIC ${sources})

add_executable(${PROJECT_NAME} test.cpp )

add_subdirectory(hiredis ../)

target_include_directories(${PROJECT_NAME} PUBLIC hiredis/ PUBLIC ./)

target_link_directories(${PROJECT_NAME} PUBLIC hiredis/ PUBLIC ./)

target_link_libraries(${PROJECT_NAME} PUBLIC hiredis PUBLIC mylib)

