//
// Created by 18149 on 1/13/2021.
//

#include "Creature.h"




Creature::Creature(Handler handler, float x, float y, int width, int height) {
super(handler, x, y, width, height);
health = DEFAULT_HEALTH;
speed = DEFAULT_SPEED;
xMove = 0;
yMove = 0;
}

void Creature::move(){
    if(!entity.checkEntityCollisions(xMove, 0.0f)) {
        moveX();
    }
    if(!entity.checkEntityCollisions(0, yMove)) {
        moveY();
    }
}

void Creature::moveX(){
    if (xMove > 0){ //Move Right

        int tx = (int) (entity.x + xMove + entity.bounds.x + entity.bounds.width) / tile.TILEWIDTH;
        if(!collisionWithTile(tx, (int) (entity.y + entity.bounds.y) / tile.TILEHEIGHT) &&
           !collisionWithTile(tx, (int) (entity.y + entity.bounds.y + entity.bounds.height) / tile.TILEHEIGHT)){
            entity.x += xMove;
        }else {
            entity.x = tx * tile.TILEWIDTH - entity.bounds.x - entity.bounds.width - 1;
        }

    } else if (xMove < 0){//Move Left
        int tx = (int) (entity.x + xMove + entity.bounds.x) / tile.TILEWIDTH;
        if(!collisionWithTile(tx, (int) (entity.y + entity.bounds.y) / tile.TILEHEIGHT) &&
           !collisionWithTile(tx, (int) (entity.y + entity.bounds.y + entity.bounds.height) / tile.TILEHEIGHT)){
            entity.x += xMove;
        } else{
            entity.x = tx * tile.TILEWIDTH + tile.TILEWIDTH - entity.bounds.x;
        }
    }
}

void Creature::moveY(){
    if(yMove < 0 ){//Up
        int ty = (int) (entity.y + yMove + entity.bounds.y) / tile.TILEHEIGHT;

        if(!collisionWithTile((int) (entity.x + entity.bounds.x) / tile.TILEWIDTH, ty) &&
           !collisionWithTile((int) (entity.x + entity.bounds.x + entity.bounds.width) / tile.TILEWIDTH, ty)   ){
            entity.y += yMove;
        } else{
            entity.y = ty * tile.TILEHEIGHT + tile.TILEHEIGHT - entity.bounds.y;
        }

    }else if( yMove > 0){//Down
        int ty = (int) (entity.y + yMove + entity.bounds.y + entity.bounds.height) / tile.TILEHEIGHT;

        if(!collisionWithTile((int) (entity.x + entity.bounds.x) / tile.TILEWIDTH, ty) &&
           !collisionWithTile((int) (entity.x + entity.bounds.x + entity.bounds.width) / tile.TILEWIDTH, ty)   ){
            entity.y += yMove;
        } else{
            entity.y = ty * tile.TILEHEIGHT - entity.bounds.y - entity.bounds.height - 1;
        }
    }
}

bool Creature::collisionWithTile(int x, int y){
    return handler.getWorld().getTile(x, y).isSolid();
}

