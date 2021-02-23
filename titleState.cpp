//#include "titleState.h"
#include "Game.h"


void titleState::tick()
{
    UpdateMusicStream(Assets::titleSong);
    // Update
    mousePoint = GetMousePosition();
    startBtnAction = false;
    settBtnAction = false;
    controlBtnAction = 0;
    exitBtnAction = 0;

    tickStartBtn();
    tickSettBtn();
    tickControlsBtn();
    tickExitBtn();

    ClearBackground(YELLOW);
    DrawTexture(Assets::titleScreen, 0, 0, WHITE);
    DrawFPS(10, 10);

    if (startBtnState == 0) {
        DrawTexture(Assets::startBtn, startBtnBounds.x, startBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::startBtn, startSourceRec, (Vector2){ startBtnBounds.x, startBtnBounds.y }, WHITE);
    }
    if (startBtnState == 1) {
        DrawTexture(Assets::startHover, startBtnBounds.x, startBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::startHover, startSourceRec, (Vector2){ startBtnBounds.x, startBtnBounds.y }, WHITE);
    }
    if (settBtnState == 0) {
        DrawTexture(Assets::settBtn,settBtnBounds.x, settBtnBounds.y , WHITE); // Draw button frame
        //DrawTextureRec(Assets::settBtn, settSourceRec, (Vector2){ settBtnBounds.x, settBtnBounds.y }, WHITE);
    }
    if (settBtnState == 1) {
        DrawTexture(Assets::settHover,settBtnBounds.x, settBtnBounds.y, WHITE); // Draw button frame
        //DrawTextureRec(Assets::settHover, settSourceRec, (Vector2){ settBtnBounds.x, settBtnBounds.y }, WHITE);
    }
    //DrawRectangleRec(exitBtnBounds, RED);
    DrawTexture(Assets::controlsBtn, 950, 550, WHITE);
    DrawTexture(Assets::exitBtn, -5, 550, WHITE);
    //rawRectangle(950, 550, 25, 25, RED);
    //DrawTexture();

    //DrawRectangleRec(settBtnBounds, PURPLE);
}

void titleState::tickStartBtn() {
    // Check start button state
    if (CheckCollisionPointRec(mousePoint, startBtnBounds)) {
        //printf("Start has been touched!\n");
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) startBtnState = 2;
        else startBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) startBtnAction = true;
    }
    else startBtnState = 0;

    if (startBtnAction) {
        SetSoundVolume(Assets::buttonclick1, 0.6);
        PlaySound(Assets::buttonclick1);
        // Just set a thingy here
        std::cout << "Start button clicked\n" << std::endl;
        StopMusicStream(Assets::titleSong);
        Assets::type = "game";
    }
}

void titleState::tickSettBtn() {
    // Check settings button state
    if (CheckCollisionPointRec(mousePoint, settBtnBounds)) {
        //printf("Settings has been touched!\n");
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) settBtnState = 2;
        else settBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) settBtnAction = true;
    }
    else settBtnState = 0;

    if (settBtnAction) {
        // Just set a thingy here
        std::cout << "Setting button clicked\n" << std::endl;
        Assets::type = "settings";
    }
}

void titleState::tickControlsBtn() {
    if(CheckCollisionPointRec(mousePoint, controlBtnBounds)){
        //printf("Controls has been touched!");
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) controlBtnState = 2;
        else controlBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) controlBtnAction = true;
    }
    else controlBtnState = 0;

    if(controlBtnAction){
        SetSoundVolume(Assets::buttonclick2, 0.06);
        PlaySound(Assets::buttonclick2);
        std::cout << "Control Button Clicked\n" << std::endl;
        Assets::type = "controls";
    }
}
void titleState::tickExitBtn() {
    if(CheckCollisionPointRec(mousePoint, exitBtnBounds)){
        //printf("Controls has been touched!");
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)) exitBtnState = 2;
        else exitBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) exitBtnAction = true;
    }
    else exitBtnState = 0;

    if(exitBtnAction){
        SetSoundVolume(Assets::buttonclick3, 0.06);
        PlaySound(Assets::buttonclick3);
        std::cout << "Exit Button Clicked\n" << std::endl;
        Assets::unloadTitle();
        Assets::type = "exit";
    }
}
