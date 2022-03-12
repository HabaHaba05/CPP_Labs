#include "../header/Basket.hpp"
#include "helpers.cpp"

Basket::Basket(int maxWeight)
    : maxWeight(maxWeight)
{
}

Basket::~Basket()
{
    clearVectorContent(this->items);
}

// getters
int Basket::getMaxWeight()
{
    return this->maxWeight;
}

std::vector<Apple *> Basket::getItems()
{
    return this->items;
}

// methods
int Basket::getBasketWeight()
{
    int weight = 0;
    for (size_t i = 0; i < this->items.size(); i++)
    {
        weight += this->items[i]->getWeight();
    }
    return weight;
}

void Basket::addFruit(Apple *item)
{
    if (this->getBasketWeight() + item->getWeight() <= this->maxWeight)
    {

        this->items.push_back(item);
    }
    else
    {
        throw FullBasketException();
    }
}

int Basket::getPriceOfAllFruits()
{
    int sum = 0;
    for (size_t i = 0; i < this->items.size(); i++)
    {
        sum += this->items[i]->price;
    }
    return sum;
}

void Basket::emptyBasket()
{
    clearVectorContent(this->items);
}
