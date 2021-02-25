//
// Created by 18149 on 1/14/2021.
//

#ifndef GAME1_CONTROLSSTATE_H
#define GAME1_CONTROLSSTATE_H

#include "raylib.h"
#include "Assets.h"

class controlsState {
public:

    //The button boundaries for collision with the button
    Rectangle backBtnBounds = { 0,550,50, 50 };
    //If the button is clicked, this is true. Otherwise, it is false
    bool backBtnAction = false;
    //The mouse position used for collision
    Vector2 mousePoint = { 0.0f, 0.0f };

    //The functions used
    void tickBackBtn();
    void tick();
    static void render();
    //const char walkForward[] = "";
    ////const char walkBack[];
    //const char walkLeft[];
    //const char walkRight[];
};


#endif //GAME1_CONTROLSSTATE_H
