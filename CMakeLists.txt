cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
SET(GCC_COVERAGE_COMPILE_FLAGS "-static-libgcc -static-libstdc++")

project(game1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



add_executable(Dynashot-1.0.0
        Launcher.cpp Assets.cpp Assets.h titleState.cpp titleState.h gameState.cpp gameState.h Game.cpp Game.h controlsState.cpp controlsState.h settingsState.cpp settingsState.h Map.h Map.cpp Worlds.cpp Worlds.h MapReader.cpp MapReader.h Tiles.cpp Tiles.h)
target_link_libraries(Dynashot-1.0.0 PRIVATE raylib)
target_link_libraries(Dynashot-1.0.0 PRIVATE winmm)

target_compile_options(Dynashot-1.0.0 PRIVATE -Wall -Wextra)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
target_include_directories(Dynashot-1.0.0 PRIVATE $PROJECT_DIR/res)
file(COPY res DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/res)
target_link_directories(Dynashot-1.0.0 PRIVATE $PROJECT_DIR/res)