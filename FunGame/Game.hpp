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
    void render();
    void clean();
    
    bool running(){ return isRunning;}

private:
    int count;
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif /* Game_hpp */
