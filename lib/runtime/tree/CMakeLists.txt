
add_library (${PROJECT_NAME}-runtime-tree
    tree.c
)
include_directories ("${PROJECT_BINARY_DIR}/lib/runtime")

if(ENABLE_DEBUG)
  add_definitions(-DENABLE_DEBUG=1)
endif()

install (FILES
		tree.h
	DESTINATION include/${PROJECT_NAME}/antlr/tree)

