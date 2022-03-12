#include "../header/Picker.hpp"

Picker::Picker(int fruitsPerDayMaxCount, Basket *basket)
    : fruitsPerDayMaxCount(fruitsPerDayMaxCount),
      basket(basket)
{
    money = 0;
    todayCollected = 0;
}

Picker::~Picker()
{
    delete basket;
}

// getters
int Picker::getFruitsPerDayMaxCount() const
{
    return this->fruitsPerDayMaxCount;
}

Basket *Picker::getBasket() const
{
    return this->basket;
}

int Picker::getTodayColected() const
{
    return this->todayCollected;
}

int Picker::getMoney() const
{
    return this->money;
}

// setters
void Picker::setFruitsPerDayMaxCount(int fruitsPerDayMaxCount)
{
    this->fruitsPerDayMaxCount = fruitsPerDayMaxCount;
}

// methods
void Picker::sellFruits()
{
    this->money += this->basket->getPriceOfAllFruits();
    this->basket->emptyBasket();
}

void Picker::collectFruit(AppleTree &tree)
{
    if (this->todayCollected == this->fruitsPerDayMaxCount)
    {
        throw PickerHasNoEnergyException();
    }

    Apple *apple = tree.removeFruit();
    if (this->basket->getMaxWeight() < this->basket->getBasketWeight() + apple->getWeight())
    {
        this->money += this->basket->getPriceOfAllFruits();
        this->basket->emptyBasket();
    }
    this->basket->addFruit(apple);
    ++(this->todayCollected);
}