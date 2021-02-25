#include "raylib.h"
#include "Game.h"

class titleState
{
public:

    // The button collision boxes
    Rectangle startBtnBounds = {355,200,255, 112 };
    Rectangle settBtnBounds = { 355,330,255, 112 };
    Rectangle exitBtnBounds = { 0,550,50, 50 };
    Rectangle controlBtnBounds = { 950,550,50, 50 };

    //The button states (determines the texture displayed)
    int startBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER
    int settBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER

    //Button actions. If clicked, they are true, otherwise, it is false
    bool startBtnAction = false;         // Button action should be activated
    bool settBtnAction = false;          // Button action should be activated
    bool exitBtnAction = false;
    bool controlBtnAction = false;

    //Mouse position
    Vector2 mousePoint = { 0.0f, 0.0f };


    //All the functions used
    void tick();
    void render();
    void tickStartBtn();
    void tickSettBtn();
    void tickExitBtn();
    void tickControlsBtn();
};