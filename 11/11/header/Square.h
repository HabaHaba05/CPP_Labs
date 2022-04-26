#pragma once

#include "Rectangle.h"

class Square : public Rectangle {
public:
    Square(Point<int>, int);
    Square(Point<int>, Point<int>);
};