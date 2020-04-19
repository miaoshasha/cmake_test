
add_library(functions sqr.cpp)

target_include_directories(functions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
install(TARGETS functions DESTINATION lib)
install(FILES functions.hpp DESTINATION include)
