//
//  Collision.hpp
//  FunGame
//
//  Created by stanley pena on 7/21/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef Collision_hpp
#define Collision_hpp

#include <stdio.h>
#include "SDL2/SDL.h"

class Collision {
    
public:
    static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
};

#endif /* Collision_hpp */
