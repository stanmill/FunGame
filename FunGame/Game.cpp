//
//  Game.cpp
//  FunGame
//
//  Created by stanley pena on 7/18/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include "Game.hpp"
#include "TextureManager.hpp"
#include "Map.hpp"
#include "ECS/Components.hpp"
using namespace std;

Map* map;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());

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
    // render map
    map = new Map();
    
    // render player
    player.addComponent<PositionComponent>();
    player.addComponent<SpriteComponent>("/Users/stanleypena/Documents/GitHub/FunGame/Assets/player.png");

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
    manager.refresh();
    manager.update();
    
    if(player.getComponent<PositionComponent>().x() >100){
        player.getComponent<SpriteComponent>().setTex("/Users/stanleypena/Documents/GitHub/FunGame/Assets/enemy.png");
    }
}

void Game::render(){
    SDL_RenderClear(renderer);
    map->drawMap();
    manager.draw();
    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    cout << "Game Cleaned \n";
}
