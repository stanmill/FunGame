//
//  Components.cpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//
#ifndef Components_hpp
#define Components_hpp

#include "ECS.hpp"
#include <iostream>

class PositionComponent : public Component {
public:
    int x() {return xpos;}
    int y() {return ypos;}
    
    void init() override {
        xpos = 0;
        ypos = 0;
    }
    
    void update() override {
        xpos++;
        ypos++;
    }
    void setPos(int x, int y){
        xpos = x;
        ypos = y;
    }

    
private:
    int xpos;
    int ypos;
};

#endif /* Components_hpp */
