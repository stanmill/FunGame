//
//  Map.cpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "Map.hpp"
#include "Game.hpp"
#include <fstream>
#include <iostream>

using namespace std;


Map::Map(){
   

}

Map::~Map(){
   

}

void Map::loadMap(string path, int sizeX, int sizeY){
    char tile;
    fstream mapFile;
    mapFile.open(path);
    
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++) {
            mapFile.get(tile);
            Game::addTile(atoi(&tile), x * 32, y * 32);
            mapFile.ignore();
        }
    }
    
    mapFile.close();
}

