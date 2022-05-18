#include "../header/Shop.hpp"

Shop::Shop()
    : discount(nullptr)
{
}

Shop::Shop(Discount *discount)
    : discount(discount)
{
}

void Shop::setDiscount(Discount *discount)
{
    this->discount = discount;
}

void Shop::addItem(Item item)
{
    this->items.push_back(item);
}

double Shop::calculateCartPrice(const ShoppingCart &cart) const
{
    if (this->discount != nullptr)
    {
        return this->discount->getPriceWithDiscount(cart);
    }
    return cart.getCartPrice();
}