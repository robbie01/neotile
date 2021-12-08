find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)
find_package(PNG REQUIRED)

file(GLOB SOURCES *.c)
list(REMOVE_ITEM SOURCES Test.c)

include_directories(${neotile_SOURCE_DIR}/include)

add_library(neotile STATIC ${SOURCES})
set_target_properties(neotile PROPERTIES C_STANDARD 99)
target_link_libraries(neotile m ZLIB::ZLIB PNG::PNG SDL2::SDL2)
