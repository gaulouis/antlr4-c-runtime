
add_library (${PROJECT_NAME}-runtime-misc
	object.c
	type.c)
include_directories ("${PROJECT_BINARY_DIR}/lib/runtime")
target_compile_definitions(${PROJECT_NAME}-runtime-misc PRIVATE ENABLE_DEBUG=1 BAR=1)

install (FILES
		macro.h
		type.h
		object.h
	DESTINATION include/${PROJECT_NAME}/antlr/misc)

