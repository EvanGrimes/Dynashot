//
// Created by 18149 on 1/17/2021.
//

#ifndef GAME1_MAP_H
#define GAME1_MAP_H
#include "Assets.h"
#include "Worlds.h"
#include <fstream>
#include <raylib.h>
#include <string>
#include <sstream>
#include "MapReader.h"

class Map{
public:

    Map();
    //~Map();
    MapReader mapReader;
    //void LoadMap(std::string path, int sizeX, int sizeY);
    void LoadMap(int arr[25][25]);
    void DrawMap();
private:
    Rectangle sourceRec, destRect;

    int map[25][25];
};
#endif //GAME1_MAP_H
