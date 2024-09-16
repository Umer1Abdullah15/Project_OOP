#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "user.h"
#include "order.h"
#include "menuitem.h"

class Customer : public User // class of Customer [INHERITED] from user class
{
private:
    Order* orderHistory;
    int orderHistorySize;
    double MonthlyEarnings;

public:
    Customer(); // default constructor
    Customer(int id, string name, string password, string userType); // parameterrized constructor
    ~Customer(); // destructors

    void ViewMenu(const MenuItem* menuItems, int menuSize) const; // Shows the available items in the cafe's menu. Different according to type of user.
    void PlaceOrder(Order& order, const MenuItem* menuItems, int menuSize); // Lets users select items and confirm their order. 
    void ViewOrderHistory() const; // Displays a record of past orders made by the user.
    void Logout(); // Ends the user's current session and exits the system.
    void CalculateMonthlyEarnings(); // monthly earnings only shown to the administrator
    void ReserveTable(); // user is able to reserve the table
};
#endif