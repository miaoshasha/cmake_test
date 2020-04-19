
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


#testing
enable_testing()

#run exe
add_test(NAME runs COMMAND Test 24)
add_test(NAME Usage COMMAND Test 2)
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )
function(do_test target arg result)
  add_test(NAME Comp${arg} COMMAND ${target} ${arg})
  set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
  )
endfunction(do_test)

do_test(Test 2 "2 is 4")
do_test(Test 3.3 "3.3 is 10.89")

