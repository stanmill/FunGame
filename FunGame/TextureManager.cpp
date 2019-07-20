//
//  TextureManager.cpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "TextureManager.hpp"

SDL_Texture* TextureManager::LoadTexture(const char *texture){
    SDL_Surface* tempSurface = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    
    return tex;
}
void TextureManager::draw(SDL_Texture *text, SDL_Rect src, SDL_Rect des){
    SDL_RenderCopy(Game::renderer, text, &src, &des);
}
