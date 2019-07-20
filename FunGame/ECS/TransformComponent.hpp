//
//  PositionComponent.h
//  FunGame
//
//  Created by stanley pena on 7/20/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef TransformComponent_hpp
#define TranformComponent_hpp

#include "Components.hpp"
#include "../Vector2D.hpp"

class TransformComponent : public Component {
public:
    
    Vector2D position;

    TransformComponent(){
        position.x = 0.0f;
        position.y = 0.0f;
    }
    TransformComponent(float x, float y){
        position.x = x;
        position.y = y;
    }
   
    void update() override {
        
       
    }
    
};

#endif /* TransformComponent_h */
