#pragma once
#include <vector>
#include "Apple.hpp"

class AppleTree
{
private:
    int newFruitsPerDayCount;
    std::vector<Apple *> apples;
    const int maxFruitWeight;
    const int minFruitWeight;

public:
    static int treeCount;

    AppleTree() = delete;
    AppleTree(int newFruitsPerDayCount = 0, int minFruitWeight = 5, int maxFruitWeight = 10);
    AppleTree(const std::vector<Apple *>, int newFruitsPerDayCount = 0, int minFruitWeight = 5, int maxFruitWeight = 10);
    ~AppleTree();

    // getters
    int getNewFruitsPerDayCount() const;
    std::vector<Apple *> getApples() const;

    // setters
    void setNewFruitsPerDayCount(int);
    void setApples(const std::vector<Apple *>);

    // methods
    void growFruit();
    void growFruitsForAllDay();
    Apple *removeFruit();
};

class EmptyTreeException : public std::exception
{
    const char *what() const throw()
    {
        return "There are no fruits on tree";
    }
};