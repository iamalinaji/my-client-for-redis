cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

set(sources 
    test.cpp
    Redis.h
    Redis.cpp
    Server.h
    Connection.h 
    Connection.cpp 
    DataBase.cpp 
    DataBase.h 
    Command.h 
    Parse.h
    Parse.cpp 
    RunCommand.cpp 
    RunCommand.h )

add_executable(${PROJECT_NAME} ${sources} )

add_subdirectory(hiredis)

target_include_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_libraries(${PROJECT_NAME} PUBLIC hiredis)

