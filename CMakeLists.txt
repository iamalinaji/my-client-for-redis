cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

set(sources 
    test.cpp
    redis.hpp 
    redis.cpp
    server.hpp 
    Connection.hpp 
    Connection.cpp 
    DataBase.cpp 
    DataBase.hpp 
    Command.hpp 
    parse.hpp
    parse.cpp 
    runcommand.cpp 
    runcommand.hpp )

add_executable(${PROJECT_NAME} ${sources} )

add_subdirectory(hiredis)

target_include_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_libraries(${PROJECT_NAME} PUBLIC hiredis)

