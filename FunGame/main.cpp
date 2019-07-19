//
//  main.cpp
//  FunGame
//
//  Created by stanley pena on 7/15/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h> // engine library
#include <SDL2/SDL_image.h> //image library
#include "Game.hpp"

using namespace std;

Game *game = nullptr;

int main(int argc, const char * argv[]) {
    // make the fps stay at a stable 60
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;
    
    
    game = new Game();
    game->init("fun game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    
    while(game->running()){
        frameStart = SDL_GetTicks();
       
        game->handleEvents();
        game->update();
        game->render();
        
        frameTime = SDL_GetTicks() - frameStart;
        
        // checks that fps is stable with every pc
        if(frameDelay > frameTime){
            SDL_Delay(frameDelay - frameTime);
        }
    }
    game->clean();

    
    return 0;;
}
