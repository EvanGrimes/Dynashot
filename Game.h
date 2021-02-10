#ifndef GAME1_GAME_H
#define GAME1_GAME_H
#include <raylib.h>
#include "titleState.h"
#include "gameState.h"
#include "settingsState.h"
#include "controlsState.h"

/*void Map::LoadMap(int arr[20][25]) {
    for(row = 0; row < 20; row++){
        for (column = 0; column <25; column++){
            map[row][column] = arr[row][column];
        }
    }
}*/


class Game {
public:
        static Camera2D camera;
        titleState titleState;
        gameState gameState;
        controlsState controlsState;
        settingsState settingsState;


        void loop();
};


#endif //GAME1_GAME_H
