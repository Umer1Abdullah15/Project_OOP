#ifndef CAFE_STAFF_H
#define CAFE_STAFF_H

#include "user.h"
#include "order.h"  
#include "menuitem.h"  

class CafeStaff : public User // class of cafestaff [INHERITED] from user class
{
private:
    MenuItem* menuItems; 
    int menuSize;

public:
    CafeStaff(); // default constructor
    CafeStaff(int id, string name, string password, string userType); // parameterized constructor
    ~CafeStaff();  // destructor

    void ViewMenu(const MenuItem* menuItems, int menuSize) const; // Displays the cafe's available items for users to see.
    void ProcessOrder() const; // Enables staff to handle and fulfill incoming orders.
    void AddMenuItem(const MenuItem& newItem); // Lets staff include new items to the cafe's menu.
    void RemoveMenuItem(int itemId); // Allows staff to delete items from the cafe's menu.
    void Logout() const ; // Ends the current session and exits the system for the user.
    void ViewMenu_for_new_items() const; // new menu after adding and removing new items
    void ManageInventory(); // Offers administrators the ability to oversee and update the cafe's stock.
    void ManageDiscountPromotion(); // Allows the Administrator to create, update, or remove discounts 
    void ManageTableReservations(); // cafe staff is able to manage table reservations
};
#endif