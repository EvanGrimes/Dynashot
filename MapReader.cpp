#include "MapReader.h"
#include <raylib.h>
#include <cstdio>


//Reads map data from a text file. (see res/worlds/test.txt for a example)
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
    UnloadFileText((unsigned char*)(buffer));
}

//Sets the map collision the same way the map is drawn
void MapReader::setMapCollision() {
    destRect.x = destRect.y = 0;
    for(int x = 0; x < 24; ++x ){
        for(int y = 0; y < 24; y++){
            //Mulitiplies the destRect so the collision boxes are on different tile areas
            destRect.x = (float)y * 32;
            destRect.y = (float)x * 32;
            switch(mapTileData[x * 24 + y]) {
                case '0':
                    //Grass
                    break;
                case '1':
                    //Rock
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 3,25, 25};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 3,25, 25};
                    for(auto & temp : collision){
                        if(CheckCollisionRecs(temp, (Rectangle) {collision[count].x - 5, collision[count].x, 25, 28})){
                            collision[count] = {destRect.x + 4, destRect.y + 4,25, 25};
                            break;
                        }

                    }


                    break;
                case '2':
                    //Big Rock
                    break;
                case '3':
                    //Bush
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                    break;

                case '4':
                    //Tall Bush
                    break;
                case '5':
                    //Secret Bush
                    if(count == 0){
                        collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 2, destRect.y + 4 ,25, 25};
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
                        collision[count] = {destRect.x + 4, destRect.y + 3,25, 28};
                        count++;
                        break;
                    }
                    count++;
                    collision[count] = {destRect.x + 4, destRect.y + 3,25, 25};
                    break;
                default:
                    break;
            }
        }
    }
}
