add_subdirectory(misc)

configure_file (
  "${PROJECT_SOURCE_DIR}/lib/runtime/Config.h.in"
  "${PROJECT_BINARY_DIR}/lib/runtime/Config.h"
)

include_directories ("${PROJECT_SOURCE_DIR}/lib/runtime" "${PROJECT_BINARY_DIR}/lib/runtime")

add_library (${PROJECT_NAME}-runtime
    types.h
    runtime.h
    char-stream-interface.c
    int-stream-interface.c
    input-stream.c
    file-stream.c)

if(ENABLE_DEBUG)
  add_definitions(-DENABLE_DEBUG=1)
endif()

target_link_libraries (${PROJECT_NAME}-runtime ${PROJECT_NAME}-runtime-misc)

install (TARGETS ${PROJECT_NAME}-runtime DESTINATION lib)
install (FILES
		runtime.h
		int-stream-interface.h
		char-stream-interface.h
		input-stream.h
		file-stream.h
	DESTINATION include/${PROJECT_NAME}/antlr)
install (FILES "${PROJECT_BINARY_DIR}/lib/runtime/Config.h" DESTINATION lib/${PROJECT_NAME}/include)

