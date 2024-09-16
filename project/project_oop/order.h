#ifndef ORDER_H
#define ORDER_H

#include "menuitem.h"

class Order  // class of Order with protected data members and public member functions
{
protected:
    int OrderID;
    int CustomerID;
    MenuItem* ItemsOrdered;
    double TotalPrice;
    string OrderStatus;
    bool isTableReservation;

public:
    Order(); // default constructor
    Order(int id, int customerID); // parameterrized constructor
    ~Order(); // destructor

    // Getters
    int GetOrderID() const;
    int GetCustomerID() const;
    const MenuItem* GetItemsOrdered() const;
    double GetTotalPrice() const;
    string GetOrderStatus() const;
    int GetNumItems() const;
    bool IsTableReservation() const;

    // Setters
    void SetOrderID(int id);
    void SetCustomerID(int customerID);
    void SetItemsOrdered(MenuItem* items);
    void SetTotalPrice(double totalPrice);
    void SetOrderStatus(const string& orderStatus);
    void SetTableReservation(bool reservation);

    // Methods
    void AddItem(const MenuItem& item, int quantity); // Adds selected items to the order.
    void RemoveItem(const MenuItem& item); // Deletes specific items from the order.
    double CalculateTotal(); // Computes the total price of items in the order.
    void ConfirmOrder(); // Finalizes and confirms the placed order. And should call process payment.
    void CancelOrder(); // Aborts and cancels the ongoing order process.
};
#endif