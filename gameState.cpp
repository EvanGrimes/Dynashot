#include "gameState.h"
#include "Game.h"

//Sets an envItem (Don't really know what those are for to be honest)
EnvItem envItems[] = {
{{0,   0,   1000, 400}, 0, /*LIGHTGRAY*/},
{{0,   400, 1000, 200}, 1, /*GRAY*/},
{{300, 200, 400,  10},  1, /*GRAY*/},
{{250, 300, 100,  10},  1, /*GRAY*/},
{{650, 300, 100,  10},  1, /*GRAY*/}
};


int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

void gameState::tick() {
    //Seeing if esc was pressed to pause the game
    if(checkPausePress()){
        printf("PAUSE\n");
        Assets::type = "pause";
    }

    //Advancing the animation frame counter
    float deltaTime = GetFrameTime();
    framesCounter++;
    if (framesCounter >= (60/framesSpeed))
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame > 5) currentFrame = 0;
    }

    //Checking for player movement
    UpdatePlayer(&player, envItems, envItemsLength, deltaTime);

    //Centering camera on the player
    Game::camera.target.x = player.position.x;
    Game::camera.target.y = player.position.y;
    //Drawing
    render();
}

void gameState::render() {
    //Clears screen so you don't see previous frames
    ClearBackground(WHITE);

    //Draws the map (Function in Map.cpp)
    map.DrawMap();
    //Draws the player collision box for debug reasons :)
    DrawRectangleRec(playerRect, BLUE);
    //Draws the player with the last animation (see the function below) and the index of the current frame (see function above)
    DrawTexture(getLastAnim(), (int)player.position.x, (int)player.position.y, WHITE);
}

Texture2D gameState::getLastAnim() const{
    //Moving is only set true if w, a, s, or d is pressed
    if(Moving) {
        //lastAnim is a string in gameState.h that is set in UpdatePlayer.
        if (lastAnim == "up") {
            //Returns up animation with index of the current frame (set in the `tick` function)
            return Assets::player_up[currentFrame];
        }
        if (lastAnim == "down") {
            //Returns down animation with index of the current frame (set in the `tick` function)
            return Assets::player_down[currentFrame];
        }
        if (lastAnim == "left") {
            //Returns left animation with index of the current frame (set in the `tick` function)
            return Assets::player_left[currentFrame];
        }
        if (lastAnim == "right") {
            //Returns right animation with index of the current frame (set in the `tick` function)
            return Assets::player_right[currentFrame];
        }
    }
    //The else is for the idle animations
    else {
        if (lastAnim == "up") {
            //Returns the idle up animation
            return Assets::player_idle_up;
        }
        if (lastAnim == "down") {
            //Returns the idle down animation
            return Assets::player_idle_down;
        }
        if (lastAnim == "left") {
            //Returns the idle left animation
            return Assets::player_idle_right;
        }
        if (lastAnim == "right") {
            //Returns the idle right animation
            return Assets::player_idle_left;
        }
        else{
            //When game starts and has yet to see a key press/player movement direction, it automatically returns the idle down animation
            return Assets::player_idle_down;
        }
    }
    //In case something goes wrong here, this is just a default return that gives the idle down animation
    return Assets::player_idle_down;
}




