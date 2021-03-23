#ifndef GAME1_PAUSESTATE_H
#define GAME1_PAUSESTATE_H

#include <raylib.h>
#include "Assets.h"
#include <ctime>

class pauseState {
public:
    int grace;
    void tick();
    void render();

    static bool checkPausePress(){
        //while(IsKeyUp(KEY_ESCAPE)){
            if (IsKeyPressed(KEY_ESCAPE)) {
                return true;
            } else {
                return false;
            }
        //}
    }


};


#endif //GAME1_PAUSESTATE_H
