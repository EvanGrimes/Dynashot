#include "Game.h"


void titleState::tick() {
    UpdateMusicStream(Assets::titleSong);
    //Sets mousePoint to a Vector2 of the mouse position so that it can check collision with the button
    mousePoint = GetMousePosition();

    //Sets all the buttons to not being clicked. If this didn't happen, you would not be able to enter a menu twice
    startBtnAction = false;
    settBtnAction = false;
    controlBtnAction = false;
    exitBtnAction = false;

    //Sets the state to 0 (regular) so that it looks normal.
    //If it is set to 2, it displays a "hovering" version of the button
    startBtnState = 0;
    settBtnState = 0;

    //Updates and checks for collision with all the buttons
    tickStartBtn();
    tickSettBtn();
    tickControlsBtn();
    tickExitBtn();

    //Draws the scene
    render();
}
void titleState::render() {

    //Clears the background
    ClearBackground(YELLOW);

    //Draws the title screen background
    DrawTexture(Assets::titleScreen, 0, 0, WHITE);

    //Draws the FPS in the upper left corner
    DrawFPS(10, 10);


    //If startBtnState is 0, it draws the regular start button image
    if (startBtnState == 0) {
        DrawTexture(Assets::startBtn, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::startBtn, startSourceRec, (Vector2){ startBtnBounds.x, startBtnBounds.y }, WHITE);
    }

    //If startBtnState is 1, it draws the hovered  start button image
    if (startBtnState == 1) {
        DrawTexture(Assets::startHover, (int)startBtnBounds.x, (int)startBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::startHover, startSourceRec, (Vector2){ startBtnBounds.x, startBtnBounds.y }, WHITE);
    }

    //If settBtnState is 0, it draws the regular settings button image
    if (settBtnState == 0) {
        DrawTexture(Assets::settBtn,(int)settBtnBounds.x, (int)settBtnBounds.y , WHITE); // Draw button frame
        //DrawTextureRec(Assets::settBtn, settSourceRec, (Vector2){ settBtnBounds.x, settBtnBounds.y }, WHITE);
    }
    //If settBtnState is 1, it draws the hovered settings button image
    if (settBtnState == 1) {
        DrawTexture(Assets::settHover,(int)settBtnBounds.x, (int)settBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::settHover, settSourceRec, (Vector2){ settBtnBounds.x, settBtnBounds.y }, WHITE);
    }
    //DrawRectangleRec(exitBtnBounds, RED);

    //Draws the controls button
    DrawTexture(Assets::controlsBtn, 950, 550, WHITE);

    //Draws the exit button
    DrawTexture(Assets::exitBtn, -5, 550, WHITE);

    //DrawRectangleRec(settBtnBounds, PURPLE);
}

void titleState::tickStartBtn() {
    // Check start button state

    //If collision is detected between the mouse and the start button
    if (CheckCollisionPointRec(mousePoint, startBtnBounds)) {
        //printf("Start has been touched!\n");

        //Makes the button display the hovering version
        startBtnState = 1;

        //If the button is clicked, the button action is true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) startBtnAction = true;
    }
    else startBtnState = 0;

    if (startBtnAction) {
        //Sets sound volume
        SetSoundVolume(Assets::buttonclick1, 0.6);

        //Plays a sound
        PlaySound(Assets::buttonclick1);
        // Just set a thingy here

        //Debug text
        std::cout << "Start button clicked\n" << std::endl;

        //Stops the title music
        StopMusicStream(Assets::titleSong);

        //Makes the game loop go into the game state
        Assets::type = "game";
    }
}

void titleState::tickSettBtn() {
    // Check settings button state

    //If collision is detected between the mouse and the settings button
    if (CheckCollisionPointRec(mousePoint, settBtnBounds)) {
        //printf("Settings has been touched!\n");

        //Makes the button display the hovering version
        settBtnState = 1;

        //If the button is clicked, the button action is true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) settBtnAction = true;
    }
    else settBtnState = 0;

    if (settBtnAction) {
        // Just set a thingy here

        //Debug text
        std::cout << "Setting button clicked\n" << std::endl;

        //Makes the game loop go into the settings menu
        Assets::type = "settings";
    }
}

void titleState::tickControlsBtn() {

    //If collision is detected between the mouse and the controls button
    if(CheckCollisionPointRec(mousePoint, controlBtnBounds)){
        //printf("Controls has been touched!");

        //If the button is clicked, the button action is true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) controlBtnAction = true;
    }

    if(controlBtnAction){
        //Sets sound volume
        SetSoundVolume(Assets::buttonclick2, 0.06);

        //Plays a sound
        PlaySound(Assets::buttonclick2);

        //Debug text
        std::cout << "Control Button Clicked\n" << std::endl;

        //Makes the game loop go into the controls menu
        Assets::type = "controls";
    }
}
void titleState::tickExitBtn() {
    //If collision is detected between the mouse and the exit button
    if(CheckCollisionPointRec(mousePoint, exitBtnBounds)){
        //printf("Controls has been touched!");

        //If the button is clicked, the button action is true
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) exitBtnAction = true;
    }


    if(exitBtnAction){
        //Sets sound volume
        SetSoundVolume(Assets::buttonclick3, 0.06);

        //Plays a sound
        PlaySound(Assets::buttonclick3);

        //Debug text
        std::cout << "Exit Button Clicked\n" << std::endl;

        //Unloads title assets before closing
        Assets::unloadTitle();

        //Makes the game close
        Assets::type = "exit";
    }
}
