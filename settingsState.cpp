//
// Created by 18149 on 1/14/2021.
//

#include "settingsState.h"
#include <stdio.h>



void settingsState::tick(){
    backBtnAction = false;
    backBtnState = 0;
    render();
}

void settingsState::render(){
    tickBackBtn();
    ClearBackground(LIME);
    //DrawRectangleRec(backBtnBounds, RED);
    //DrawText("Walk Up:     W", 20, 20, 40, RAYWHITE);
    ////DrawText("Walk Down:  S", 20, 60, 40, RAYWHITE);
    //DrawText("Walk Left:   A", 20, 100, 40, RAYWHITE);
    //DrawText("Walk Right:  D", 20, 140, 40, RAYWHITE);
    DrawTexture(Assets::backBtn, -3, 550, WHITE);
    //printf("Controls");
}

void settingsState::tickBackBtn(){
    mousePoint = GetMousePosition();
    if (CheckCollisionPointRec(mousePoint, backBtnBounds)) {
        //printf("Back has been touched!\n");
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) backBtnState = 2;
        else backBtnState = 1;

        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) backBtnAction = true;
    }
    else backBtnState = 0;

    if (backBtnAction) {
        SetSoundVolume(Assets::buttonclick4, 0.06);
        PlaySound(Assets::buttonclick4);
        // Just set a thingy here
        std::cout << "Back button clicked\n" << std::endl;
        Assets::type = "title";
    }
};