
#include "Game.h"
#include <raylib.h>
int main()
{
    Game game;
    InitWindow(Assets::screenWidth, Assets::screenHeight, "Test");
    SetExitKey(0);
    InitAudioDevice();
    SetTargetFPS(60);
    BeginDrawing();
    ClearBackground(SKYBLUE);
    Assets::loadTitle();
    SetWindowIcon(Assets::icon);
    DrawTexture(Assets::splashScreen, 175, 0, WHITE);
    EndDrawing();
    _sleep(1.4 * 1000);
    Assets::type = "title";
    game.loop();
    CloseWindow();
    return 0;
}
