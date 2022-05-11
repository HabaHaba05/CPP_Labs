#pragma once

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    int radius;
public:
    Circle(Point<int>, int);
    virtual ~Circle();

    int getRadius() const;
    void setRadius(int);

    float area() const;
    float perimeter() const;

    void print() const;
    void draw(SDL_Renderer*) const;
};
