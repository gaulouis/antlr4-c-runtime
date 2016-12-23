
aux_source_directory(. SRC_LIST)
add_executable(${PROJECT_NAME}-demo ${SRC_LIST})

target_link_libraries (${PROJECT_NAME}-demo ${PROJECT_NAME}-runtime)
include_directories("${PROJECT_BINARY_DIR}/lib/runtime" "${PROJECT_SOURCE_DIR}/lib/runtime")

install (TARGETS ${PROJECT_NAME}-demo DESTINATION bin)

