cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set (CMAKE_CXX_FLAGS "-static-libgcc -static-libstdc++ -static")

project(game1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Dynashot-1.0.0
        Launcher.cpp Assets.cpp Assets.h titleState.cpp titleState.h gameState.cpp
        gameState.h Game.cpp Game.h controlsState.cpp controlsState.h settingsState.cpp
        settingsState.h Map.h Map.cpp MapReader.cpp MapReader.h pauseState.cpp pauseState.h Enemy.cpp Enemy.h Mole.cpp Mole.h)
target_link_libraries(Dynashot-1.0.0 PRIVATE raylib)
target_link_libraries(Dynashot-1.0.0 PRIVATE winmm)

target_compile_options(Dynashot-1.0.0 PRIVATE -Wall -Wextra)
target_link_options(Dynashot-1.0.0 PRIVATE -static-libgcc)
target_link_options(Dynashot-1.0.0 PRIVATE -static-libstdc++)