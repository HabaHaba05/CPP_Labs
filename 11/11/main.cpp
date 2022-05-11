#include <iostream>
#include <SDL.h>
#include <SDL_timer.h>
#include "header/Square.h"
#include "header/Rectangle.h"
#include "header/Circle.h"
#include "header/Shape.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

int sign(int val) {
    return val >= 0 ? 1 : -1;
}

void sdlLoop(vector<Shape*>&);
void handleKeyDown(const SDL_Keycode, Shape**, vector<Shape*>&);
void handleMouseDown(const SDL_Event&, Shape*);
void handleMouseUp(const SDL_Event&, Shape**, vector<Shape*>&);
void handleMouseMotion(const SDL_MouseMotionEvent&, Shape*);
void resizeAllCircles(vector<Shape*>&, float);

int main(int argc, char *argv[]) {

    Rectangle *rectangle = new Rectangle(Point<int>(10, 10), Point<int>(100, 120));
    Circle *circle = new Circle(Point<int>(325, 325), 100);
    Square *square = new Square(Point<int>(400, 400), Point<int>(450, 450));

    cout << "Rectangle" <<endl;
    rectangle->print();
    cout << rectangle->perimeter() << " " << rectangle->area() << endl;

    cout << "Circle" <<endl;
    circle->print();
    cout << circle->perimeter() << " " << circle->area() << endl;

    cout << "Square" <<endl;
    square->print();
    cout << square->perimeter() << " " << square->area() << endl;


    vector<Shape*> shapes;
    shapes.push_back(rectangle);
    shapes.push_back(circle);
    shapes.push_back(square);

    sdlLoop(shapes);

    float totalArea = accumulate(shapes.begin(),shapes.end(),0, [](float acc, Shape* shape)
                        { return acc + shape->area(); });

    cout<<"Total area: "<< totalArea << endl;

    return 0;
}

void sdlLoop(vector<Shape*>& shapes) {
    // variables
    bool quit = false;
    SDL_Event event;
    Shape* newShape = nullptr;

    // init SDL
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    // handle events
    while (!quit)
    {
        SDL_Delay(50);
        SDL_PollEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                handleKeyDown(event.key.keysym.sym, &newShape,shapes);
                break;
            case SDL_MOUSEBUTTONDOWN:
                handleMouseDown(event, newShape);
                break;
            case SDL_MOUSEBUTTONUP:
                handleMouseUp(event, &newShape, shapes);
                break;
            case SDL_MOUSEMOTION:
                handleMouseMotion(event.motion, newShape);
                break;
            default:
                break;
        }

        // clear window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // TODO rendering code goes here
        std::for_each(shapes.begin(), shapes.end(), [renderer](Shape* x) {x->draw(renderer); });
        if (newShape != nullptr && newShape->getPoint().x !=0) {
            newShape->draw(renderer);
        }
        // render window
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void handleKeyDown(const SDL_Keycode sym, Shape** newShape, vector<Shape*>& shapes) {
    switch (sym) {
        case SDLK_c:
            *newShape = new Circle(Point<int>(0,0), 0);
            break;
        case SDLK_r:
            *newShape = new Rectangle(Point<int>(0, 0), 1, 1);
            break;
        case SDLK_s:
            *newShape = new Square(Point<int>(0, 0), 1);
            break;
        case SDLK_UP:
            resizeAllCircles(shapes, 1.3);
            break;
        case SDLK_DOWN:
            resizeAllCircles(shapes, 0.7);
            break;
        default:
            break;
    }
};

void handleMouseDown(const SDL_Event& event, Shape* newShape) {
    if (newShape == nullptr) {
        return;
    }
    
    if (event.button.button) {
        newShape->setPoint(Point<int>(event.motion.x, event.motion.y));
    }
}

void handleMouseUp(const SDL_Event& event, Shape** newShape, vector<Shape*>& shapes) {
    if (*newShape == nullptr) {
        return;
    }

    if (event.button.button == SDL_BUTTON_LEFT) {
        shapes.push_back(*newShape);
        *newShape = nullptr;
    }
}

void handleMouseMotion(const SDL_MouseMotionEvent& event, Shape* newShape) {
    if (newShape == nullptr) {
        return;
    }

    Circle* circle{ dynamic_cast<Circle*>(newShape) };
    Square* square{ dynamic_cast<Square*>(newShape) };
    Rectangle* rect{ dynamic_cast<Rectangle*>(newShape) };
    Point<int> clickedPoint = Point<int>(event.x, event.y);

    if (square != nullptr) {
        Point<int> diff = clickedPoint - square->getPoint();
        int distance = sqrt(diff.x * diff.x + diff.y * diff.y);
        square->setBottomRightPoint(Point<int>(square->getPoint().x + distance * sign(diff.x) , square->getPoint().y + distance * sign(diff.y)));
    }
    else if (rect != nullptr) {
        rect->setBottomRightPoint(Point<int>(event.x, event.y));
    }else if (circle != nullptr) {
        Point<int> diff = circle->getPoint() - clickedPoint;
        int radius = sqrt(diff.x * diff.x + diff.y * diff.y);
        circle->setRadius(radius);
    }
}

void resizeAllCircles(vector<Shape*>& shapes, float coef) {
    for(Shape* shape : shapes){
        Circle* circle{ dynamic_cast<Circle*>(shape) };
        if (circle != nullptr) {
            circle->setRadius(circle->getRadius() * coef);
        }
    }
}
