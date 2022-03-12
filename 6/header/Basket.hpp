#pragma once
#include <vector>
#include "Apple.hpp"

class Basket
{
private:
    const int maxWeight;
    std::vector<Apple *> items;

public:
    Basket() = delete;
    Basket(int);
    ~Basket();

    // getters
    int getMaxWeight();
    std::vector<Apple *> getItems();

    // methods
    int getBasketWeight();
    int getPriceOfAllFruits();
    void addFruit(Apple *);
    void emptyBasket();
};

class FullBasketException : public std::exception
{
    const char *what() const throw()
    {
        return "Basket is full";
    }
};