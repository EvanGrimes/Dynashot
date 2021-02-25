#include "controlsState.h"

void controlsState::tick(){
    backBtnAction = false;
    render();
}

void controlsState::render(){
    tickBackBtn();
    ClearBackground(BLUE);
    //DrawRectangleRec(backBtnBounds, RED);
    //DrawText("Walk Up:  W", 20, 20, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Up:     W", (Vector2){20, 20}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Down:  S", 20, 60, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Down:     S", (Vector2){20, 60}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Left:   A", 20, 100, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Left:     A", (Vector2){20, 100}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    //DrawText("Walk Right:  D", 20, 140, 40, RAYWHITE);
    DrawTextEx(Assets::comicSans,  "Walk Right:     D", (Vector2){20, 140}, (float)Assets::comicSans.baseSize, 2, RAYWHITE);
    DrawTexture(Assets::backBtn, -3, 550, WHITE);
    printf("Controls");
}

void controlsState::tickBackBtn(){
    mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, backBtnBounds)) {
        //printf("Back has been touched!\n");

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) backBtnAction = true;
    }

    if (backBtnAction) {
        SetSoundVolume(Assets::buttonclick4, 0.06);
        PlaySound(Assets::buttonclick4);
        // Just set a thingy here
        std::cout << "Back button clicked\n" << std::endl;
        Assets::type = "title";
    }
}