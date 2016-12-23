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
