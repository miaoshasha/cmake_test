cmake_minimum_required(VERSION 3.14)
project(Test VERSION 1.0)

option(USE_FUNCTIONS "Use tutorial provided math implementation" ON)
configure_file(TestConfig.h.in TestConfig.h)

#set c++ standard
add_library(test_compiler_flags INTERFACE)
target_compile_features(test_compiler_flags INTERFACE cxx_std_11)

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(test_compiler_flags INTERFACE 
                       "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>" 
                       "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")

option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

#add the functions library
add_subdirectory(functions)

add_executable(Test main.cpp)
target_link_libraries(Test PUBLIC functions)

target_include_directories(Test PUBLIC
                           "${PROJECT_BINARY_DIR}")

#install
install(TARGETS Test DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TestConfig.h" DESTINATION include)


#testing
include(CTest)
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

do_test(Test 4 "4 is 2")
do_test(Test 0.64 "0.64 is 0.8")

include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Test_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Test_VERSION_MINOR}")
include(CPack)
