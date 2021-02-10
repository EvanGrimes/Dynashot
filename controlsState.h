//
// Created by 18149 on 1/14/2021.
//

#ifndef GAME1_CONTROLSSTATE_H
#define GAME1_CONTROLSSTATE_H

#include "raylib.h"
#include "Assets.h"

class controlsState {
public:

    Rectangle backBtnBounds = { 0,550,50, 50 };
    int backBtnState = 0;
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


#endif //GAME1_CONTROLSSTATE_H
