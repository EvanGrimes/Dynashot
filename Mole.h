#ifndef GAME1_MOLE_H
#define GAME1_MOLE_H

#include "Enemy.h"
#include "Assets.h"

class Mole : Enemy{
    Mole(float x, float y);
public:
    int MoleCount = 0;
    Entity moles[256];

    void tick();





};


#endif //GAME1_MOLE_H
