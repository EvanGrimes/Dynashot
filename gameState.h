#ifndef GAME1_GAMESTATE_H
#define GAME1_GAMESTATE_H

#define PLAYER_HOR_SPD 200.0f

#include "raylib.h"
#include "Assets.h"
#include "Map.h"


typedef struct Player {
    Vector2 position;
    float speed;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);

class gameState {
public:
    Map map;
    Player player;
    void tick();
    void render();
    Texture2D getLastAnim();
    int framesCounter = 0;
    int framesSpeed = 8;
    int currentFrame = 0;
    bool Moving;
    int count = 0;
    std::string lastAnim;
    Rectangle playerRect = {  player.position.x , player.position.y + 20, 20, 20};
    void startPlayer() {
        player = {{0, 0}, 0};
        player.position = (Vector2) {Assets::screenWidth/2, Assets::screenHeight/2};
        player.speed = 0;
    }


    void movePlayerCollider(){
        for(count = 0; count < MapReader::mapSize; count++) {
            if (CheckCollisionRecs(map.mapReader.collision[count], playerRect)) {
                if(!CheckCollisionPointRec((Vector2){player.position.x - 1, player.position.y}, map.mapReader.collision[count]))
                {
                    if(lastAnim == "right"){
                        playerRect = {player.position.x + 10, player.position.y + 10, 18, 20};
                    }
                    if(lastAnim == "left"){
                        playerRect = {player.position.x + 10, player.position.y + 10, 18, 20};
                    }
                }
                else{
                    if(lastAnim == "left"){
                        playerRect = {player.position.x + 10, player.position.y + 10, 18, 20};
                    }
                    if(lastAnim == "right"){
                        playerRect = {player.position.x - 10, player.position.y + 10, 18, 20};
                    }
                }
            }
        }
    }

    bool checkCollision() {
        for(count = 0; count < MapReader::mapSize; count++){
            playerRect = { player.position.x + 10, player.position.y + 10, 18, 20 };
            if(CheckCollisionRecs(map.mapReader.collision[count], playerRect)) {
                printf("COLLISION\n");
                return true;
            }
            DrawRectangleRec(map.mapReader.collision[count], RED);
        }
        return false;
    }

    bool checkPausePress(){
        if(IsKeyPressed(KEY_ESCAPE)){
            return true;
        }
        else{
            return false;
        }
    }

    void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta)
    {
        Moving = false;
        if (IsKeyDown(KEY_W)){
            if(!IsKeyDown(KEY_S)) {
                Moving = true;
                    player->position.y -= PLAYER_HOR_SPD * delta;
                    lastAnim = "up";
                if(checkCollision()){
                    player->position.y += PLAYER_HOR_SPD * delta + 5;
                }
                lastAnim = "up";
            }
        }
        if (IsKeyDown(KEY_S)) {
            if(!IsKeyDown(KEY_W)) {
                Moving = true;
                    player->position.y += PLAYER_HOR_SPD * delta;
                    lastAnim = "down";
                if(checkCollision()){
                    player->position.y -= PLAYER_HOR_SPD * delta + 5;
                }

                lastAnim = "down";
            }
        }
        if (IsKeyDown(KEY_A)) {
            if(!IsKeyDown(KEY_D)) {
                Moving = true;
                    player->position.x -= PLAYER_HOR_SPD * delta;
                    lastAnim = "left";
                if(checkCollision()){
                    player->position.x += PLAYER_HOR_SPD * delta + 5;
                }

                lastAnim = "left";
            }
        }

        if (IsKeyDown(KEY_D)) {
            if(!IsKeyDown(KEY_A)) {
                Moving = true;
                player->position.x += PLAYER_HOR_SPD * delta;
                lastAnim = "right";
                if(checkCollision()){
                    player->position.x -= PLAYER_HOR_SPD * delta + 5;
                }
            }
        }

        for (int i = 0; i < envItemsLength; i++)
        {
            EnvItem *ei = envItems + i;
            Vector2 *p = &(player->position);
            if (ei->blocking &&
                ei->rect.x <= p->x &&
                ei->rect.x + ei->rect.width >= p->x &&
                ei->rect.y >= p->y &&
                ei->rect.y < p->y + player->speed*delta)
            {
                player->speed = 0.0f;
                p->y = ei->rect.y;
            }
        }
    }
};



#endif //GAME1_GAMESTATE_H
