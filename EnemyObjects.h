//
// Created by 18149 on 2/28/2021.
//

#ifndef GAME1_ENEMYOBJECTS_H
#define GAME1_ENEMYOBJECTS_H

#endif //GAME1_ENEMYOBJECTS_H

#include <raylib.h>

class EnemyObjects {
    typedef struct Enemy {
        Vector2 position;
        float speed;
        Texture2D sprite;
        Rectangle collision;
    } Enemy;
public:
    int enemyIndex;
    Rectangle enemyCollision[256];
    Enemy enemies[256];

    EnemyObjects();

    void createNewEnemy(Vector2 position, float speed, Texture2D sprite);

    static void drawEnemy(Enemy enemy);

    void moveEnemy(Enemy enemy);
};
