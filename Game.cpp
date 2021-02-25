#include "Game.h"


Camera2D Game::camera;
void Game::loop(){
    //Just some variables so that it can initialize the game objects only once and have that happen when the loop is called
    int caminitvar = 0;
    int gameinitvar = 0;

while (!WindowShouldClose()){
    //Starts drawing
    BeginDrawing();
    //The title screen loop (Assets::type is just a string that has the state name)
    if(Assets::type == "title"){
        //Plays some title screen music (WIP)
        PlayMusicStream(Assets::titleSong);
        //Starts the title state loop
        titleState.tick();
    }

    //Starts the actual game once the start button has been pressed
    if(Assets::type == "game"){
        if(gameinitvar == 0){
            //Loads the game assets like tiles and such (only happens once)
            Assets::unloadTitle();

            //Unloaded the title assets (only happens once)
            Assets::loadGame();

            //Initializes the camera (only happens once)
            if(caminitvar == 0){
                //Sets default game camera parameters
                Game::camera = { {0, 0}, {0, 0}, 0.0f, 0 };
                //Sets the target of the player (offset by 20px)
                Game::camera.target = (Vector2){ gameState.player.position.x + 20, gameState.player.position.y + 20 };
                //Sets the offset from the screen
                Game::camera.offset = (Vector2){ Assets::screenWidth/2.0, Assets::screenHeight/2.0 };
                //Sets the zoom
                Game::camera.zoom = 1.5f;
                //stops the camera from initializing every frame
                caminitvar += 1;
            }

            //Sets the map collision
            gameState.map.mapReader.setMapCollision();

            //Initializes the play (function in gameState.h
            gameState.startPlayer();

            //Just a message to show that everything initialized correctly
            printf("Game assets inited\n");

            //Stops the game assets from being loaded every frame
            gameinitvar += 1;
        }
        //Starts a 2D game mode (needed for the camera to work
        BeginMode2D(camera);

        //Runs all the game logic and rendering
        gameState.tick();

        //Stops the 2D mode.
        EndMode2D();

        //Draws the FPS at the left corner of the screen (can only be drawn correctly after EndMode2D() is called
        DrawFPS(10, 10);
    }

    //Starts the pause menu loop (still WIP)
    if(Assets::type == "pause"){
        ClearBackground(RAYWHITE);
    }
    //Starts the settings menu loop (also still WIP)
    if(Assets::type == "settings"){
        //ClearBackground(LIME);
        settingsState.tick();
    }
    //Starts the controls menu loop
    if(Assets::type == "controls"){
        ClearBackground(BLUE);
        controlsState.tick();

    }
    //Closes the game
    if(Assets::type == "exit"){
        CloseWindow();
    }

    EndDrawing();
    }
    //If window is closed, it checks if the game assets were initialized or not, and unloaded whatever needs to be
    //If the game assets aren't initialized, it unloads the title screen assets
    if(gameinitvar == 0){
        Assets::unloadTitle();
    }
    //If the game assets are initialized, they are unloaded. The title screen assets were unloaded when the game assets were
    if(gameinitvar == 1){
        Assets::unloadGame();
    }
    //Closes the window
    CloseWindow();
}