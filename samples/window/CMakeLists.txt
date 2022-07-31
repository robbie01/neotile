find_package(SDL2 REQUIRED)

add_library(Window STATIC Window.c GaussianBlur.c)
target_include_directories(Window PUBLIC include)
set_target_properties(neotile PROPERTIES C_STANDARD 99 C_EXTENSIONS OFF)
target_link_libraries(Window neotile SDL2::SDL2)
