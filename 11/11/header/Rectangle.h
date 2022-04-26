#pragma once

#include "Shape.h"

class Rectangle : public Shape {
private:
    Point<int> bottomRightPoint;

    std::pair<int, int> getDimensions() const;
public:
    Rectangle(Point<int>, Point<int>);
    Rectangle(Point<int>, int, int);

    void setBottomRightPoint(Point<int>);
    Point<int> getBottomRightPoint() const;
    void setTopLeftPoint(Point<int>);
    Point<int> getTopLeftPoint() const;

    int area() const;
    int perimeter() const;

    void print() const;
    void draw(SDL_Renderer*) const;
};