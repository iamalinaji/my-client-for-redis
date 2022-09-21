cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

# add the executable
add_executable(${PROJECT_NAME} test.cpp)

add_subdirectory(hiredis)

target_include_directories(${PROJECT_NAME} PUBLIC hiredis/)

target_link_directories(${PROJECT_NAME} 
    PRIVATE hiredis/)

target_link_libraries(${PROJECT_NAME} PRIVATE hiredis)

