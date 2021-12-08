cmake_minimum_required(VERSION 3.22.0)

if ( ${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR} )
    message( FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

project(neotile C)

set(CMAKE_INSTALL_LIBDIR lib64)

add_subdirectory(src lib)
add_subdirectory(samples EXCLUDE_FROM_ALL)

set_target_properties(neotile PROPERTIES PUBLIC_HEADER "include/Tilengine.h")
install(
    TARGETS neotile
    EXPORT neotile
)
install (
    EXPORT neotile
    DESTINATION lib64/neotile
)