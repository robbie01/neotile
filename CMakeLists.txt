cmake_minimum_required(VERSION 3.16.3)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

project(neotile C)

add_subdirectory(src lib)
add_subdirectory(samples EXCLUDE_FROM_ALL)

install(
    TARGETS neotile
    EXPORT neotile
)
