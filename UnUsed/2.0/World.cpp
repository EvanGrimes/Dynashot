#include "World.h"
#include <iostream>


World::World(Handler handler, std::string path){
        this->handler = handler;
        EntityManager entityManager;
        entityManager = new EntityManager(handler, new Player(handler, 100, 100));
        //enemy = new Enemy(handler, entityManager.player, 200, 200);
        //entityManager.addEntity(enemy);
        loadWorld(path);
        entityManager.player.setX(spawnX);
        entityManager.player.setY(spawnY);
    };

void World::tick(){
        //enemyTick++;

        //if (enemyTick == 5){
        //enemy.tick();
        //enemyTick = 0;
        //}
        //Game.camera.centerOnEntity(entityManager.player);
        entityManager.player.tick();
    }

void World::render(){
        int xStart = (int) max(0, handler.getGameCamera().xOffset / tiles.TILEWIDTH), yStart = (int) max(0, handler.getGameCamera().yOffset / tiles.TILEHEIGHT);
        int xEnd = (int) min(WIDTH, (handler.getGameCamera().xOffset + handler.getWidth()) / tiles.TILEWIDTH + 1), yEnd = (int) (HEIGHT, (handler.getGameCamera().yOffset + handler.getHeight()) / tiles.TILEHEIGHT + 1);

        for (int y = yStart;y < yEnd;y++){
            for(int x = xStart;x < xEnd;x++){
                getTile(x, y).render((int) (x * tiles.TILEWIDTH - handler.getGameCamera().xOffset), (int) (y * tiles.TILEHEIGHT - handler.getGameCamera().xOffset));
            }
        }
        entityManager.render();
    }

Tiles World::getTile(int x, int y){
        if(x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT){
            return tiles.grassTile;
        }

        Tiles t = tiles.tiles[tiles.tiles[x][y]];
        if(t == null){
            return tiles.grassTile;
        }
        return t;
    }

void World::loadWorld(std::string path){
        string file = Utils.loadFileAsString(path);
        std::string[] tokens = file.split("\\s+");
        WIDTH = Utils.parseInt(tokens[0]);
        HEIGHT = Utils.parseInt(tokens[1]);
        spawnX = Utils.parseInt(tokens[2]);
        spawnY = Utils.parseInt(tokens[3]);

        tiles = new int[WIDTH][HEIGHT];
        for (int y = 0;y<HEIGHT;y++){
            for (int x = 0;x<HEIGHT;x++){
                tiles.tiles[x][y] = Utils.parseInt(tokens[(x+y*WIDTH) + 4]);
            }
        }


    }
