//
//  ColliderComponent.h
//  FunGame
//
//  Created by stanley pena on 7/21/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef ColliderComponent_hpp
#define ColliderComponent_hpp

#include <string>
#include "SDL2/SDL.h"
#include "Components.hpp"

using namespace std;

class ColliderComponent : public Component {
    
public:
    SDL_Rect collider;
    string tag;
    TransformComponent* transform;
    
    ColliderComponent(string t){
        tag = t;
    }
    
    void init() override {
        if(!entity->hasComponent<TransformComponent>()){
            entity->addComponent<TransformComponent>();
        }
        transform = &entity->getComponent<TransformComponent>();
    }
    
    void update() override {
        collider.x = static_cast<int>(transform->position.x);
        collider.y = static_cast<int>(transform->position.y);
        collider.w = transform->width * transform->scale;
        collider.h = transform->height * transform->scale;

    }
};

#endif /* ColliderComponent_h */
