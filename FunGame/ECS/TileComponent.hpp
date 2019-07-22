//
//  TileComponent.h
//  FunGame
//
//  Created by stanley pena on 7/22/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef TileComponent_hpp
#define TileComponent_hpp

#include "ECS.hpp"
#include "TransformComponent.hpp"
#include "SpriteComponent.hpp"
#include "SDL2/SDL.h"

class TileComponent : public Component{
    
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    
    SDL_Rect tileRect;
    int tileID;
    char *path;
    
    TileComponent() = default;
    
    TileComponent(int x, int y, int w, int h, int id){
        tileRect.x = x;
        tileRect.y = y;
        tileRect.h = h;
        tileRect.w = w;
        tileID = id;
        
        switch (tileID) {
            case 0:
                path = "/Users/stanleypena/Documents/GitHub/FunGame/Assets/water.png";
                break;
            case 1:
                path = "/Users/stanleypena/Documents/GitHub/FunGame/Assets/ground.png";
                break;
            case 2:
                path = "/Users/stanleypena/Documents/GitHub/FunGame/Assets/grass.png";
                break;
            default:
                break;
        }
    }
    
    void init() override {
        entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();
        
        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
    }
};

#endif /* TileComponent_h */
