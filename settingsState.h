//
// Created by 18149 on 1/14/2021.
//

#ifndef GAME1_SETTINGSSTATE_H
#define GAME1_SETTINGSSTATE_H

#include "raylib.h"
#include "Assets.h"

class settingsState {
public:

    Rectangle backBtnBounds = { 0,550,50, 50 };
    bool backBtnAction = false;
    Vector2 mousePoint = { 0.0f, 0.0f };

    void tickBackBtn();
    void tick();
    void render();
    //const char walkForward[] = "";
    ////const char walkBack[];
    //const char walkLeft[];
    //const char walkRight[];
};


#endif //GAME1SETTINGSSTATE_H
