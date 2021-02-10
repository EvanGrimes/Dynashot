//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_HANDLER_H
#define GAME1_HANDLER_H


#include "World.h"
#include "Game.h"


class Handler {
public:
    Game game;
    World world;
    Handler(Game game);
    Camera2D getGameCamera();
    int getWidth();
    int getHeight();
    Game getGame();
    World getWorld();
    void setWorld(World world);

};


#endif //GAME1_HANDLER_H
