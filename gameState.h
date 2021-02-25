#ifndef GAME1_GAMESTATE_H
#define GAME1_GAMESTATE_H

#define PLAYER_HOR_SPD 200.0f

#include "raylib.h"
#include "Assets.h"
#include "Map.h"

//The player type. Just holds it position and speed
typedef struct Player {
    Vector2 position;
    float speed;
} Player;

//EnvItem type. Don't really know what it does or why it's here
typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    //Color color;
} EnvItem;


class gameState {
public:
    //The map object. Used for drawing the map, loading the map, and collision detection
    Map map;

    //The player. Wouldn't really be a game without a player
    Player player;

    //tick() is the actual game logic
    void tick();

    //Render just draws everything needed in the game state
    void render();

    //Gets the needed animation from a string set in UpdatePlayer()
    [[nodiscard]] Texture2D getLastAnim() const;

    //A frame counter for animation cycles
    int framesCounter = 0;

    //Animation speed
    int framesSpeed = 8;

    //A frame counter to use to increment framesCounter
    int currentFrame = 0;

    //If set true, it plays the respective walking animation, if false, it shows the idle animation
    bool Moving;

    //Used for checking the collision
    int count = 0;
    //This holds what direction was last traveled in so it can play the correct animation
    std::string lastAnim;

    //The player collision box
    Rectangle playerRect = {  player.position.x , player.position.y + 20, 20, 20};

    //Initializes all fields of the player
    void startPlayer() {
        //Just zeros out all parameters
        player = {{0, 0}, 0};

        //Sets the player position to the center of the screen
        player.position = (Vector2) {(float)Assets::screenWidth/2, (float)Assets::screenHeight/2};

        //Sets the player speed to 0
        player.speed = 0;
    }


    //Unused code to account for collision
    /*void movePlayerCollider(){
        for(count = 0; count < MapReader::mapSize; count++) {
            if (CheckCollisionRecs(map.mapReader.collision[count], playerRect)) {
                if(!CheckCollisionPointRec((Vector2){player.position.x - 1, player.position.y}, map.mapReader.collision[count]))
                {
                    if(lastAnim == "right"){
                        playerRect = {player.position.x + 20, player.position.y + 10, 18, 20};
                    }
                    if(lastAnim == "left"){
                        playerRect = {player.position.x + 10, player.position.y + 10, 18, 20};
                    }
                }
                //else{
                //    if(lastAnim == "left"){
                //        playerRect = {player.position.x + 10, player.position.y + 10, 18, 20};
                //    }
                //    if(lastAnim == "right"){
                //        playerRect = {player.position.x - 10, player.position.y + 10, 18, 20};
                //    }
                //}
            }
        }
    }*/

    //Old collision detection
    /*bool checkCollision() {
        for(count = 0; count < MapReader::mapSize; count++){
            //playerRect = { player.position.x + 10, player.position.y + 10, 18, 20 };

            if(CheckCollisionRecs(map.mapReader.collision[count], playerRect)) {
                printf("COLLISION\n");
                return true;
            }
            DrawRectangleRec(map.mapReader.collision[count], RED);
        }
        return false;
    }*/

    //Collision detection. Called checkCollisionFuture because it checks for collision 1px in front of the player so that you will not walk into the block
    //Will only be called every time the player moves / a movement key is pressed
    bool checkCollisionFuture() {

        //For-loop so that it can check collision with an array of rectangles for the collision (Rectangles are created in MapReader.cpp
        for(count = 0; count < MapReader::mapSize; count++){

            //Offsets the player collision box (depending on the last direction) so that it will never be inside of a tile
            if(lastAnim == "down"){
                playerRect = { player.position.x + 9, player.position.y +14, 8, 15 };
            }
            if(lastAnim == "up"){
                playerRect = { player.position.x + 9, player.position.y + 14, 8, 15 };
            }
            if(lastAnim == "right"){
                playerRect = {player.position.x + 9, player.position.y + 14, 9, 15};
            }
            if(lastAnim == "left"){
                playerRect = {player.position.x + 11, player.position.y + 14, 9, 15};
            }
            //Left and down direction collision
                if(lastAnim == "left" || "down") {
                    //If it finds collision with the collision rectangles and the player rectangle minus 1 pixel
                    // (even though it's minus one pixel, it's still in front of the player) it will return true
                    if (CheckCollisionRecs(map.mapReader.collision[count],
                                           (Rectangle) {playerRect.x - 1, playerRect.y - 1, playerRect.width,
                                                        playerRect.height})) {
                        printf("COLLISION\n");
                        return true;
                    }
                }
            //right and up direction collision
                if(lastAnim == "right" || "up"){
                    //If it finds collision with the collision rectangles and the player rectangle plus 1 pixel
                    // (Plus one pixel is now in front of the player because of the opposite direction) it will return true
                   if(CheckCollisionRecs(map.mapReader.collision[count], (Rectangle){playerRect.x + 1, playerRect.y + 0.1f, playerRect.width, playerRect.height})){
                            printf("COLLISION\n");
                            return true;
                        }
                }

                //Draws the tiles collision box for debug reasons
                DrawRectangleRec(map.mapReader.collision[count], RED);
            }
            return false;
        }
        //Checks if escape was pressed and returns true if it was
    static bool checkPausePress(){
        if(IsKeyPressed(KEY_ESCAPE)){
            return true;
        }
        else{
            return false;
        }
    }

    //Checks the player movement and also calls the collision detection
    void UpdatePlayer(Player *playerP, EnvItem *envItems, int envItemsLength, float delta)
    {

        //Sets moving to false so that when not moving, the idle animations play
        Moving = false;

        //Checks for up first
        if (IsKeyDown(KEY_W)){

            //This is just for some animation reasons, every direction does this against the opposite direction.
            // Just makes the correct correct animation play
            if(!IsKeyDown(KEY_S)) {

                //If the collision detection returns false, it will move the player forwards
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y -= PLAYER_HOR_SPD * delta;

                    //Makes the last direction "up" so that it will play the moving / idle up animation
                    lastAnim = "up";
                }

                //If it returns true, it moves the player backward so that you don't go into the tile
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y += PLAYER_HOR_SPD * delta;
                }


                //Unused movement code
                //if(checkCollision()){
                //// /   player->position.y += PLAYER_HOR_SPD * delta + 5;
                ///}

                //Makes the last direction "up" so that it will play the moving / idle up animation
                //This is here only in case the collision returns ture
                lastAnim = "up";
            }
        }

        //Checks for downwards movement
        if (IsKeyDown(KEY_S)) {

            //This is just for some animation reasons, every direction does this against the opposite direction.
            // Just makes the correct correct animation play
            if(!IsKeyDown(KEY_W)) {

                //If the collision detection returns false, it will move the player forwards
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y += PLAYER_HOR_SPD * delta;
                    lastAnim = "down";
                }

                //If it returns true, it moves the player backward so that you don't go into the tile
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.y -= PLAYER_HOR_SPD * delta;
                }

                //Unused movement code
                //if(checkCollision()){
                //    player->position.y -= PLAYER_HOR_SPD * delta + 5;
                //}

                //Makes the last direction "down" so that it will play the moving / idle down animation
                //This is here only in case the collision returns ture
                lastAnim = "down";
            }
        }

        //Checks for movement left
        if (IsKeyDown(KEY_A)) {

            //This is just for some animation reasons, every direction does this against the opposite direction.
            // Just makes the correct correct animation play
            if(!IsKeyDown(KEY_D)) {

                //If the collision detection returns false, it will move the player forwards
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x -= PLAYER_HOR_SPD * delta;
                    lastAnim = "left";
                }

                //If it returns true, it moves the player backward so that you don't go into the tile
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x += PLAYER_HOR_SPD * delta;
                }

                //Unused movement code
                ///if(checkCollision()){
               //     player->position.x += PLAYER_HOR_SPD * delta + 5;
                //}

                //Makes the last direction "down" so that it will play the moving / idle down animation
                //This is here only in case the collision returns ture
                lastAnim = "left";
            }
        }

        //Checks for movement right
        if (IsKeyDown(KEY_D)) {

            //This is just for some animation reasons, every direction does this against the opposite direction.
            // Just makes the correct correct animation play
            if(!IsKeyDown(KEY_A)) {

                //If the collision detection returns false, it will move the player forwards
                if(!checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x += PLAYER_HOR_SPD * delta;

                    lastAnim = "right";
                }

                //If it returns true, it moves the player backward so that you don't go into the tile
                if(checkCollisionFuture()) {
                    Moving = true;
                    playerP->position.x -= PLAYER_HOR_SPD * delta;
                }

                //Unused movement code
                //if(checkCollision()){
                //    player->position.x -= PLAYER_HOR_SPD * delta + 5;
                //}

                //Makes the last direction "down" so that it will play the moving / idle down animation
                //This is here only in case the collision returns ture
                lastAnim = "right";
            }
        }

        //I honestly don't know what this does
        for (int i = 0; i < envItemsLength; i++)
        {
            EnvItem *ei = envItems + i;
            Vector2 *p = &(playerP->position);
            if (ei->blocking &&
                ei->rect.x <= p->x &&
                ei->rect.x + ei->rect.width >= p->x &&
                ei->rect.y >= p->y &&
                ei->rect.y < p->y + playerP->speed*delta)
            {
                playerP->speed = 0.0f;
                p->y = ei->rect.y;
            }
        }
    }
};

#endif //GAME1_GAMESTATE_H