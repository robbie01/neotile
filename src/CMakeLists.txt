find_package(ZLIB REQUIRED)
find_package(SDL2 REQUIRED)
find_package(PNG REQUIRED)

file(GLOB SOURCES *.c)

add_library(neotile STATIC ${SOURCES})

target_include_directories(neotile PUBLIC ${neotile_SOURCE_DIR}/include)

set_target_properties(neotile PROPERTIES C_STANDARD 99 C_EXTENSIONS OFF)
target_link_libraries(neotile m ZLIB::ZLIB PNG::PNG SDL2::SDL2)
