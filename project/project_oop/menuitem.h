#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include <string>
#include<iostream>
using namespace std;

class MenuItem // class of MenuItem with protected data members and public member functions
{
protected:
    int ItemID;
    string ItemName;
    string ItemDescription;
    double Price;
    int QuantityInStock;

public:
    MenuItem(); // default constructor
    MenuItem(int id, string name, string description, double price, int quantity); // parameterrized constructor

    void UpdateStock(int newQuantity);

    // Getters
    int GetItemID() const;
    string GetItemName() const;
    string GetItemDescription() const;
    double GetPrice() const;
    int GetQuantityInStock() const;

    // Setters
    void SetItemID(int id);
    void SetItemName(const string& name);
    void SetItemDescription(const string& description);
    void SetPrice(double price);
    void SetQuantityInStock(int quantity);
};
#endif