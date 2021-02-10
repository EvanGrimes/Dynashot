#include "titleState.cpp"
#include <raylib.h>

int main() {
    std::string type;
    titleState titleState;
    InitWindow(titleState.assets.screenWidth, titleState.assets.screenHeight, "Test");
    SetTargetFPS(60);
    //SetWindowIcon(assets.player_idle_downImg);
    titleState.assets.loadTitle();
    //BeginDrawing();
    //ClearBackground(SKYBLUE);
    //DrawTexture(assets.splashScreen, 175, 0, WHITE);
    //DrawFPS(10, 10);
    type = "title";
    while (!WindowShouldClose()){
        BeginDrawing();
        if(type == "title"){

            titleState.tick();

        }
        if(type == "game"){

        }
        if(type == "settings"){

        }
        EndDrawing();
    }
    CloseWindow();
    //CloseWindow();
    return 0;
}
