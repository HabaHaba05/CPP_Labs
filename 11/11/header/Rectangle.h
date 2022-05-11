#pragma once

#include "Shape.h"

class Rectangle : public Shape {
private:
    Point<int> bottomRightPoint;

    std::pair<int, int> getDimensions() const;
public:
    Rectangle(Point<int>, Point<int>);
    Rectangle(Point<int>, int, int);
    virtual ~Rectangle();

    void setBottomRightPoint(Point<int>);
    Point<int> getBottomRightPoint() const;

    float area() const;
    float perimeter() const;
    void print() const;
    void draw(SDL_Renderer*) const;
};