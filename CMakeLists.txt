cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 14)

# set the project name
project(myredisclient)

set(lib 
    Server.h
    Connection.h 
    Connection.cpp 
    Command.h 
)

add_library(mylib ${lib}) 
target_include_directories(mylib PUBLIC hiredis/)
target_link_libraries(mylib PUBLIC hiredis)
target_link_directories(mylib PUBLIC hiredis/)

add_executable(MyTest test.cpp )

add_subdirectory(hiredis)
add_subdirectory(third_party/googletest)

target_include_directories(MyTest PRIVATE third_party/googletest/googletest)
target_link_libraries(MyTest PRIVATE mylib gtest gtest_main)   

if(TEST)
    enable_testing()
    include(GoogleTest)
    gtest_discover_tests(MyTest)
endif()

set (CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
if(TEST_COVERAGE)
    message("YAY....")
    set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
    include(CodeCoverage)
    append_coverage_compiler_flags()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -O0")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
    set(GCOVR_PATH "/home/ali/.local/bin/gcovr")
    setup_target_for_coverage_gcovr_html(
        NAME TestCoverage
        EXECUTABLE MyTest
        DEPENDENCIES MyTest mylib gtest
    )
endif()








