cmake_minimum_required(VERSION 3.25)
project(Morpion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Morpion
        main.cpp
        Circle.cpp
        Cross.cpp
        Cursor.cpp
        Elements.cpp
        Game.cpp
        Playground.cpp
        ResourcesManager.cpp
        WindowSettings.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
target_link_libraries(Morpion sfml-graphics sfml-audio)
