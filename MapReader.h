#ifndef GAME1_MAPREADER_H
#define GAME1_MAPREADER_H

#include <raylib.h>

class MapReader {
public:
    static const int mapSize = 24 * 24;
    char mapTileData[mapSize] = {0};
    Rectangle collision[24 * 24] = {{0, 0, 35, 35}};
    int count = 0;

    void readMapData();
    void setMapCollision();
private:
     Rectangle destRect = {0, 0, 0, 0};
};
#endif //GAME1_MAPREADER_H
