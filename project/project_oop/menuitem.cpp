#include "menuItem.h"
#include <iostream>

MenuItem::MenuItem() : ItemID(0), Price(0), QuantityInStock(0) 
{
    ItemName = "";
    ItemDescription = "";
}

MenuItem::MenuItem(int id, string name, string description, double price, int quantity) : ItemID(id), ItemName(name), ItemDescription(description), Price(price), QuantityInStock(quantity) {}

void MenuItem::UpdateStock(int newQuantity) 
{
    if (newQuantity >= 0) 
    {
        QuantityInStock = newQuantity;
        cout << "Item stock updated successfully. New quantity: " << QuantityInStock << endl;
    }
    else 
    {
        cout << "Invalid stock quantity. Stock quantity remains unchanged." << endl;
    }
}


// GETTERS
double MenuItem::GetPrice() const 
{
    return Price;
}

int MenuItem::GetItemID() const 
{
    return ItemID;
}

std::string MenuItem::GetItemName() const 
{
    return ItemName;
}

std::string MenuItem::GetItemDescription() const 
{
    return ItemDescription;
}

int MenuItem::GetQuantityInStock() const 
{
    return QuantityInStock;
}

// SETTERS  
void MenuItem::SetItemID(int id) 
{
    ItemID = id;
}

void MenuItem::SetItemName(const string& name) 
{
    ItemName = name;
}

void MenuItem::SetItemDescription(const string& description) 
{
    ItemDescription = description;
}

void MenuItem::SetPrice(double price) 
{
    Price = price;
}

void MenuItem::SetQuantityInStock(int quantity) 
{
    QuantityInStock = quantity;
}