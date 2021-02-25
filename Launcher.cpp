#include "Game.h"
#include <raylib.h>
#include <ctime>

class timer {
private:
    unsigned long begTime;
public:
    void start() {
        begTime = clock();
    }

    [[nodiscard]] unsigned long elapsedTime() const {
        return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
    }
};


int main()
{
    unsigned long seconds = 2;
    timer t{};

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
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
    //_sleep(1.4 * 1000);
    t.start();
    while(true) {
        if(t.elapsedTime() >= seconds) {
            break;
        }
    }
    Assets::type = "title";
    game.loop();
    CloseWindow();
    return 0;
}
