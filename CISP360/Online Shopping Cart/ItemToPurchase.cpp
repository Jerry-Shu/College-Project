#include <iostream>
#include <string>
#include "ItemToPurchase.h"
using namespace std;
    ItemToPurchase::ItemToPurchase()
    {
        itemName = "none";
        itemPrice = 0;
        itemQuantity = 0;
    }
    ItemToPurchase::ItemToPurchase(string name, double price, int quantity)
    {

        itemName = name;
        itemPrice = price;
        itemQuantity = quantity;


    }
    void ItemToPurchase::setName(string name)
    {
        itemName = name;
    }
    void ItemToPurchase::setPrice(double price)
    {
        itemPrice = price;

    }
    void ItemToPurchase::setQuantity(int quantity)
    {
        itemQuantity = quantity;

    }
    string ItemToPurchase::getName() const
    {

        return itemName;

    }
    double ItemToPurchase::getPrice() const
    {
        return itemPrice;
    }
    int ItemToPurchase::getQuantity() const
    {
        return itemQuantity;

    }
    void ItemToPurchase::printItemCost()
    {

        cout << itemName << " " << itemQuantity << "@ $" << itemPrice << " = $" <<  itemPrice * itemQuantity << endl;


    }
