
cmake_minimum_required(VERSION 3.14)
project(Test VERSION 1.0)

option(USE_MYMATH "Use tutorial provided math implementation" ON)
configure_file(TestConfig.h.in TestConfig.h)

#set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the functions library
add_subdirectory(functions)

add_executable(Test main.cpp)
target_link_libraries(Test PUBLIC functions)

target_include_directories(Test PUBLIC
                           "${PROJECT_SOURCE_DIR}/functions"
                           "${PROJECT_BINARY_DIR}")


