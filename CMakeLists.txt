
cmake_minimum_required(VERSION 3.14)
project(Test VERSION 1.0)

option(USE_FUNCTIONS "Use tutorial provided math implementation" ON)
configure_file(TestConfig.h.in TestConfig.h)

#set c++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the functions library
if (USE_FUNCTIONS) 
  add_subdirectory(functions)
  list(APPEND EXTRA_LIBS functions)
endif()

add_executable(Test main.cpp)
target_link_libraries(Test PUBLIC functions)

target_include_directories(Test PUBLIC
                           "${PROJECT_BINARY_DIR}")

#install
install(TARGETS Test DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TestConfig.h" DESTINATION include)
