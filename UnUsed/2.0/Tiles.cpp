//
// Created by 18149 on 1/13/2021.
//

#include "Tiles.h"
#include <raylib.h>
    //Static Stuff

static Tiles::Tiles[256] tiles;
//Tile grassTile = new GrassTile(1);
//Tile rockTile = new RockTile(2);
//Tile bushTile = new BushTile(3);
//Tile treeTile = new TreeTile(4);
//Tile tree2Tile = new SecretTree(5);
//Tile secretBushTile = new SecretBush(6);

    //Class

int TILEWIDTH = 64, TILEHEIGHT = 64;

static Texture2D texture;
int id;

Tiles::Tiles(Texture2D texture, int id){
        Tiles::texture = texture;
        Tiles::id = id;

        Tiles::tiles[id] = Tiles::tiles;
    }

void Tiles::tick(){

    }

void Tiles::render(int x, int y){
        BeginDrawing();
        DrawTexture(texture, x, y, RAYWHITE);
        EndDrawing();
    }

bool Tiles::isSolid(){
        return false;
    }


