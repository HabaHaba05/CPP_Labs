#pragma once
#include <iostream>
#include "ShoppingCart.hpp"
using namespace std;

class Discount
{
protected:
    Discount *next;

public:
    Discount();
    virtual double getPriceWithDiscount(const ShoppingCart &) const = 0;
    void setNext(Discount *);
};

class FixedDiscount : public Discount
{
private:
    double threshold;
    double discount;

public:
    FixedDiscount(double threshold, double discount);
    double getPriceWithDiscount(const ShoppingCart &) const;
};

class RelativeDiscount : public Discount
{
private:
    double threshold;
    double discountPercentage;

public:
    RelativeDiscount(double threshold, double discountPercentage);
    double getPriceWithDiscount(const ShoppingCart &) const;
};