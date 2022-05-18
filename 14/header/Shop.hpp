#pragma once
#include <iostream>
#include "ShoppingCart.hpp"
#include "Discount.hpp"
#include "Item.hpp"
#include <vector>
using namespace std;

class Shop
{
private:
    vector<Item> items;
    Discount *discount;

public:
    Shop();
    Shop(Discount *discount);

    void setDiscount(Discount *discount);
    void addItem(Item item);
    double calculateCartPrice(const ShoppingCart &) const;
};