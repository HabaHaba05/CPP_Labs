#include "../header/ShoppingCart.hpp"
#include <string>
#include <sstream>
#include <numeric>
#include <algorithm>

ShoppingCart::ShoppingCart()
{
}

ShoppingCart::ShoppingCart(vector<Item> items)
    : items(items)
{
}

vector<Item> ShoppingCart::getItems() const
{
    return this->items;
}

double ShoppingCart::getCartPrice() const
{
    double price = 0;
    for_each(items.begin(), items.end(), [&price](Item item)
             { price += item.getPrice(); });
    return price;
}

void ShoppingCart::addItem(Item item)
{
    this->items.push_back(item);
}

string ShoppingCart::toString() const
{
    stringstream ss;
    ss << "ShoppingCart:{\n";
    for (Item item : items)
    {
        ss << item.toString() << endl;
    }
    ss << "}";

    return ss.str();
}