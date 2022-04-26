#include <iostream>
#include <SDL.h>
#include <SDL_timer.h>
#include "header/Square.h"
#include "header/Rectangle.h"
#include "header/Circle.h"
#include "header/Shape.h"
#include <vector>
#include <algorithm>

using namespace std;

void sdlLoop(const vector<Shape*>& shapes);

int main(int argc, char *argv[]) {

    Rectangle *rectangle = new Rectangle(Point<int>(10, 10), Point<int>(100, 120));
    Circle *circle = new Circle(Point<int>(325, 325), 50);
    Square *square = new Square(Point<int>(200, 200), Point<int>(250, 250));

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

    return 0;
}

void sdlLoop(const vector<Shape*>& shapes) {
    // variables
    bool quit = false;
    SDL_Event event;

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
            default:
                break;
        }

        // clear window
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        // TODO rendering code goes here
        std::for_each(shapes.begin(), shapes.end(), [renderer](Shape* x) {x->draw(renderer); });

        // render window
        SDL_RenderPresent(renderer);
    }

    // cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}