//
//  KeyboardController.h
//  FunGame
//
//  Created by stanley pena on 7/21/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include "../Game.hpp"
#include "ECS.hpp"
#include "Components.hpp"

class KeyboardController : public Component {

public:
    TransformComponent *transform;
    
    void init() override {
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override {
        // when key is pressed increase the speed velocity
        if(Game::event.type == SDL_KEYDOWN){
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = -1;
                    break;
                case SDLK_a:
                    transform->velocity.x = -1;
                    break;
                case SDLK_d:
                    transform->velocity.x = 1;
                    break;
                case SDLK_s:
                    transform->velocity.y = 1;
                    break;
                    
                default:
                    break;
            }
        }
        
        // when key is relesed set the speed back to 0
        if(Game::event.type == SDL_KEYUP){
            switch (Game::event.key.keysym.sym) {
                case SDLK_w:
                    transform->velocity.y = 0;
                    break;
                case SDLK_a:
                    transform->velocity.x = 0;
                    break;
                case SDLK_d:
                    transform->velocity.x = 0;
                    break;
                case SDLK_s:
                    transform->velocity.y = 0;
                    break;
                    
                default:
                    break;
            }
        }
    }
};

#endif /* KeyboardController_h */
