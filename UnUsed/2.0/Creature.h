//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_CREATURE_H
#define GAME1_CREATURE_H

#include "Entity.h"
#include "Tiles.h"

class Creature {
protected:
    bool collisionWithTile(int x, int y);

public:
    Entity entity;
    Tiles tile;
int health;
float speed;
float xMove, yMove;

int DEFAULT_HEALTH = 10;
float DEFAULT_SPEED = 3.0f;
int DEFAULT_CREATURE_WIDTH = 64;
int DEFAULT_CREATURE_HEIGHT = 64;

    Creature(Handler handler, float x, float y, int width, int height);
    void move();
    void moveX();
    void moveY();
};


#endif //GAME1_CREATURE_H
