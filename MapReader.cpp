#include "MapReader.h"
#include <raylib.h>
#include <stdio.h>

void MapReader::readMapData() {
    char *buffer = LoadFileText("../res/worlds/test.txt");
    char *p = buffer;
    int x = 0;
    while (*p != '\0') {
        if (*p != '\n') {
                if (x >= mapSize) {
                    printf("MAP TO BIG");
                    break;
            }
            mapTileData[x++] = *p;
        }
        ++p;
    }
    UnloadFileText(reinterpret_cast<unsigned char *>(buffer));
}

void MapReader::setMapCollision() {
    for(int x = 0; x < 23; ++x ){
        for(int y = 0; y < 23; y++){
            destRect.x = y * 32;
            destRect.y = x * 32;
            switch(mapTileData[x * 24 + y]) {
                case '0':
                    //Grass
                    break;
                case '1':
                    //Rock
                    count++;
                    if(count >= MapReader::mapSize){
                        printf("TOO BIG");
                        break;
                    }
                    printf("%d\n", count);
                    collision[count] = {destRect.x, destRect.y ,31, 29};

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
                case 10:
                    //Tree Trunk
                    break;
                case 'w':
                    //Water
                    count++;
                    if(count >= MapReader::mapSize){
                        //printf("TOO BIG");
                        //break;
                    }
                    printf("%d\n", count);
                    collision[count] = {destRect.x, destRect.y ,31, 29};
                    printf("X: %f\n Y: %f\n", collision[count].x, collision[count].y);
                    //count++ ;
                    //collision[count] = {destRect.x, destRect.y, 32, 32};
                    break;
                default:
                    break;
            }
        }
    }


}
