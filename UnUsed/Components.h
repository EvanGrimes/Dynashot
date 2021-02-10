#ifndef GAME1_COMPONENTS_H
#define GAME1_COMPONENTS_H
#endif //GAME1_COMPONENTS_H

#include "ECS.h"

class PositionComponent : public Component{

private:
    int xpos;
    int ypos;

public:
    void init() override{
        xpos = 0,
                ypos = 0;
    }

    int getX(){
        return xpos;
    }

    int getX(){
        return ypos;
    }

    void tick() override{
        xpos++;
        ypos++;
    }



    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }

};
