#include "../header/Apple.hpp"

int Apple::appleCount = 0;
int Apple::price = 1;

Apple::Apple(int weight, Date createdAt)
    : weight(weight), createdAt(createdAt)
{
    appleCount++;
}

Apple::~Apple()
{
    appleCount--;
}

// Getters
int Apple::getWeight() const
{
    return this->weight;
}

Date Apple::getCreatedAt() const
{
    return this->createdAt;
}