//
//  Game.cpp
//  FunGame
//
//  Created by stanley pena on 7/18/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
using namespace std;

SDL_Texture* playertex;
SDL_Rect srcR, desR;

Game::Game(){
    
}
Game::~Game(){
    
}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullScreen){
    int flags = 0;
    if(fullScreen){
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        cout << "Subsystem Initialized. \n";
        
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullScreen);
        if(window){
            cout << "Window created. \n";
        }
        
        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer){
            // changes the background color
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            cout << "Renderer Created. \n";
        }
        isRunning = true;
    } else {
        isRunning = false;
    }
    // render player
    playertex = TextureManager::LoadTexture("/Users/stanleypena/Documents/GitHub/FunGame/Assets/player.png", renderer);
   
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
            
        default:
            break;
    }
    
}

void Game::update(){
    count++;
    
    desR.h = 64;
    desR.w = 64;
    desR.x = count;
    cout << count << endl;
    
}

void Game::render(){
    
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, playertex, NULL, &desR); // render image
    SDL_RenderPresent(renderer);
    
}

void Game::clean(){
    
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned \n";
    
}
