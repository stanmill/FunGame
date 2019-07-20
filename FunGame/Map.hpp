//
//  Map.hpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>
#include "Game.hpp"

class Map {
    
public:
    Map();
    ~Map();
    
    void drawMap();
    void loadMap(int arr[20][25]);
    
private:
    SDL_Rect src, dest;
    
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;
    
    int map[20][25];
};

#endif /* Map_hpp */
