//
// Created by 18149 on 1/13/2021.
//

#include "Handler.h"


Handler::Handler(Game game){
        this->game = game;
    }


Camera2D Handler::getGameCamera(){
        return game.camera;
    }

int Handler::getWidth(){
        return Assets::screenWidth;
    }

int Handler::getHeight(){
        return Assets::screenHeight;
    }

Game Handler::getGame(){
        return game;
    }

World Handler::getWorld() {
        return world;
    }

void Handler::setWorld(World world){
        this->world = world;
    }


