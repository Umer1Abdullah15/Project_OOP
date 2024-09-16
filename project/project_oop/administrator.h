#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "user.h"
#include "order.h"  
#include "menuitem.h"  

class Administrator : public User // class of Administrator [INHERITED] from user class
{
private:
    MenuItem* menuItems;  
    int menuSize;
    string notifications[50]; // Array to store notifications

public:
    Administrator(); // default constructor
    Administrator(int id, string name, string password, string userType); // parameterrized constructor
    ~Administrator(); // destructor
    void ViewMenu(const MenuItem* menuItems, int menuSize) const; // Displays the cafe's available items for users to see.
    void AddMenuItem(const MenuItem& newItem); // Allows administrators to include new items on the cafe's menu.
    void RemoveMenuItem(int itemId); // Permits administrators to delete items from the cafe's menu.
    void ManageInventory(); // Offers administrators the ability to oversee and update the cafe's stock.
    void ManageDiscountPromotion(); // Allows the Administrator to create, update, or remove discounts 
    void ViewOrderHistory(); // Shows a record of past orders made within the system.
    void AddNotification(); // Permits administrators to create and send messages to staff or customers.
    void RemoveNotification(); // Allows administrators to delete previously sent messages.
    void RateMenuItem(); // Enables users to provide ratings and feedback for items on the menu
    void DisplayFromFile(); // Reads and presents specific stored data from a file for administrative viewing.
    void ViewUsersFromFile(); // Retrieves and displays user data from a file for administrative review.
    void ViewMenuItemsFromFile(); // Fetches and presents menu item details stored in a file for administrative viewing.
    void ViewOrdersFromFile(); // Retrieves and displays order information from a file for administrative inspection.
    void ViewRatingsFromFile(); // Fetches and shows ratings and feedback for menu items stored in a file.
    void ViewPaymentsFromFile(); // Retrieves and presents payment details or transaction records from a file for administrative reference.
    void CalculateMonthlyEarnings(); // Calculates and displays the total earnings or revenue generated within a month based on payment records stored in a file.
    void Logout() override; // Ends the current session and exits the system for the user
    void ViewMenu_for_new_items() const; // new menu after adding and removing new items
};

#endif