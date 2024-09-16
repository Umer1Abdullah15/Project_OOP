#include<iostream>
#include "administrator.h"

Administrator::Administrator() : User(0, "", "", "Administrator") {}

Administrator::Administrator(int id, string name, string password, string userType) : User(id, name, password, userType) {}

Administrator::~Administrator() // deallocating the allocated memory
{
    delete[] menuItems;
}

void Administrator::ViewMenu(const MenuItem* menuItems, int menuSize) const
{
    cout << "\n\nViewing menu as " << GetUserType() << ":\n";

    // Displaying the menu items to the user
    for (int i = 0; i < menuSize; ++i)
    {
        cout << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
    }
}

void Administrator::ViewMenu_for_new_items() const 
{
    for (int i = 0; i < menuSize; ++i)
    {
        cout << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
    }

    ofstream write("ADMINISTRATOR.txt", ios::app); // saving the data in ADMINISTRATOR.txt
    if (write.is_open())
    {
        for (int i = 0; i < menuSize; ++i)
        {
            write << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
        }
        write.close();
    }
}

void Administrator::AddMenuItem(const MenuItem& newItem) 
{
    cout << "\nAdding a new menu item as Administrator" << endl;

    MenuItem* newMenu = new MenuItem[menuSize + 1];

    for (int i = 0; i < menuSize; ++i) 
    {
        newMenu[i] = menuItems[i];
    }

    newMenu[menuSize] = newItem;
    delete[] menuItems; // deallocating

    menuItems = newMenu;
    menuSize++;

    cout << "Menu item added successfully\n";
}

void Administrator::RemoveMenuItem(int itemId) 
{
    cout << "\nRemoving a menu item as Administrator" << endl;

    int removeIndex = -1;
    for (int i = 0; i < menuSize; ++i) 
    {
        if (menuItems[i].GetItemID() == itemId) 
        {
            removeIndex = i;
            break;
        }
    }

    // If the item is found, remove it
    if (removeIndex != -1) 
    {
        MenuItem* newMenu = new MenuItem[menuSize - 1];

        for (int i = 0, j = 0; i < menuSize; ++i) 
        {
            if (i != removeIndex) 
            {
                newMenu[j] = menuItems[i];
                ++j;
            }
        }

        delete[] menuItems; // deallocating

        menuItems = newMenu;
        menuSize--;

        cout << "Menu item removed successfully\n";
    }
    else 
    {
        cout << "-> Item with ID " << itemId << " not found\n";
    }
}

void Administrator::ManageInventory() 
{
    cout << "\nManaging inventory as Administrator" << endl;
    cout << "Enter the ID of the item to update inventory: ";
    int i_ID; // i_ID = itemId
    cin >> i_ID;

    int itemIndex = -1;
    for (int i = 0; i < menuSize; ++i) 
    {
        if (menuItems[i].GetItemID() == i_ID) 
        {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex != -1) 
    {
        int nq; // nq = newQuantity
        cout << "Enter the new quantity in stock: ";
        cin >> nq;

        // Update the quantity in stock
        menuItems[itemIndex].UpdateStock(nq);

        cout << "Inventory updated successfully.\n";
    }
    else
    {
        cout << "Item with ID " << i_ID << " not found\n";
    }
}

void Administrator::ManageDiscountPromotion() 
{
    cout << "\nManaging discounts/promotions as Administrator" << endl;
    cout << "Enter the ID of the item to set discount/promotion: ";
    int i_ID; // i_ID = itemId
    cin >> i_ID;

    int itemIndex = -1;
    for (int i = 0; i < menuSize; ++i) 
    {
        if (menuItems[i].GetItemID() == i_ID) 
        {
            itemIndex = i;
            break;
        }
    }

    if (itemIndex != -1) 
    {
        double d; // d = discount
        cout << "Enter the discount/promotion percentage: ";
        cin >> d;

        // Apply the discount/promotion
        double discountedPrice = menuItems[itemIndex].GetPrice() * (1.0 - d / 100);

        // Update the price of the item
        menuItems[itemIndex].SetPrice(discountedPrice);

        cout << "Discount/promotion applied successfully\n";
    }
    else 
    {
        cout << "Item with ID " << i_ID << " not found\n";
    }
}


void Administrator::ViewOrderHistory() 
{
    cout << "\nViewing order history as Administrator" << endl;
    
    ifstream read("place_order.txt"); // // reading the data from place_order.txt
    if (read.is_open())
    {
        string s;
        while (getline(read, s))
        {
            cout << s << endl;
        }
        read.close();
    }
    else
    {
        cout << "No order history available\n";
    }
}

void Administrator::AddNotification() 
{
    cout << "\nAdding a notification as Administrator" << endl;

    // Checking if there is space for a new notification
    if (notifications[49] != "") 
    {
        cout << "Notification limit reached. Remove old notifications to add new ones\n";
        return;
    }

    // Get input for the new notification
    string new_notification;
    cout << "Enter the notification message: ";
    cin.ignore(); // Ignore the newline character in the buffer
    getline(cin, new_notification);

    // Finding an empty slot and adding the new notification
    for (int i = 0; i < 50; ++i) 
    {
        if (notifications[i] == "") 
        {
            notifications[i] = new_notification;
            cout << "Notification added successfully\n";
            return;
        }
    }
}

void Administrator::RemoveNotification() 
{
    cout << "\nRemoving a notification as Administrator" << endl;

    // Displaying existing notifications
    cout << "Current notifications:\n";
    for (int i = 0; i < 50; ++i) 
    {
        if (notifications[i] != "") 
        {
            cout << i + 1 << ". " << notifications[i] << "\n";
        }
    }

    int n; // n = notification that is stored in the array
    cout << "Enter the number of the notification to remove: ";
    cin >> n;

    if (n >= 1 && n <= 50 && notifications[n - 1] != "") 
    {
        notifications[n - 1] = "";
        cout << "Notification removed successfully\n";
    }
    else 
    {
        cout << "Invalid notification number\n";
    }
}

void Administrator::RateMenuItem() 
{
    cout << "Rating a menu item as Administrator" << endl;
}

void Administrator::DisplayFromFile() 
{
    cout << "\nViewing all data from a file as Administrator" << endl;
    cout << "\nUsers Data:-\n";
    ifstream read("users.txt"); // reading from the file users_data.txt
    if (read.is_open())
    {
        string s;
        while (getline(read, s))
        {
            cout << s << endl;
        }
        read.close();
    }

    cout << "\nMenu Item:-\n";
    ifstream rea("menu_items.txt"); // reading from the file menu_items.txt
    if (rea.is_open())
    {
        string st;
        while (getline(rea, st))
        {
            cout << st << endl;
        }
        rea.close();
    }

    cout << "\nRatings:-\n";
    ifstream re("ratings.txt"); // reading from the file ratings.txt
    if (re.is_open())
    {
        string str;
        while (getline(re, str))
        {
            cout << str << endl;
        }
        re.close();
    }
}

void Administrator::ViewUsersFromFile() 
{
    cout << "\nViewing users from a file as Administrator" << endl;

    ifstream read("users.txt"); // reading from the file users_data.txt
    if (read.is_open()) 
    {
        string s;
        while (getline(read, s))
        {
            cout << s << endl;
        }
        read.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void Administrator::ViewMenuItemsFromFile() 
{
    cout << "\nViewing menu items from a file as Administrator" << endl;

    ifstream read("menu_items.txt"); // reading from the file menu_items.txt
    if (read.is_open()) 
    {
        string s;
        while (getline(read, s)) 
        {
            cout << s << endl;
        }
        read.close();
    }
    else 
    {
        cout << "Unable to open file" << endl;
    }
}

void Administrator::ViewOrdersFromFile() 
{
    cout << "\nViewing orders from a file as Administrator" << endl;
   
    ifstream read("place_order.txt"); // reading the data from place_order.txt
    if (read.is_open())
    {
        string s;
        while (getline(read, s))
        {
            cout << s << endl;
        }
        read.close();
    }
    else
    {
        cout << "No order history available\n";
    }
}

void Administrator::ViewRatingsFromFile() 
{
    cout << "\nViewing ratings from a file as Administrator" << endl;

    ifstream read("ratings.txt"); // reading from the file ratings.txt
    if (read.is_open()) 
    {
        string s;
        while (getline(read, s)) 
        {
            cout << s << endl;
        }
        read.close();
    }
    else 
    {
        cout << "Unable to open file" << endl;
    }
}

void Administrator::ViewPaymentsFromFile() 
{
    cout << "\nViewing payments from a file as Administrator" << endl;

    ifstream read("payment.txt"); // reading the data from payment.txt
    if (read.is_open()) 
    {
        string s;
        while (getline(read, s)) 
        {
            cout << s << endl;
        }
        read.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }
}

void Administrator::CalculateMonthlyEarnings() 
{
    cout << "Calculating monthly earnings as Administrator" << endl;
    //cout << "Monthly Earnings: RS_" << MonthlyEarnings << endl;
}

void Administrator::Logout() 
{
    cout << "Administrator logout" << endl;
}