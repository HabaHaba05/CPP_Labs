#include "../header/Rectangle.h"
#include <map>

Rectangle::Rectangle(Point<int> topLeftPoint, Point<int> bottomRightPoint) 
    : Shape(topLeftPoint) {
    Point<int> diff = bottomRightPoint - topLeftPoint;
    if(diff.x <= 0 || diff.y <= 0) {
        throw std::invalid_argument("BottomRightPoint values must be higher than TopLeftPoint");
    }
    this->bottomRightPoint = bottomRightPoint;
}

Rectangle::Rectangle(Point<int> topLeftPoint, int w, int h) 
    : Shape(topLeftPoint) {
    this->bottomRightPoint = topLeftPoint + Point<int>(w, h);
}

Rectangle::~Rectangle(){
    std::cout << "Rect destroyed\n";
}

Point<int> Rectangle::getBottomRightPoint() const {
    return this->bottomRightPoint;
}

void Rectangle::setBottomRightPoint(Point<int> bottomRightPoint) {
    this->bottomRightPoint = bottomRightPoint;
}

float Rectangle::area() const {
    std::pair<int, int> dim = this->getDimensions();
    return dim.first * dim.second;
}

float Rectangle::perimeter() const {
    std::pair<int,int> dim = this->getDimensions();
    return 2 * (dim.first + dim.second);
}

std::pair<int, int> Rectangle::getDimensions() const {
    Point<int> topLeftPoint = this->getPoint();
    return { bottomRightPoint.x - topLeftPoint.x, bottomRightPoint.y - topLeftPoint.y };
}

void Rectangle::print() const {
    std::cout << "Top left: ";
    Shape::print();
    std::cout << "Bottom right: " << this->bottomRightPoint << std::endl;
}


void Rectangle::draw(SDL_Renderer* renderer) const {
    Point<int> topLeftPoint = this->getPoint();
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawLine(renderer, this->bottomRightPoint.x, topLeftPoint.y, this->bottomRightPoint.x, this->bottomRightPoint.y);
    SDL_RenderDrawLine(renderer, topLeftPoint.x, this->bottomRightPoint.y, this->bottomRightPoint.x, this->bottomRightPoint.y);
    SDL_RenderDrawLine(renderer, topLeftPoint.x, topLeftPoint.y, this->bottomRightPoint.x, topLeftPoint.y);
    SDL_RenderDrawLine(renderer, topLeftPoint.x, topLeftPoint.y, topLeftPoint.x, this->bottomRightPoint.y);
    SDL_RenderPresent(renderer);
}
