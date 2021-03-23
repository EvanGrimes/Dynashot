#ifndef GAME1_GAME_H
#define GAME1_GAME_H
#include <raylib.h>
#include "titleState.h"
#include "gameState.h"
#include "settingsState.h"
#include "controlsState.h"
#include "pauseState.h"

//It's just random leftover unused code from a LoadMap function
/*void Map::LoadMap(int arr[20][25]) {
    for(row = 0; row < 20; row++){
        for (column = 0; column <25; column++){
            map[row][column] = arr[row][column];
        }
    }
}*/


class Game {
public:
        //The game camera
        static Camera2D camera;
        //The state loaded when game first starts
        titleState titleState;
        //The actual state where you can play the game
        gameState gameState;
        //A menu that shows all the controls (May in the future add the ability to change controls)
        controlsState controlsState;
        //A state where you can change setting (WIP)
        settingsState settingsState;
        //Pause menu state
        pauseState pauseState;

        //The main game loop
        void loop();
};


#endif //GAME1_GAME_H
