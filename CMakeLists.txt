cmake_minimum_required(VERSION 3.10)

# set the project name
project(myredisclient)

# add the executable
add_executable(${PROJECT_NAME} test.cpp)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)