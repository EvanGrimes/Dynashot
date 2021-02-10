//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_TILES_H
#define GAME1_TILES_H

#include <raylib.h>


class Tiles {
public:
    static Tiles tiles[256];
 //static Tiles grassTile = new GrassTile(1);
 //static Tiles rockTile = new RockTile(2);
 //static Tiles bushTile = new BushTile(3);
 //static Tiles treeTile = new TreeTile(4);
 //static Tiles tree2Tile = new SecretTree(5);
 //static Tiles secretBushTile = new SecretBush(6);
 static Texture2D texture;

 int TILEWIDTH = 64, TILEHEIGHT = 64;

 int id;

    Tiles(Texture2D texture, int id);

    void tick();

    void render(int x, int y);

    bool isSolid();



};


#endif //GAME1_TILES_H
