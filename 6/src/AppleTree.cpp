#include "../header/AppleTree.hpp"
#include "helpers.cpp"
#include <stdlib.h>
#include <time.h>
#include <stdexcept>

int AppleTree::treeCount = 0;

AppleTree::AppleTree(int newFruitsPerDayCount, int minFruitWeight, int maxFruitWeight)
    : newFruitsPerDayCount(newFruitsPerDayCount),
      minFruitWeight(minFruitWeight),
      maxFruitWeight(maxFruitWeight)
{
    treeCount++;
}

AppleTree::AppleTree(const std::vector<Apple *> apples, int newFruitsPerDayCount, int minFruitWeight, int maxFruitWeight)
    : newFruitsPerDayCount(newFruitsPerDayCount),
      minFruitWeight(minFruitWeight),
      maxFruitWeight(maxFruitWeight),
      apples(apples)
{
    treeCount++;
}

AppleTree::~AppleTree()
{
    clearVectorContent(this->apples);
    treeCount--;
}

// getters
int AppleTree::getNewFruitsPerDayCount() const
{
    return this->newFruitsPerDayCount;
}

std::vector<Apple *> AppleTree::getApples() const
{
    return this->apples;
}

// setters
void AppleTree::setNewFruitsPerDayCount(int newFruitsPerDayCount)
{
    this->newFruitsPerDayCount = newFruitsPerDayCount;
}

void AppleTree::setApples(const std::vector<Apple *> apples)
{
    clearVectorContent(this->apples);
    this->apples = apples;
}

// methods
void AppleTree::growFruit()
{
    srand(time(NULL));
    int weight = rand() % this->maxFruitWeight + this->minFruitWeight;

    this->apples.push_back(new Apple(weight, Date()));
}

void AppleTree::growFruitsForAllDay()
{
    for (size_t i = 0; i < this->newFruitsPerDayCount; i++)
    {
        growFruit();
    }
}

Apple *AppleTree::removeFruit()
{
    if (this->apples.size() == 0)
    {
        throw EmptyTreeException();
    }
    Apple *result = this->apples[0];

    this->apples.erase(this->apples.begin());

    return result;
}