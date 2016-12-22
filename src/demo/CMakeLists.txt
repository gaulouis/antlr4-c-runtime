
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME}-demo ${SRC_LIST})

target_link_libraries (${PROJECT_NAME}-demo ${PROJECT_NAME}-runtime)
target_compile_definitions(${PROJECT_NAME}-demo PRIVATE ENABLE_DEBUG=1)
include_directories("${PROJECT_BINARY_DIR}/lib/runtime" "${PROJECT_SOURCE_DIR}/lib/runtime")

install (TARGETS ${PROJECT_NAME}-demo DESTINATION bin)

