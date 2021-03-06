add_library(functions functions.cpp)
target_link_libraries(functions PUBLIC test_compiler_flags)
set(TARGET functions PROPERTY VERSION "1.0.0")
SET(TARGET functions PROPERTY VERSION "1")
target_include_directories(functions
                           INTERFACE
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           $<INSTALL_INTERFACE:include>
                           )

option(USE_MYMATH "Use tutorial provided implementation" ON)

if (USE_MYMATH)
  target_compile_definitions(functions PRIVATE "USE_MYMATH")
  add_executable(MakeTable MakeTable.cpp)
  target_link_libraries(MakeTable PUBLIC test_compiler_flags)
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
    DEPENDS MakeTable
  )
  add_library(sqrtFunction STATIC
            sqrt.cpp
            ${CMAKE_CURRENT_BINARY_DIR}/Table.h
            )
  target_link_libraries(sqrtFunction PUBLIC test_compiler_flags)
  target_include_directories(sqrtFunction
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          PRIVATE ${CMAKE_CURRENT_BINARY_DIR}
          )
  # state that SqrtLibrary need PIC when the default is shared libraries
  set_target_properties(sqrtFunction PROPERTIES
                        POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
                        )
  target_link_libraries(functions PRIVATE sqrtFunction)
endif()

target_compile_definitions(functions PRIVATE "EXPORTING_MYMATH")

# install rules
install(TARGETS functions test_compiler_flags
        DESTINATION lib
        EXPORT functionsTargets)
install(FILES functions.hpp DESTINATION include)

