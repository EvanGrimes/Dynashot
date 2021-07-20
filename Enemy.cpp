#include "Enemy.h"
#define ENEMY_HOR_SPD 200.00f


void Enemy::render(const Entity& enemy, int maxFrames){
    WalkCycleAninCount++;
    if(WalkCycleAninCount > maxFrames){
        WalkCycleAninCount = 0;
    }

    if(enemy.lastDir == "up"){
        DrawTexture(enemy.EntityWalkUp[WalkCycleAninCount], (int) enemy.enemyCollision.x, (int) enemy.enemyCollision.x, WHITE);
    }

    if(enemy.lastDir == "down"){
        DrawTexture(enemy.EntityWalkDown[WalkCycleAninCount], (int) enemy.enemyCollision.x, (int) enemy.enemyCollision.x, WHITE);
    }

    if(enemy.lastDir == "left"){
        DrawTexture(enemy.EntityWalkLeft[WalkCycleAninCount], (int) enemy.enemyCollision.x, (int) enemy.enemyCollision.x, WHITE);
    }

    if(enemy.lastDir == "right"){
        DrawTexture(enemy.EntityWalkRight[WalkCycleAninCount], (int) enemy.enemyCollision.x, (int) enemy.enemyCollision.x, WHITE);
    }

}



void Entity::die() {

}



bool Enemy::CheckCollision(Entity enemy, /* Rectangle collision,*/ std::string direction) {
    //For-loop so that it can check collision with an array of rectangles for the collision (Rectangles are created in MapReader.cpp
    for(int count = 0; count < MapReader::mapSize; count++){

        //Offsets the enemy collision box (depending on the last direction) so that it will never be inside of a tile
        if(enemy.lastDir == "down"){
            enemy.enemyCollision = { enemy.position.x + 9, enemy.position.y +14, 8, 15 };
        }
        if(enemy.lastDir == "up"){
            enemy.enemyCollision = { enemy.position.x + 9, enemy.position.y + 14, 8, 15 };
        }
        if(enemy.lastDir == "right"){
            enemy.enemyCollision = {enemy.position.x + 9, enemy.position.y + 14, 9, 15};
        }
        if(enemy.lastDir == "left"){
            enemy.enemyCollision = {enemy.position.x + 9, enemy.position.y + 14, 9, 15};
        }
        //Left and down direction collision
        if(enemy.lastDir == "left" || "down") {
            //If it finds collision with the collision rectangles and the enemy rectangle minus 1 pixel
            // (even though it's minus one pixel, it's still in front of the enemy) it will return true
            if (CheckCollisionRecs(mapReader.collision[count],
                                   (Rectangle) {enemy.enemyCollision.x + 1, enemy.enemyCollision.y - 1, enemy.enemyCollision.width,
                                                enemy.enemyCollision.height})) {
                printf("COLLISION\n");
                return true;
            }
        }
        //right and up direction collision
        if(enemy.lastDir == "right" || "up"){
            //If it finds collision with the collision rectangles and the enemy rectangle plus 1 pixel
            // (Plus one pixel is now in front of the enemy because of the opposite direction) it will return true
            if(CheckCollisionRecs(mapReader.collision[count],
                                  (Rectangle){enemy.enemyCollision.x + 1, enemy.enemyCollision.y + 0.1f, enemy.enemyCollision.width, enemy.enemyCollision.height})){
                printf("COLLISION\n");
                return true;
            }
        }
    }
    return false;
}

void Enemy::Walk(Entity enemy, std::string direction) {
    for(auto & x : mapReader.collision) {

        //Enemy Forwards Movement
        if(direction == "up"){
            if(!CheckCollision(enemy, /*x,*/ direction)){
                Moving = true;
                enemy.position.y -= ENEMY_HOR_SPD * delta;
                enemy.lastDir = "up";
            }
            if(CheckCollision(enemy, /*x,*/ direction)) {
                Moving = true;
                enemy.position.y += ENEMY_HOR_SPD * delta;
                enemy.lastDir = "up";
            }
        }

        //Downwards Movement
        if(direction == "down"){
                if(!CheckCollision(enemy, /*x,*/ direction)){
                    Moving = true;
                    enemy.position.y += ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "down";
                }
                if(CheckCollision(enemy, /*x,*/ direction)) {
                    Moving = true;
                    enemy.position.y -= ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "down";
                }
            }
        //Left Movement
        if(direction == "left") {
                if(!CheckCollision(enemy, /*x,*/ direction)){
                    Moving = true;
                    enemy.position.x -= ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "left";
                }
                if(CheckCollision(enemy, /*x,*/ direction)) {
                    Moving = true;
                    enemy.position.x += ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "left";
                }
            }

        //Right Movement
        if(direction == "right"){
                    if(!CheckCollision(enemy, /*x,*/ direction)){
                        Moving = true;
                        enemy.position.x += ENEMY_HOR_SPD * delta;
                        enemy.lastDir = "right";
                    }
                    if(CheckCollision(enemy, /*x,*/ direction)) {
                        Moving = true;
                        enemy.position.x -= ENEMY_HOR_SPD * delta;
                        enemy.lastDir = "right";
                    }
                }
            }
        }

void Enemy::IdleWalk(Entity enemy) {
    WalkCycleRand = GetRandomValue(0, 4);
    switch (WalkCycleRand) {
        case 0:
            //Random Walk Up
            for(auto & x : mapReader.collision) {
                if (!CheckCollision(enemy, /*x,*/ "up")) {
                    Moving = true;
                    enemy.position.y -= ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "up";
                }
                if (CheckCollision(enemy, /*x,*/ "up")) {
                    Moving = true;
                    enemy.position.y += ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "up";
                }
            }
            break;
        case 1:
            //Random Walk Down
            for(auto & x : mapReader.collision) {
                if (!CheckCollision(enemy, /*x,*/ "down")) {
                    if (!CheckCollision(enemy, /*x,*/ "down")) {
                        Moving = true;
                        enemy.position.y += ENEMY_HOR_SPD * delta;
                        enemy.lastDir = "down";
                    }
                    if (CheckCollision(enemy, /*x,*/ "down")) {
                        Moving = true;
                        enemy.position.y -= ENEMY_HOR_SPD * delta;
                        enemy.lastDir = "down";
                    }
                }
            }
            break;
        case 2:
            //Random Walk Left
            for(auto & x : mapReader.collision) {
                if (!CheckCollision(enemy, /*x,*/ "left")) {
                    Moving = true;
                    enemy.position.x -= ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "left";
                }
                if (CheckCollision(enemy, /*x,*/ "left")) {
                    Moving = true;
                    enemy.position.x += ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "left";
                }
            }
            break;
        case 3:
            //Random Walk Right
            for(auto & x : mapReader.collision) {
                if (!CheckCollision(enemy, /*x,*/ "right")) {
                    Moving = true;
                    enemy.position.x += ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "right";
                }
                if (CheckCollision(enemy, /*x,*/ "right")) {
                    Moving = true;
                    enemy.position.x -= ENEMY_HOR_SPD * delta;
                    enemy.lastDir = "right";
                }
            }
            break;
        case 4:
            if(WaitCycle){
                WaitCycleTime();
            }
         break;
    }
}

bool Enemy::WaitCycleTime(){
    WaitCycle = true;
    if(WaitTemp == 0) {
        WaitCycleRand = GetRandomValue(0, 9);
        if (WaitCycleRand == GetRandomValue(0, 3)) {
            WaitCycle = false;
        } else {
            WaitRandomStore = WaitCycleRand;
            WaitTemp = 1;
        }
    }
    if(WaitTemp >= 1){
        if (WaitRandomStore == GetRandomValue(0, 3)) {
            WaitCycle = false;
            WaitTemp = 0;
        }

    }
}

/*void Enemy::tick(Entity enemy, PlayerP player) {
    delta = GetFrameTime();
    if(player.position.x <= enemy.position.x - 10){
        Walk(enemy, "left");

    }
    else if(player.position.x <= enemy.position.x + 10){
        Walk(enemy, "right");
    }
    else if(player.position.y <= enemy.position.y + 10){
        Walk(enemy, "down");
    }
    else if(player.position.y <= enemy.position.y - 10){
        Walk(enemy, "up");
    }
    else{
        IdleWalk(enemy);
    }
} */