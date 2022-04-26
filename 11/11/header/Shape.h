#pragma once 

#include "Point.h"
#include <iostream>
#include <SDL.h>

class Shape {
private:
    Point<int> point;
public:
    Shape();
    Shape(int, int);
    Shape(Point<int>);

    void setPoint(Point<int>);
    Point<int> getPoint() const;

    void print() const;
    virtual void draw(SDL_Renderer* renderer) const = 0;
};