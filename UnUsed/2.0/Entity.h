//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_ENTITY_H
#define GAME1_ENTITY_H


class Entity {
protected:
    Rectangle bounds;
public :
    Handler handler;
float x;
float y;
int width;
int height;
    Entity(Handler handler, float x, float y, int width, int height);
    bool checkEntityCollisions(float xOffset, float yOffset);
    Rectangle getCollisionBounds(float xOffset, float yOffset);
    float getX();
    float getY();
    int getWidth();
    int getHeight();
    void tick();
    void render();



};


#endif //GAME1_ENTITY_H
