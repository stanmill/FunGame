//
//  GameObject.hpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <stdio.h>
#include "Game.hpp"

class GameObject {
    
public:
    GameObject (const char* textureSheet, int x, int y);
    ~GameObject();
    
    void update();
    void render();
private:
    int xpos;
    int ypos;
    
    SDL_Texture* objTexture;
    SDL_Rect srcRec, desRec;
    
};

#endif /* GameObject_hpp */
