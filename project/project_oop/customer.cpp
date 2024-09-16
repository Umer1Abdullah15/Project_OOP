#include "customer.h"
#include "menuitem.h"
#include <iostream>

Customer::Customer() : User(0, "", "", "Customer"), orderHistory(nullptr), orderHistorySize(0) {}

Customer::Customer(int id, string name, string password, string userType) : User(id, name, password, userType), orderHistory(nullptr), orderHistorySize(0) {}

void Customer::ViewMenu(const MenuItem* menuItems, int menuSize) const
{
    cout << "\n\nViewing menu as " << GetUserType() << ":\n";

    // items that are in the menu will be shown to the user
    for (int i = 0; i < menuSize; ++i)
    {
        cout << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
    }

    ofstream write("CUSTOMER.txt", ios::app); // saving the data in CUSTOMER.txt
    if (write.is_open())
    {     
        for (int i = 0; i < menuSize; ++i)
        {
            write << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
        }
        write.close();
    }
}


void Customer::PlaceOrder(Order& order, const MenuItem* menuItems, int menuSize)
{
    cout << "\n-> Placing an order as " << GetUserType() << ":";

    // Displayin menu
    ViewMenu(menuItems, menuSize);

    int i_ID;  // i_ID = itemId
    int q; // q = quantity of the item

    cout << "\nEnter the ID of the item to order: ";
    cin >> i_ID;

    cout << "Enter the quantity: ";
    cin >> q;

    // Finding the item in the menu
    const MenuItem* SI = nullptr; // SI = selectedItem
    for (int i = 0; i < menuSize; ++i)
    {
        if (menuItems[i].GetItemID() == i_ID)
        {
            SI = &menuItems[i];
            break;
        }
    }

    if (SI != nullptr)
    {
        ofstream write("place_order.txt", ios::app); // saving the data in place_order.txt
        if (write.is_open())
        {
            write << "ID: " << SI->GetItemID() << ", Name: " << SI->GetItemName() << ", Description: " << SI->GetItemDescription() << ", Price: RS_" << SI->GetPrice() << ", Quantity: " << q << "\n";
            write.close();


            MonthlyEarnings += SI->GetPrice() * q; // ADDING ALL THE PRICES OF ITEMS TO CALCULATE MonthlyEarnings

        }
        else
        {
            cout << "Unable to open file\n";
        }
    }
    else
    {
        cout << "Item with ID " << i_ID << " not found in the menu\n";
    }

    if (SI != nullptr)
    {
        ofstream out("CUSTOMER.txt", ios::app); // saving the data in CUSTOMER.txt
        if (out.is_open())
        {
            out << "\nID: " << SI->GetItemID() << ", Name: " << SI->GetItemName() << ", Description: " << SI->GetItemDescription() << ", Price: RS_" << SI->GetPrice() << ", Quantity: " << q << "\n";
            out.close();
        }
        else
        {
            cout << "Unable to open file\n";
        }
    }

    ofstream out("ADMINISTRATOR.txt", ios::app); // saving the data in ADMINISTRATOR.txt
    if (out.is_open())
    {
        out << "Monthly Earnings: RS_" << MonthlyEarnings << endl;
        out.close();
    }
}

void Customer::CalculateMonthlyEarnings() // monthly earnings only shown to the administrator
{
    cout << "\nCalculating monthly earnings as Administrator" << endl;
    cout << "-> Monthly Earnings: RS_" << MonthlyEarnings << endl;
}

void Customer::ViewOrderHistory() const
{
    cout << "\nViewing order history as " << GetUserType() << ":\n";

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


void Customer::Logout()
{
    cout << "Logging out as " << GetUserType() << ".\n";
}

Customer::~Customer() // deallocating memory
{
    delete[] orderHistory;
}

void Customer::ReserveTable() 
{
    cout << "Enter the date and time for the reservation : ";
    string r;
    cin.ignore(); // Ignore the newline character
    getline(cin, r);

    cout << "\n-> Table reserved successfully.\n";
}