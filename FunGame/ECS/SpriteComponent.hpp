//
//  Header.h
//  FunGame
//
//  Created by stanley pena on 7/20/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef SpriteComponent_hpp
#define SpriteComponent_hpp

#include "Components.hpp"
#include "SDL2/SDL.h"

class SpriteComponent : public Component {
    
public:
    SpriteComponent() = default;
   
    SpriteComponent(const char* path){
        setTex(path);
    }
    
    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = srcRect.h = 32;
        destRect.w = destRect.h = 64;
    }
    
    void update() override {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
    }
    
    void draw() override {
        TextureManager::draw(texture, srcRect, destRect);
    }
    
private:
    TransformComponent *transform;
    SDL_Texture *texture;
    SDL_Rect srcRect, destRect;
};

#endif /* Header_h */
