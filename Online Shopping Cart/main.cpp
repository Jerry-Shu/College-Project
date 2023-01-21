// Program    : Assignment Part 1: Online shopping cart
// Author     : Jiarui.Shu
// Date       : 4/24/2021
// Description: Online shopping cart
//
//
//
//

#include<iostream>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iomanip>
#include <string>

using namespace std;


int main()
{
    ItemToPurchase first;
    ItemToPurchase second;
    ItemToPurchase third;


    string person_name;
    string itemName;
    double itemPrice;
    int itemQuantity;
     cout << fixed << setprecision(2);
    cout << "Name:  ";
    getline(cin, person_name);

    ShoppingCart wholeShoppingCart(person_name);





    //first one
    cout << "Enter the item name:" << endl;
    getline(cin, itemName);

    cout << "Enter the item price:" << endl;
    cin >> itemPrice;

    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity;

    first.setName(itemName);
    first.setPrice(itemPrice);
    first.setQuantity(itemQuantity);

    wholeShoppingCart.addItem(first);
    cin.ignore();
    cout << endl;

    //second one

    cout << "Enter the item name:" << endl;
    getline(cin, itemName);

    cout << "Enter the item price:" << endl;
    cin >> itemPrice;

    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity;

    second.setName(itemName);
    second.setPrice(itemPrice);
    second.setQuantity(itemQuantity);

     wholeShoppingCart.addItem(second);

     cin.ignore();
     cout << endl;

     //third one

     cout << "Enter the item name:" << endl;
    getline(cin, itemName);

    cout << "Enter the item price:" << endl;
    cin >> itemPrice;

    cout << "Enter the item quantity:" << endl;
    cin >> itemQuantity;
    cout << endl;

    third.setName(itemName);
    third.setPrice(itemPrice);
    third.setQuantity(itemQuantity);

     wholeShoppingCart.addItem(third);

     cin.ignore();


    wholeShoppingCart.printCart();
  return 0;
}
