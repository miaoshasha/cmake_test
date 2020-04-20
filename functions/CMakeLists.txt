
add_library(functions sqr.cpp)

target_include_directories(functions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
install(TARGETS functions DESTINATION lib)
install(FILES functions.hpp DESTINATION include)

include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

if (HAVE_LOG AND HAVE_EXP)
  target_compile_definitions(functions
                             PRIVATE "HAVE_LOG" "HAVE_EXP")
endif()
