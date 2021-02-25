#ifndef GAME1_SETTINGSSTATE_H
#define GAME1_SETTINGSSTATE_H

#include "raylib.h"
#include "Assets.h"

class settingsState {
public:

    //The button bounds for collision
    Rectangle backBtnBounds = { 0,550,50, 50 };

    //If false, the button is not clicked, if true the button is clicked
    bool backBtnAction = false;

    //The mouse position
    Vector2 mousePoint = { 0.0f, 0.0f };

    //The functions
    void tickBackBtn();
    void tick();
    void render();
};


#endif //GAME1SETTINGSSTATE_H
