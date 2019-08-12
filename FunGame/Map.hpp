//
//  Map.hpp
//  FunGame
//
//  Created by stanley pena on 7/19/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <string>

using namespace std;

class Map {
    
public:
    Map();
    ~Map();
    
  static void loadMap(string path, int sizeX, int sizeY);
    
private:
    
};

#endif /* Map_hpp */
