add_executable(barrel Barrel.c Simon.c)
add_executable(mode7 Mode7.c Sin.c)
add_executable(mode8 Mode8.c)
add_executable(platformer Platformer.c)
add_executable(racer Racer.c Tree.c Actor.c)
add_executable(scaling Scaling.c)
add_executable(shadow Shadow.c)
add_executable(shooter Shooter.c Actor.c Boss.c Enemy.c Explosion.c Ship.c Sin.c)
add_executable(tutorial Tutorial.c)
add_executable(wobble Wobble.c Sin.c)
add_executable(colorcycle ColorCycle.c)
add_executable(benchmark Benchmark.c)
add_executable(supermarioclone SuperMarioClone.c)
add_executable(test_mouse TestMouse.c)
add_executable(forest Forest.c)
add_executable(querylayer QueryLayer.c)

add_executable(test_linescroll test_linescroll.c)
add_executable(test_pivot test_pivot.c)
add_executable(test_pauseanimation test_pauseanimation.c)

add_subdirectory(window)

get_directory_property(execs BUILDSYSTEM_TARGETS)
foreach(exec ${execs})
    set_target_properties(${exec} PROPERTIES C_STANDARD 99 C_EXTENSIONS OFF)
    target_link_libraries(${exec} neotile Window)
endforeach()

find_package(SDL2 REQUIRED)
target_link_libraries(test_mouse SDL2::SDL2)

file(COPY assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
