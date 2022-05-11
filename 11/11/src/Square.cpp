#include "../header/Square.h"

Square::Square(Point<int> point, int length)
    : Rectangle(point, length, length) {}

Square::Square(Point<int> topLeftPoint, Point<int> bottomRightPoint) 
    : Rectangle(topLeftPoint, bottomRightPoint) {
    Point<int> diff = bottomRightPoint - topLeftPoint;
    if (diff.x != diff.y) {
        throw std::invalid_argument("It's rectangle, but not square!!!");
    }
}


Square::~Square() {
    std::cout << "Square destroyed\n";
}