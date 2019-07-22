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
#include "../TextureManager.hpp"

class SpriteComponent : public Component {
    
public:
    SpriteComponent() = default;
   
    SpriteComponent(const char* path){
        setTex(path);
    }
    
    ~SpriteComponent(){
        SDL_DestroyTexture(texture);
    }
    
    void setTex(const char* path){
        texture = TextureManager::LoadTexture(path);
    }
    
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
        
        srcRect.x = srcRect.y = 0;
        srcRect.w = transform->width;
        srcRect.h = transform->height;
    }
    
    void update() override {
        destRect.x = (int)transform->position.x;
        destRect.y = (int)transform->position.y;
        destRect.w = transform->width * transform->scale;
        destRect.h = transform->height * transform->scale;
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
