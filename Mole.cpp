//
// Created by 18149 on 7/19/2021.
//

#include "Mole.h"

Mole::Mole(float x, float y){
    if(MoleCount == 0){
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkUp[z] = Assets::mole_up[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkDown[z] = Assets::mole_down[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkLeft[z] = Assets::mole_left[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkRight[z] = Assets::mole_right[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityIdle[z] = Assets::mole_idle[z];
        }

        moles[MoleCount].enemyCollision.x = x;
        moles[MoleCount].enemyCollision.y = y;


        MoleCount++;
    }
    if(MoleCount > 0){
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkUp[z] = Assets::mole_up[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkDown[z] = Assets::mole_down[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkLeft[z] = Assets::mole_left[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityWalkRight[z] = Assets::mole_right[z];
        }
        for(int z = 0; z <= 4; z++){
            moles[MoleCount].EntityIdle[z] = Assets::mole_idle[z];
        }

        moles[MoleCount].enemyCollision.x = x;
        moles[MoleCount].enemyCollision.y = y;


        MoleCount++;
    }
    if(MoleCount > 256){
        printf("too many moles");
    }
}

void Mole::tick() {





    for(int x; x >= MoleCount; x++){
        Enemy::render(moles[x], 4);
    }


}