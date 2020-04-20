add_executable(MakeTable MakeTable.cpp)
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
)
add_library(functions
            sqr.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )

target_include_directories(functions
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )
install(TARGETS functions DESTINATION lib)
install(FILES functions.hpp DESTINATION include)

