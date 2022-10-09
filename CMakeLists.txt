cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

set(sources 
    test.cpp
    Server.h
    Connection.h 
    Connection.cpp 
    Command.h 
)

add_executable(${PROJECT_NAME} ${sources} )

add_subdirectory(hiredis)

target_include_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_libraries(${PROJECT_NAME} PUBLIC hiredis)

