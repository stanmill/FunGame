//
//  Game.hpp
//  FunGame
//
//  Created by stanley pena on 7/18/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h> //image library

class Game {
    
public:
    Game();
    ~Game();
    void init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);
    
    void handleEvents();
    void update();
    bool running(){ return isRunning;}
    void render();
    void clean();
    
    static SDL_Renderer* renderer;

private:
    int count;
    bool isRunning;
    SDL_Window *window;
};

#endif /* Game_hpp */
