//
//  TextureManager.hpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef TextureManager_hpp
#define TextureManager_hpp

#include <stdio.h>
#include "Game.hpp"

class TextureManager {
    
public:
    static SDL_Texture* LoadTexture (const char* fileName);
    static void draw(SDL_Texture* text, SDL_Rect src, SDL_Rect des);
    
};

#endif /* TextureManager_hpp */
