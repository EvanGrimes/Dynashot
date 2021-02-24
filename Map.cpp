#include "Map.h"


int lvlDef[20][25] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 9, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 9, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0,  11, 11, 11, 11, 11, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 11, 11, 11, 11, 11, 11, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  11, 11, 11, 11, 11, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  0,  0,  0,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  2,  2,  2,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  2,  3,  2,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0,  2,  2,  2,  0,  0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

Map::Map(){
    mapReader.readMapData();
    sourceRec.x = 0;
    sourceRec.y = 0;
    sourceRec.width = destRect.width = 32;
    sourceRec.height = destRect.height = 32;
    destRect.x = destRect.y = 0;

}

void Map::LoadMap(int arr[25][25]) {
    for(int row = 0; row < 25; row++){
        for (int column = 0; column <25; column++){
            map[row][column] = arr[row][column];
        }
    }
}

void Map::DrawMap() {
    for (int x = 0; x < 24; ++x) {
        for (int y = 0; y < 24; y++) {
            destRect.x = y * 32;
            destRect.y = x * 32;


            switch (mapReader.mapTileData[x * 24 + y]) {
                case '0':
                    DrawTextureRec(Assets::grass, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '1':
                    DrawTextureRec(Assets::rock, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '2':

                    DrawTextureRec(Assets::rockBig, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '3':
                    DrawTextureRec(Assets::bush, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '4':
                    DrawTextureRec(Assets::bushTall, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '5':
                    DrawTextureRec(Assets::bushSecret, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '6':
                    DrawTextureRec(Assets::sign, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '7':
                    DrawTextureRec(Assets::tree, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '8':
                    DrawTextureRec(Assets::treeSecret, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case '9':
                    DrawTextureRec(Assets::treeDead, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 10:
                    DrawTextureRec(Assets::treeTrunk, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                case 'w':

                    DrawTextureRec(Assets::water, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
                default:
                    //DrawTextureRec(Assets::grass, sourceRec, (Vector2) {destRect.x, destRect.y}, WHITE);
                    break;
            }
        }
    }
}




    /*for(int x = 0; x < 25; x++){
        for (int y = 0; y <25; y++){
            type = map[x][y];

            destRect.x = y * 32;
            destRect.y = x * 32;

            switch (type){
                case 0:
                    DrawTextureRec(Assets::grass, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 1:
                    DrawTextureRec(Assets::rock, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 2:
                    DrawTextureRec(Assets::rockBig, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 3:
                    DrawTextureRec(Assets::bush, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 4:
                    DrawTextureRec(Assets::bushTall, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 5:
                    DrawTextureRec(Assets::bushSecret, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 6:
                    DrawTextureRec(Assets::sign, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 7:
                    DrawTextureRec(Assets::tree, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 8:
                    DrawTextureRec(Assets::treeSecret, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 9:
                    DrawTextureRec(Assets::treeDead, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 10:
                    DrawTextureRec(Assets::treeTrunk, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
                case 11:
                    DrawTextureRec(Assets::water, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    //count++ ;
                    //collision[count] = {destRect.x, destRect.y, 32, 32};
                    break;
                default:
                    //DrawTextureRec(Assets::grass, sourceRec, (Vector2){destRect.x, destRect.y}, WHITE);
                    break;
            }

        }
    }*/




