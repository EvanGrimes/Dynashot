//
// Created by 18149 on 1/13/2021.
//

#include "Entity.h"
#include <raylib.h>

Entity::Entity(Handler handler, float x, float y, int width, int height){
        this->handler = handler;
        this->x = x;
        this->y = y;
        this->height = height;
        this->width = width;

        bounds = new Rectangle{0, 0, static_cast<float>(width), static_cast<float>(height)};
    }

bool Entity::checkEntityCollisions(float xOffset, float yOffset){
        for(Entity *e : handler.world.entityManager.entities){
            if(e == this){
                continue;
            }
            if(e->getCollisionBounds(0.0f, 0.0f).intersects(getCollisionBounds(xOffset, yOffset))){
                return true;
            }

        }
        return false;
    }

Rectangle Entity::getCollisionBounds(float xOffset, float yOffset){
        return new Rectangle((int) (x + bounds.x + xOffset), (int) (y + bounds.y + yOffset), bounds.width, bounds.height);
    }

float Entity::getX() {
        return x;
    }

float Entity::getY() {
        return y;
    }

int Entity::getWidth(){
        return width;
    }

int Entity::getHeight(){
        return height;
    }


