#ifndef SHOPPINGCART_H_INCLUDED
#define SHOPPINGCART_H_INCLUDED
#include<iostream>
#include <string>
#include <vector>
#include"ItemToPurchase.h"
using namespace std;

class ShoppingCart
{
public:
    ShoppingCart();
    ShoppingCart(string name);
    string getCustomerName() const;
    void addItem(ItemToPurchase);
    void removeItem(string);
    void changeQuantity(string, int);
    double getTotalCost();
    void printCart();
private:
    string customerName;
    vector<ItemToPurchase> cartItems;
};
#endif // SHOPPINGCART_H_INCLUDED
