#include "raylib.h"
#include "Assets.h"
#define NUM_FRAMES  2

class titleState {
public:
    Assets assets;
    //Texture2D startBtn = assets.startBtn;
    //Texture2D startBtnHover = assets.startHover;
    //Texture2D settBtn = assets.settBtn;
    //Texture2D settBtnHover = assets.settHover;

    Rectangle startBtnBounds = {static_cast<float>(.screenWidth / 2 - assets.startBtn.width / 2),
                                static_cast<float>(assets.screenHeight / 2 - assets.startBtn.height / NUM_FRAMES / 2),
                                static_cast<float>(assets.startBtn.width), static_cast<float>(assets.startBtn.height)};
    Rectangle settBtnBounds  = {static_cast<float>(assets.screenWidth / 2 - assets.settBtn.width / 2),
                               static_cast<float>(assets.screenHeight / 2 - assets.settBtn.height / NUM_FRAMES / 2),
                               static_cast<float>(assets.settBtn.width), static_cast<float>(assets.settBtn.height)};

    int startBtnState = 0;               // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    int settBtnState = 0;                // Button state: 0-NORMAL, 1-MOUSE_HOVER, 2-PRESSED
    bool startBtnAction = false;         // Button action should be activated
    bool settBtnAction = false;          // Button action should be activated

    Vector2 mousePoint = {0.0f, 0.0f};

    void tick() {
        // Update
        printf("Start id: %d \n Start Hover: %d\n", assets.startBtn.id, assets.startHover.id);
        printf("Setting id: %d \n Setting Hover: %d\n", assets.settBtn.id, assets.settBtn.id);
        mousePoint = GetMousePosition();
        startBtnAction = false;
        settBtnAction = false;

        tickStartBtn();
        tickSettBtn();

        // Calculate button frame rectangle to draw depending on button state
        //startSourceRec.y = startBtnState * startFrameHeight;
        //startSourceRec.y = settBtnState * settFrameHeight;

        // Draw

        ClearBackground(YELLOW);
        DrawRectangle(10,10,100,100,RED);
        DrawTexture(assets.titleScreen, 0, 0, WHITE);

        if (startBtnState == 0) {
            DrawTexture(assets.startBtn, startBtnBounds.x, startBtnBounds.y, WHITE); // Draw button frame
        }
        if (startBtnState == 1) {
            DrawTexture(assets.startHover, startBtnBounds.x, startBtnBounds.y,WHITE); // Draw button frame
        }


        if (settBtnState == 0) {
            DrawTexture(assets.settBtn,/*settBtnBounds.x*/ 0, /*settBtnBounds.y*/ 0,WHITE); // Draw button frame
        }
        if (settBtnState == 1) {
            DrawTexture(assets.settHover, /*settBtnBounds.x*/ 0, /*settBtnBounds.y*/ 0,WHITE); // Draw button frame
        }

    }

    void tickStartBtn(){
        // Check start button state
        if (CheckCollisionPointRec(mousePoint, startBtnBounds)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) startBtnState = 2;
            else startBtnState = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) startBtnAction = true;
        } else startBtnState = 0;

        if (startBtnAction) {
            // Just set a thingy here
            std::cout << "Start button clicked" << std::endl;
        }
    }

    void tickSettBtn(){
        // Check settings button state
        if (CheckCollisionPointRec(mousePoint, settBtnBounds)) {
            if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) settBtnState = 2;
            else settBtnState = 1;

            if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) settBtnAction = true;
        } else settBtnState = 0;

        if (settBtnAction) {
            // Just set a thingy here
            std::cout << "Setting button clicked" << std::endl;
        }
    }
};