//
//  Collision.cpp
//  FunGame
//
//  Created by stanley pena on 7/21/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "Collision.hpp"

bool Collision::AABB(const SDL_Rect& recA, const SDL_Rect& recB){
    if(recA.x + recA.w >= recB.x && recB.x + recB.w >= recA.x && recA.y + recA.h >= recB.y && recB.y + recB.h >= recA.y){
        return true;
    }
    return false;
}
