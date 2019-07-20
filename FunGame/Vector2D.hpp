//
//  Vector2D.hpp
//  FunGame
//
//  Created by stanley pena on 7/20/19.
//  Copyright © 2019 stanley pena. All rights reserved.
//

#ifndef Vector2D_hpp
#define Vector2D_hpp

#include <iostream>

using namespace std;

class Vector2D {
    
public:
    float x;
    float y;
    
    Vector2D();
    Vector2D(float x, float y);
    
    Vector2D& add(const Vector2D& vec);
    Vector2D& subtract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);
    
    friend Vector2D& operator+(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(const Vector2D& v1, const Vector2D& v2);
    
    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);
    

    friend ostream& operator<<(ostream& stream, const Vector2D& vec);

};

#endif /* Vector2D_hpp */
