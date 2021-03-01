#include "EnemyAI.h"
#include "EnemyObjects.h"

EnemyObjects::EnemyObjects() {
    enemies->speed = 0;
    enemies->position = (Vector2){0, 0};

    enemyCollision->height  = 0;
    enemyCollision->width = 0;
    enemyCollision->x = 0;
    enemyCollision->y = 0;
}

void EnemyObjects::createNewEnemy(Vector2 position, float speed, Texture2D sprite) {
    if (enemyIndex == 0) {
        enemies[enemyIndex].position = position;
        enemies[enemyIndex].speed = speed;
        enemies[enemyIndex].collision = enemyCollision[enemyIndex];
        enemies[enemyIndex].sprite = sprite;
        enemyIndex++;
    }
    else {
        enemyIndex++;
        enemies[enemyIndex].position = position;
        enemies[enemyIndex].speed = speed;
        enemies[enemyIndex].collision = enemyCollision[enemyIndex];
        enemies[enemyIndex].sprite = sprite;
    }
}

void EnemyObjects::drawEnemy(Enemy enemy) {
    DrawTexture(enemy.sprite, (int)enemy.collision.x, (int)enemy.collision.y, WHITE);
}
