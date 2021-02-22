#include "MapReader.h"
#include <raylib.h>
#include <cstdio>



void MapReader::readMapData() {
    char *buffer = LoadFileText("../res/worlds/test.txt");
    char *p = buffer;
    int x = 0;
    while (*p != '\0') {
        if (*p != '\n') {
                if (x >= mapSize) {
                    printf("MAP TOO BIG");
                    break;
            }
            mapTileData[x++] = *p;
        }
        ++p;
    }
    UnloadFileText(reinterpret_cast<unsigned char *>(buffer));
}

void MapReader::setMapCollision() {
    destRect.x = destRect.y = 0;
    for(int x = 0; x < 24; ++x ){
        for(int y = 0; y < 24; y++){
            destRect.x = y * 32;
            destRect.y = x * 32;
            switch(mapTileData[x * 24 + y]) {
                case '0':
                    //Grass
                    break;
                case '1':
                    //Rock
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                    break;
                case '2':
                    //Big Rock
                    break;
                case '3':
                    //Bush
                    break;
                case '4':
                    //Tall Bush
                    break;
                case '5':
                    //Secret Bush
                    break;
                case '6':
                    //Sign
                    break;
                case '7':
                    //Tree?
                    break;
                case '8':
                    //Secret Tree?
                    break;
                case '9':
                    //Dead Tree?

                    break;
                case 'r':
                    //Tree Trunk
                    break;
                case 'w':
                    //Water
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                    break;
                default:
                    break;
            }
        }
    }


}
