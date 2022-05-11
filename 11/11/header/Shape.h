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
    virtual ~Shape();

    void setPoint(Point<int>);
    Point<int> getPoint() const;

    void print() const;

    virtual float area() const = 0;
    virtual float perimeter() const = 0;
    virtual void draw(SDL_Renderer*) const = 0;
};