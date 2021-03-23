#include "pauseState.h"

void pauseState::tick() {

    if(grace > 8) {
        if (IsKeyPressed(KEY_ESCAPE)) {
            grace = 0;
            Assets::type = "game";
        }
    }else{
        grace++;
    }
        render();
}

void pauseState::render() {
    ClearBackground(BLUE);
}


