//
//  GameObject.cpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "GameObject.hpp"
#include "TextureManager.hpp"

GameObject::GameObject(const char* textureSheet, int x, int y){
    objTexture = TextureManager::LoadTexture(textureSheet);
    
    xpos = x;
    ypos = y;
}

void GameObject::update(){
    
    xpos++;
    ypos++;
    
    // size of the object
    srcRec.h = 32;
    srcRec.w = 32;
    
    srcRec.x = 0;
    srcRec.y = 0;
    
    desRec.x = xpos;
    desRec.y = ypos;
    desRec.w = srcRec.w * 2;
    desRec.h = srcRec.h * 2;
}

void GameObject::render(){
    SDL_RenderCopy(Game::renderer, objTexture, &srcRec, &desRec);
}
