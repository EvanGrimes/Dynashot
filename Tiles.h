//
// Created by 18149 on 2/19/2021.
//

#ifndef GAME1_TILES_H
#define GAME1_TILES_H
#include <raylib.h>
#include <iostream>
#include <string>

struct Tile{
    std::string blockType;
    Rectangle blockCollider;
    //Vector2 pos;
    Texture2D sprite;
    bool solid;
};

#endif //GAME1_TILES_H
