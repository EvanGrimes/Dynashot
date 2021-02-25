#ifndef GAME1_MAPREADER_H
#define GAME1_MAPREADER_H

#include <raylib.h>

class MapReader {
public:
    //The map size. Used instead of hard coding every instance of it
    static const int mapSize = 24 * 24;

    //This holds the actual map data in an array.
    //The switch statement is based off of it
    char mapTileData[mapSize] = {0};

    //The actual collision boxes
    Rectangle collision[24 * 24] = {{0, 0, 35, 35}};

    //Used in the for-loop and also to index the collision array
    int count = 0;

    //The functions
    void readMapData();
    void setMapCollision();
private:
    //A destination rectangle so it can use the same math that Map.cpp does
     Rectangle destRect = {0, 0, 0, 0};
};
#endif //GAME1_MAPREADER_H
