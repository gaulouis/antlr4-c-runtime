project(antlr4-c)
cmake_minimum_required(VERSION 2.8)

set (ANTLR_VERSION_MAJOR 4)
set (ANTLR_VERSION_MINOR 5)
set (ANTLR_VERSION_MICRO 3)

# rename ENABLE_TRACE and use RELEASE_DEBUG for object.name
option (ENABLE_DEBUG
        "Enable debug trace used by ANTLR_DEBUG env" ON)

add_subdirectory (lib)
add_subdirectory (src)



# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/docs/doxygen.config ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen.config @ONLY)
add_custom_target(doc
${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/docs/doxygen.config
WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
COMMENT "Generating API documentation with Doxygen" VERBATIM
)
endif(DOXYGEN_FOUND)

