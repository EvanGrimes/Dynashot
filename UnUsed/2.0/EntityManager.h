//
// Created by 18149 on 1/13/2021.
//

#ifndef GAME1_ENTITYMANAGER_H
#define GAME1_ENTITYMANAGER_H

#include "Entity.h"
#include <iostream>
#include <vector>

class EntityManager {
public:
//Handler handler;
Player player;
std::vector<Entity> entities;

    EntityManager(/*Handler handler*/ Player player);
    void tick();
    void render();
    void addEntity(Entity e);
};


#endif //GAME1_ENTITYMANAGER_H
