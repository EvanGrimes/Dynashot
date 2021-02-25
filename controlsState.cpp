#include "controlsState.h"

void controlsState::tick(){
    //Makes back button not active until clicked
    backBtnAction = false;

    //Checks for back button action
    tickBackBtn();

    //Draws the scene
    render();
}

void controlsState::render(){

    //Clears background
    ClearBackground(BLUE);
    //DrawRectangleRec(backBtnBounds, RED);
    //DrawText("Walk Up:  W", 20, 20, 40, RAYWHITE);

    //Draws the actual controls
    DrawTextEx(Assets::comicSans,  "Walk Up:     W", (Vector2){20, 20}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Down:  S", 20, 60, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Down:     S", (Vector2){20, 60}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Left:   A", 20, 100, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Left:     A", (Vector2){20, 100}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Right:  D", 20, 140, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Right:     D", (Vector2){20, 140}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);

    //Draws the back button
    DrawTexture(Assets::backBtn, -3, 550, WHITE);
}

void controlsState::tickBackBtn(){
    //Sets mousePoint to the mouse x and y to check collision with button
    mousePoint = GetMousePosition();

    //Checks collision between the mouse and the back button
    if (CheckCollisionPointRec(mousePoint, backBtnBounds)) {
        //printf("Back has been touched!\n");

        //If the mouse clicks the button, backBtnAction is set true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) backBtnAction = true;
    }

    //If backBtnAction is true
    if (backBtnAction) {
        //Sets a volume for the sound
        SetSoundVolume(Assets::buttonclick4, 0.06);
        //Plays a sound
        PlaySound(Assets::buttonclick4);
        // Just set a thingy here
        //Debug message to see if button was clicked
        std::cout << "Back button clicked\n" << std::endl;
        //Sets Assets::type to "title" so that the game loop will go back to the title screen
        Assets::type = "title";
    }
}