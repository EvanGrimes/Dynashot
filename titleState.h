#include "raylib.h"
#include "Game.h"

class titleState
{
public:
    // Define button bounds on screen
    Rectangle startBtnBounds = {355,200,255, 112 };
    Rectangle settBtnBounds = { 355,330,255, 112 };
    Rectangle exitBtnBounds = { 0,550,50, 50 };
    Rectangle controlBtnBounds = { 950,550,50, 50 };

    int startBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER
    int settBtnState = 0;                // Button state: 0-NORMAL, 1-MOUSE_HOVER
    bool startBtnAction = false;         // Button action should be activated
    bool settBtnAction = false;          // Button action should be activated
    bool exitBtnAction = false;
    bool controlBtnAction = false;

    Vector2 mousePoint = { 0.0f, 0.0f };

    void tick();
    void tickStartBtn();
    void tickSettBtn();
    void tickExitBtn();
    void tickControlsBtn();
};