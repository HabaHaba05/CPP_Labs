#include "../header/Item.hpp"
#include <string>
#include <sstream>

Item::Item(double price, string title, string category)
    : price(price), title(title), category(category)
{
}

string Item::getTitle() const
{
    return this->title;
}

string Item::getCategory() const
{
    return this->category;
}

double Item::getPrice() const
{
    return this->price;
}

string Item::toString() const
{
    std::stringstream ss;
    ss << "Item:{'Price':" << this->price;
    ss << ", 'Title':" << this->title;
    ss << ", 'Category':" + this->category + "}";

    return ss.str();
}