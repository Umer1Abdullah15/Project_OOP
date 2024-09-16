#include "order.h"
#include "payment.h" 
#include <iostream>

Order::Order() : OrderID(0), CustomerID(0), ItemsOrdered(nullptr), TotalPrice(0.0), OrderStatus("Pending") {}

Order::Order(int id, int customerID)
    : OrderID(id), CustomerID(customerID), ItemsOrdered(nullptr), TotalPrice(0.0), OrderStatus("Pending") {}

Order::~Order() // deallocating
{
    delete[] ItemsOrdered;
}

void Order::AddItem(const MenuItem& item, int quantity)
{
    if (ItemsOrdered == nullptr)
    {
        ItemsOrdered = new MenuItem[1];
        ItemsOrdered[0] = item;
        TotalPrice = item.GetPrice();  // Update TotalPrice
    }
    else
    {
        MenuItem* newItemsOrdered = new MenuItem[GetNumItems() + 1];

        for (int i = 0; i < GetNumItems(); ++i)
        {
            newItemsOrdered[i] = ItemsOrdered[i];
        }

        newItemsOrdered[GetNumItems()] = item;
        delete[] ItemsOrdered; // deallocating

        ItemsOrdered = newItemsOrdered;
        TotalPrice += item.GetPrice();
    }

    cout << "\nItem added to the order" << endl;
}


void Order::RemoveItem(const MenuItem& item) 
{
    if (ItemsOrdered != nullptr) 
    {
        int numItems = 1; 

        bool itemFound = false;
        for (int i = 0; i < numItems; ++i) 
        {
            if (ItemsOrdered[i].GetItemID() == item.GetItemID()) 
            {
                itemFound = true;

                for (int j = i; j < numItems - 1; ++j) 
                {
                    ItemsOrdered[j] = ItemsOrdered[j + 1];
                }

                numItems--;

                MenuItem* newItemsOrdered = new MenuItem[numItems];
                for (int j = 0; j < numItems; ++j) 
                {
                    newItemsOrdered[j] = ItemsOrdered[j];
                }
                delete[] ItemsOrdered; // deallocating


                ItemsOrdered = newItemsOrdered;

                cout << "Item removed from the order" << endl;
                break; 
            }
        }

        if (!itemFound) 
        {
            cout << "Item not found in the order. Nothing to remove" << endl;
        }
    }
    else 
    {
        cout << "Order is empty. Nothing to remove." << endl;
    }
}

double Order::CalculateTotal() 
{
    if (ItemsOrdered != nullptr) 
    {
        int numItems = 1; 

        for (int i = 0; i < numItems; ++i) 
        {
            TotalPrice += ItemsOrdered[i].GetPrice();
        }
        return TotalPrice;
    }
    else 
    {
        cout << "Order is empty. Total price is 0" << endl;
        return 0.0;
    }
}

void Order::ConfirmOrder() 
{
    if (ItemsOrdered != nullptr) 
    {

        Payment payment(OrderID, CustomerID, TotalPrice);
        if (payment.ProcessPayment()) 
        {           
            OrderStatus = "Confirmed";
            cout << "Order confirmed. Payment processed successfully" << endl;
        }
        else 
        {
            OrderStatus = "Payment Failed";
            cout << "Order confirmation failed. Payment processing failed" << endl;
        }
    }
    else 
    {
        cout << "Order is empty. Cannot confirm an empty order" << endl;
    }
}

void Order::CancelOrder() 
{
    if (ItemsOrdered != nullptr) 
    {
        Payment payment(OrderID, CustomerID, TotalPrice);
        if (payment.ProcessPayment())
        {
            OrderStatus = "Canceled";
            cout << "Order canceled. Refunding payment" << endl;
        }
        else 
        {
            OrderStatus = "Cancellation Failed";
            cout << "Order cancellation failed. Refund process failed" << endl;
        }

        delete[] ItemsOrdered; // deallocating
        ItemsOrdered = nullptr;
    }
    else 
    {
        cout << "Order is already empty. Nothing to cancel" << endl;
    }
}


// Getter methods
int Order::GetOrderID() const 
{
    return OrderID;
}

int Order::GetCustomerID() const 
{
    return CustomerID;
}

const MenuItem* Order::GetItemsOrdered() const 
{
    return ItemsOrdered;
}

double Order::GetTotalPrice() const 
{
    return TotalPrice;
}

string Order::GetOrderStatus() const 
{
    return OrderStatus;
}

int Order::GetNumItems() const 
{
    return 15; 
}

bool Order::IsTableReservation() const
{
    return isTableReservation;
}

// Setter methods
void Order::SetOrderID(int id) 
{
    OrderID = id;
}

void Order::SetCustomerID(int customerID) 
{
    CustomerID = customerID;
}

void Order::SetItemsOrdered(MenuItem* items) 
{
    ItemsOrdered = items;
}

void Order::SetTotalPrice(double totalPrice) 
{
    TotalPrice = totalPrice;
}

void Order::SetOrderStatus(const string& orderStatus) 
{
    OrderStatus = orderStatus;
}

void Order::SetTableReservation(bool reservation)
{
    isTableReservation = reservation;
}