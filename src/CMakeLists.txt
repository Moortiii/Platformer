cmake_minimum_required(VERSION 3.12)
project(platformer)

set(CMAKE_CXX_STANDARD 14)

add_executable(platformer main.cpp objects/graphics_object/graphics_object.cpp objects/graphics_object/graphics_object.h objects/hero/hero.cpp objects/hero/hero.h game/game.cpp game/game.h settings/config.cpp settings/config.h gamestate/gamestate.cpp gamestate/gamestate.h)

target_link_libraries(platformer sfml-graphics sfml-system sfml-window)