//
// Created by 18149 on 1/13/2021.
//

#include "EntityManager.h"

EntityManager::EntityManager(Handler handler, Player player){
        //this.handler = handler;
        this->player = player;
        entities = std::vector<Entity>();
        addEntity(player);
    }

void EntityManager::tick(){
        for(int i = 0;i < entities.size();i++){
            Entity e = entities.at(i);
            e.tick();
        }
    }

void EntityManager::render(){
        for(Entity e : entities){
            e.render();
        }
    }

void EntityManager::addEntity(Entity e){
        entities.push_back(e);
    }

