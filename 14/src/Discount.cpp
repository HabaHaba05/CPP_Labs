#include "../header/Discount.hpp"

Discount::Discount()
{
    this->next = nullptr;
}

void Discount::setNext(Discount *discount)
{
    this->next = discount;
}

FixedDiscount::FixedDiscount(double threshold, double discount)
    : Discount(), threshold(threshold), discount(discount)
{
}

double FixedDiscount::getPriceWithDiscount(const ShoppingCart &cart) const
{
    double cartPrice = cart.getCartPrice();
    if (cartPrice >= this->threshold)
    {
        return cartPrice - this->discount;
    }
    else if (this->next != nullptr)
    {
        return this->next->getPriceWithDiscount(cart);
    }

    return cartPrice;
}

RelativeDiscount::RelativeDiscount(double threshold, double discountPercentage)
    : Discount(), threshold(threshold), discountPercentage(discountPercentage)
{
}

double RelativeDiscount::getPriceWithDiscount(const ShoppingCart &cart) const
{
    double cartPrice = cart.getCartPrice();
    if (cartPrice >= this->threshold)
    {
        cartPrice *= (100 - this->discountPercentage) / 100;
    }
    else if (this->next != nullptr)
    {
        return this->next->getPriceWithDiscount(cart);
    }

    return cartPrice;
}
