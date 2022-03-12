#pragma once
#include "Basket.hpp"
#include "AppleTree.hpp"

class Picker
{
private:
    int fruitsPerDayMaxCount;
    int todayCollected;
    int money;
    Basket *basket;

public:
    Picker() = delete;
    Picker(int, Basket *);
    ~Picker();

    // getters
    int getFruitsPerDayMaxCount() const;
    int getTodayColected() const;
    Basket *getBasket() const;
    int getMoney() const;
    // setters
    void setFruitsPerDayMaxCount(int);

    // methods
    void collectFruit(AppleTree &tree);
    void sellFruits();
};

class PickerHasNoEnergyException : public std::exception
{
    const char *what() const throw()
    {
        return "Picker already collected his maximum count of fruits";
    }
};