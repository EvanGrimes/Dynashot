//
// Created by 18149 on 1/17/2021.
//

#ifndef GAME1_MAP_H
#define GAME1_MAP_H
#include "Assets.h"
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
    // USE THIS ONE JUST IN CASE void LoadMap(int arr[25][25]);
    void DrawMap();
private:
    Rectangle sourceRec = {0, 0, 0, 0}, destRect = {0, 0, 0, 0};

    //int map[25][25];
};
#endif //GAME1_MAP_H
