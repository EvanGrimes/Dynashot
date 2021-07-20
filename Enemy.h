//
// Created by 18149 on 5/31/2021.
//

#ifndef GAME1_ENEMY_H
#define GAME1_ENEMY_H

#include "MapReader.h"

typedef struct PlayerP {
    Vector2 position;
    float speed;
    static void die();
} PlayerP;

struct Entity{
    Vector2 position;
    float speed;
    static void die();
    std::string lastDir;
    Rectangle enemyCollision;
    Texture2D EntityWalkUp[4];
    Texture2D EntityWalkDown[4];
    Texture2D EntityWalkLeft[4];
    Texture2D EntityWalkRight[4];
    Texture2D EntityIdle[4];
};

class Enemy {
public:
    float delta;
    bool Moving = false;
    MapReader mapReader;


int WalkCycleAninCount;
int WalkCycleRand;
int WaitCycleRand;
int WaitTemp = 0;
int WaitRandomStore;
bool WaitCycle;


//void tick(Entity enemy, PlayerP player);
//void render();
void Walk(Entity enemy, std::string direction);
void IdleWalk(Entity enemy);
void render(const Entity& enemy, int maxFrames);
bool WaitCycleTime();
bool CheckCollision(Entity enemy, /* Rectangle collision,*/ std::string direction );


};


#endif //GAME1_ENEMY_H
