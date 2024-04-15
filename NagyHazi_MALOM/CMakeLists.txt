cmake_minimum_required(VERSION 3.26)
project(NagyHazi_MALOM)

set(CMAKE_CXX_STANDARD 17)

add_executable(NagyHazi_MALOM
        piece.cpp
        piece.h
        player.cpp
        player.h
        name.cpp
        name.h
        main.cpp
        map.cpp
        map.h
        shell.cpp
        shell.h
        point.cpp
        point.h
        colour.h
        edge_point.cpp
        edge_point.h
        corner_point.cpp
        corner_point.h
        position.cpp
        position.h
        game.cpp
        game.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include/SFML)
target_link_libraries(NagyHazi_MALOM sfml-system sfml-window sfml-graphics sfml-audio)

