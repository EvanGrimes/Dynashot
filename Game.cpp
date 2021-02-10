#include "Game.h"


Camera2D Game::camera;
void Game::loop(){
    int caminitvar = 0;
    int gameinitvar = 0;

while (!WindowShouldClose()){
    BeginDrawing();
    DrawFPS(10,10);
    if(Assets::type == "title"){
        titleState.tick();
    }
    if(Assets::type == "game"){
        if(gameinitvar == 0){
            Assets::unloadTitle();
            Assets::loadGame();
            if(caminitvar == 0){
                Game::camera = { 0 };
                Game::camera.target = (Vector2){ gameState.player.position.x + 20, gameState.player.position.y + 20 };
                Game::camera.offset = (Vector2){ Assets::screenWidth/2, Assets::screenHeight/2 };
                Game::camera.rotation = 0.0f;
                Game::camera.zoom = 1.5f;
                caminitvar += 1;
            }
            gameState.map.mapReader.setMapCollision();
            gameState.startPlayer();

            printf("Game assets inited\n");
            gameinitvar += 1;
        }
        BeginMode2D(camera);
        gameState.tick();

        EndMode2D();
    }
    if(Assets::type == "pause"){

    }
    if(Assets::type == "settings"){
        //ClearBackground(LIME);
        settingsState.tick();
    }
    if(Assets::type == "controls"){
        ClearBackground(BLUE);
        controlsState.tick();

    }
    if(Assets::type == "exit"){
        CloseWindow();
    }

    EndDrawing();
    }
CloseWindow();
}