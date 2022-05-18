#pragma once
#include <iostream>
using namespace std;

class Item
{
private:
    double price;
    string title;
    string category;

public:
    Item() = delete;
    Item(double price, string title, string category);

    string getTitle() const;
    string getCategory() const;
    double getPrice() const;

    string toString() const;
};