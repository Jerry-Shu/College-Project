#ifndef ITEMTOPURCHASE_H_INCLUDED
#define ITEMTOPURCHASE_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;
class ItemToPurchase
{
public:
    ItemToPurchase();
    ItemToPurchase(string name, double price, int quantity);
    void setName(string);
    void setPrice(double);
    void setQuantity(int);
    string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void printItemCost();
private:

    string itemName;
    double itemPrice;
    int itemQuantity;

};


#endif // ITEMTOPURCHASE_H_INCLUDED
