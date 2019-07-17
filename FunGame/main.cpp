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

using namespace std;

const int WIDTH = 800, HEIGHT = 600;

int main(int argc, const char * argv[]) {
    // creating a window    
    
    
    // check if the window is created sucessfully
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
        cout << "Error" << SDL_GetError()<< std::endl;
    }
    
    SDL_Window *window = SDL_CreateWindow("Hello window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    
    if(NULL == window){
        cout << "unable to create window";
        return EXIT_FAILURE;
    }
    
    
    SDL_Event windowEvent;
    
    while (true) {
        if(SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type) {
                break;
            }
        }
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return EXIT_SUCCESS;
    
}
