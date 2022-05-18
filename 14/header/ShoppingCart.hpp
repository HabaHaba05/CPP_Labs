#pragma once
#include <iostream>
#include "Item.hpp"
#include <vector>
using namespace std;

class ShoppingCart
{
private:
    vector<Item> items;

public:
    ShoppingCart();
    ShoppingCart(vector<Item> items);

    vector<Item> getItems() const;
    double getCartPrice() const;

    void addItem(Item item);

    string toString() const;
};