#include "../header/Circle.h"

Circle::Circle(Point<int> point, int radius) 
    : Shape(point) {
    this->radius = radius;
}

Circle::~Circle() {
    std::cout << "Circle destroyed\n";
}

void Circle::setRadius(int radius) {
    this->radius = radius;
}

int Circle::getRadius() const {
    return this->radius;
}

float Circle::area() const {
    return M_PI * pow(this->radius, 2);
}

float Circle::perimeter() const {
    return 2 * M_PI * this->radius;
}

void Circle::print() const {
    std::cout << "Center: ";
    Shape::print();
    std::cout << "Radius: " << this->radius << std::endl;
}

void Circle::draw(SDL_Renderer* renderer) const{
    double step = 2 * M_PI / 360;

    int cX = this->getPoint().x;
    int cY = this->getPoint().y;

    int x = cX + this->radius * cos(0);
    int y = cY - this->radius * sin(0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for(double angle = step; angle < 2 * M_PI; angle += step) {
        
        int xNext = cX + this->radius * cos(angle);
        int yNext = cY - this->radius * sin(angle);

        SDL_RenderDrawLine(renderer, x, y, xNext, yNext);

        x = xNext;
        y = yNext;
    }

    SDL_RenderPresent(renderer);
}