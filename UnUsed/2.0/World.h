//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_WORLD_H
#define GAME1_WORLD_H

#include <iostream>
#include "Tiles.h"
#include "EntityManager.h"
#include "Handler.h"
using namespace std;


class World {
private Handler handler;
public:
int WIDTH, HEIGHT;
Tiles tiles;
EntityManager entityManager;
    //public Enemy enemy;
    //public int enemyTick = 0;
    World(Handler handler, std::string path);
    void tick();
    void render();
    Tiles getTile(int x, int y);
    void loadWorld(std::string path);
private:
int spawnX, spawnY;
int tiles[];



};


#endif //GAME1_WORLD_H
