//
// Created by 18149 on 2/8/2021.
//

#ifndef GAME1_MAPREADER_H
#define GAME1_MAPREADER_H

#include <raylib.h>



class MapReader {
public:
    static const int mapSize = 24 * 24;
    char mapTileData[mapSize] = {0};
    Rectangle collision[24 * 24];
    int count = 0;

    void readMapData();
    void setMapCollision();

private:
    Rectangle sourceRec, destRect;
};


#endif //GAME1_MAPREADER_H
