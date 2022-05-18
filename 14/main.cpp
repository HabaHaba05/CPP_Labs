#include <iostream>
#include "header/Item.hpp"
#include "header/ShoppingCart.hpp"
#include "header/Discount.hpp"
#include "header/Shop.hpp"

using namespace std;

int main()
{
    Item a(10, "abc", "oh");
    cout << a.toString() << endl;

    ShoppingCart cart;
    cart.addItem(a);
    cart.addItem(a);

    cout << "Price:" << cart.getCartPrice() << endl;
    cout << "Price:" << cart.toString() << endl;

    FixedDiscount *fDiscount = new FixedDiscount(10, 5);
    RelativeDiscount *rDiscount = new RelativeDiscount(10, 90);

    cout << fDiscount->getPriceWithDiscount(cart) << endl;
    cout << rDiscount->getPriceWithDiscount(cart) << endl;

    cout << "--------\n";
    Shop shop;
    // Adding items but I wont use them...
    // writing some getters wont teach me anything new...
    shop.addItem(a);
    shop.addItem(a);
    shop.addItem(Item(20, "nzn", "op"));
    shop.addItem(Item(30, "nzn", "op"));
    // No discount
    cout << shop.calculateCartPrice(cart) << endl;

    shop.setDiscount(fDiscount);
    cout << shop.calculateCartPrice(cart) << endl;

    shop.setDiscount(rDiscount);
    cout << shop.calculateCartPrice(cart) << endl;

    // Chain.
    cout << "Chain" << endl;

    FixedDiscount *fd1 = new FixedDiscount(100, 20);
    FixedDiscount *fd2 = new FixedDiscount(50, 10);
    FixedDiscount *fd3 = new FixedDiscount(10, 2);
    fd1->setNext(fd2);
    fd2->setNext(fd3);

    RelativeDiscount *rd1 = new RelativeDiscount(100, 20);
    RelativeDiscount *rd2 = new RelativeDiscount(50, 10);
    RelativeDiscount *rd3 = new RelativeDiscount(10, 2);
    rd1->setNext(rd2);
    rd2->setNext(rd3);

    cart.addItem(Item(30, "nzn", "op"));
    cart.addItem(Item(-40, "nzn", "op"));
    shop.setDiscount(nullptr);
    cout << "Without discount: " << shop.calculateCartPrice(cart) << endl;

    shop.setDiscount(fd1);
    cout << "Fixed discount: " << shop.calculateCartPrice(cart) << endl;

    shop.setDiscount(rd1);
    cout << "Relative discount: " << shop.calculateCartPrice(cart) << endl;
};