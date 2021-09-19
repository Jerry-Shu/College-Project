#include<iostream>
#include <string>
#include "ShoppingCart.h"
ShoppingCart::ShoppingCart()
{
    customerName = "NoName";
    vector<ItemToPurchase> cartItems(0);
}
ShoppingCart::ShoppingCart(string name)
{
    customerName = name;
}
void ShoppingCart::addItem(ItemToPurchase a)
{
    cartItems.push_back(a);
}
void ShoppingCart::removeItem(string remove_item)
{
    size_t i;
    for( i = 0; i < cartItems.size();i++ )
    {
        if(cartItems[i].getName() == remove_item)
        {
            cartItems.erase(cartItems.begin() + i);
        }
    }
    if(i == cartItems.size())
    {
        cout << "Item not found in cart. Nothing modified." << endl;

    }
}
double ShoppingCart::getTotalCost()
{
    double sum = 0;
    for(size_t i = 0; i < cartItems.size();i++)
    {
        sum += cartItems[i].getQuantity() * cartItems[i].getPrice();
    }
    return sum;
}
void ShoppingCart::printCart()
{
    cout << customerName << "'s Shopping Cart" << endl;
    for(size_t i = 0 ; i < cartItems.size(); i++)
    {
             cartItems[i].printItemCost();
    }
    cout << "Total: $" << getTotalCost() << endl;
}
string ShoppingCart::getCustomerName() const
{
    return customerName;
}
void ShoppingCart::changeQuantity(string name, int new_quantity)
{
    for(size_t i = 0; i < cartItems.size();i++)
    {

        if(cartItems[i].getName() == name)
        {
            cartItems[i].setQuantity(new_quantity);
        }
    }
}
