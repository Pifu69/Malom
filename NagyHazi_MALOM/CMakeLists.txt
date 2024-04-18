cmake_minimum_required(VERSION 3.26)
project(NagyHazi_MALOM)

set(CMAKE_CXX_STANDARD 17)

add_executable(NagyHazi_MALOM
        piece.cpp
        player.cpp
        main.cpp
        map.cpp
        shell.cpp
        point.cpp
        position.cpp
        game.cpp
        app.cpp
        controller.cpp
        controller.h
        game_mechanic.cpp
        game_mechanic.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include/SFML)
target_link_libraries(NagyHazi_MALOM sfml-system sfml-window sfml-graphics sfml-audio)

