#include "gameState.h"
#include "Game.h"
#include "MapReader.h"


EnvItem envItems[] = {
{{0,   0,   1000, 400}, 0, LIGHTGRAY},
{{0,   400, 1000, 200}, 1, GRAY},
{{300, 200, 400,  10},  1, GRAY},
{{250, 300, 100,  10},  1, GRAY},
{{650, 300, 100,  10},  1, GRAY}
};


int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

gameState gameState;
//MapReader mapReader;



void gameState::tick() {
    playerRect = { player.position.x, player.position.y, 40, 40 };
    float deltaTime = GetFrameTime();
    framesCounter++;
    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;
    }
    //if(!checkCollision()){
        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);
    //}
    //else{

    //}

    Game::camera.target.x = player.position.x;
    Game::camera.target.y = player.position.y;
    render();

}

void gameState::render() {
    ClearBackground(WHITE);
    map.DrawMap();
    DrawTexture(getLastAnim(), playerRect.x, playerRect.y, WHITE);
}

Texture2D gameState::getLastAnim(){
    if(Moving) {
        if (lastAnim == "up") {
            return Assets::player_up[currentFrame];
        }
        if (lastAnim == "down") {
            return Assets::player_down[currentFrame];
        }
        if (lastAnim == "left") {
            return Assets::player_left[currentFrame];
        }
        if (lastAnim == "right") {
            return Assets::player_right[currentFrame];
        }
    }
    else {
        if (lastAnim == "up") {
            return Assets::player_idle_up;
        }
        if (lastAnim == "down") {
            return Assets::player_idle_down;
        }
        if (lastAnim == "left") {
            return Assets::player_idle_right;
        }
        if (lastAnim == "right") {
            return Assets::player_idle_left;
        }
        else{
            return Assets::player_idle_down;
        }
    }
    return Assets::player_idle_down;
}




