//
//  PositionComponent.h
//  FunGame
//
//  Created by stanley pena on 7/20/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef TransformComponent_hpp
#define TransformComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component {
public:
    
    Vector2D position;
    Vector2D velocity;
    
    int speed = 3;
    

    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
   
    void init() override {
        velocity.x = 0;
        velocity.y = 0;
    }
    void update() override {
        position.x += velocity.x * speed;
        position.y += velocity.y * speed;
       
    }
    
};

#endif /* TransformComponent_h */
