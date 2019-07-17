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
    
    SDL_Surface *imageSurface = NULL;
    SDL_Surface *windowSurface = NULL;
    
    SDL_Init( SDL_INIT_EVERYTHING );
    
    SDL_Window *window = SDL_CreateWindow( "Hello SDL World", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    windowSurface = SDL_GetWindowSurface( window );
    
    // Check that the window was successfully created
    if ( NULL == window )
    {
        // In the case that the window could not be made...
        cout << "Could not create window: " << SDL_GetError( ) << std::endl;
        return 1;
    }
    
    if( !( IMG_Init( IMG_INIT_JPG ) & IMG_INIT_JPG ) )
    {
        cout << "Could not create window: " << IMG_GetError( ) << std::endl;
        return 1;
    }
    
    SDL_Event windowEvent;
    
    imageSurface = IMG_Load( "sonic.jpeg" );
    
    if ( NULL == imageSurface )
    {
        cout << "SDL could not load image! SDL Error: " << SDL_GetError( ) << std::endl;
    }
    
    while ( true )
    {
        if ( SDL_PollEvent( &windowEvent ) )
        {
            if ( SDL_QUIT == windowEvent.type )
            {
                break;
            }
        }
        
        SDL_BlitSurface( imageSurface, NULL, windowSurface, NULL );
        
        SDL_UpdateWindowSurface( window );
    }
    
    SDL_FreeSurface( imageSurface );
    SDL_FreeSurface( windowSurface );
    
    imageSurface = NULL;
    windowSurface = NULL;
    
    SDL_DestroyWindow( window );
    SDL_Quit( );
    
    return EXIT_SUCCESS;
}
