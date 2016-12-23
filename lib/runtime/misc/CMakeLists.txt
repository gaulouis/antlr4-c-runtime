
add_library (${PROJECT_NAME}-runtime-misc
    type.c
    object.c
    debug.c
)
include_directories ("${PROJECT_BINARY_DIR}/lib/runtime")

if(ENABLE_DEBUG)
  add_definitions(-DENABLE_DEBUG=1)
endif()

install (FILES
		macro.h
		type.h
		object.h
	DESTINATION include/${PROJECT_NAME}/antlr/misc)

