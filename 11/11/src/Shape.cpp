#include "../header/Shape.h"

Shape::Shape() {
    this->point = Point<int>(50, 50);
}

Shape::Shape(int x, int y) {
    this->point = Point<int>(x, y);
}

Shape::Shape(Point<int> point) {
    this->point = point;
}

Shape::~Shape() {
    std::cout << "Shape destroyed\n";
}

void Shape::setPoint(Point<int> point) {
    this->point = point;
}

Point<int> Shape::getPoint() const {
    return this->point;
}

void Shape::print() const {
    std::cout << this->point << std::endl;
}