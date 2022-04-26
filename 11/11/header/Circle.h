#pragma once

#include "Shape.h"
#include <cmath>

class Circle : public Shape {
private:
    int radius;
public:
    Circle(Point<int>, int);

    int getRadius() const;
    void setRadius(int);
    Point<int> getCenterPoint() const;
    void setCenterPoint(Point<int>);

    float area() const;
    float perimeter() const;

    void print() const;

    void draw(SDL_Renderer*) const;
};
