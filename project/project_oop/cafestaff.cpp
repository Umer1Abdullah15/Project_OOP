#include "cafestaff.h"
#include"payment.h"
#include <iostream>

Payment payment;

CafeStaff::CafeStaff() : User(0, "", "", ""), menuItems(nullptr), menuSize(0) {}

CafeStaff::CafeStaff(int id, string name, string password, string userType) : User(id, name, password, userType), menuItems(nullptr), menuSize(0) {}

CafeStaff::~CafeStaff() // deallocating
{
    delete[] menuItems;
}

void CafeStaff::ViewMenu(const MenuItem* menuItems, int menuSize) const
{
    cout << "\n\nViewing menu as " << GetUserType() << ":\n";

    // Displaying menu items to the current user
    for (int i = 0; i < menuSize; ++i)
    {
        cout << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
    }
}

void CafeStaff::ViewMenu_for_new_items() const
{
    for (int i = 0; i < menuSize; ++i)
    {
        cout << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";

        ofstream write("menu_items.txt", ios::app); // saving the data in menu_items.txt
        if (write.is_open())
        {
            for (int i = 0; i < menuSize; ++i)
            {
                write << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
            }
            write.close();
        }

        ofstream out("CAFESTAFF.txt", ios::app); // saving the data in CAFESTAFF.txt
        if (out.is_open())
        {
            for (int i = 0; i < menuSize; ++i)
            {
                out << "ID: " << menuItems[i].GetItemID() << ", Name: " << menuItems[i].GetItemName() << ", Description: " << menuItems[i].GetItemDescription() << ", Price: RS_" << menuItems[i].GetPrice() << ", Quantity: " << menuItems[i].GetQuantityInStock() << "\n";
            }
            out.close();
        }
    }
}

void CafeStaff::ProcessOrder() const
{
    payment.ProcessPayment(); // calling the function to process the payment
    cout << endl;
    ifstream read("place_order.txt"); // reading the data from place_order.txt
    if (read.is_open())
    {
        string s;
        while (getline(read, s))
        {
            cout << s << endl;
        }
        read.close();
        cout << "Order processed successfully\n";
    }
    else
    {
        cout << "Cannot process an empty order\n";
    }
}


void CafeStaff::AddMenuItem(const MenuItem& newItem)
{
    cout << "Adding a new menu item" << endl;

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

void CafeStaff::RemoveMenuItem(int itemId)
{
    cout << "Removing a menu item" << endl;

    int removeIndex = -1;
    for (int i = 0; i < menuSize; ++i)
    {
        if (menuItems[i].GetItemID() == itemId)
        {
            removeIndex = i;
            break;
        }
    }

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

void CafeStaff::ManageInventory() // Inventory manage by administrator
{
    cout << "\nManaging inventory as Administrator." << endl;
    cout << "Enter the ID of the item to update inventory: ";
    int itemId;
    cin >> itemId;

    // Finding the index of the item with the given ID
    int itemIndex = -1;
    for (int i = 0; i < menuSize; ++i)
    {
        if (menuItems[i].GetItemID() == itemId)
        {
            itemIndex = i;
            break;
        }
    }

    // If the item is found, update the inventory
    if (itemIndex != -1)
    {
        int nq; // nq = newQuantity
        cout << "Enter the new quantity in stock: ";
        cin >> nq;

        menuItems[itemIndex].UpdateStock(nq);
        cout << "Inventory updated successfully.\n";
    }
    else
    {
        cout << "Item with ID " << itemId << " not found.\n";
    }
}


void CafeStaff::ManageDiscountPromotion() // discounts/promotions manage by Administrator
{
    cout << "\nManaging discounts/promotions as Administrator." << endl;
    cout << "Enter the ID of the item to set discount/promotion: ";
    int itemId;
    cin >> itemId;

    int itemIndex = -1;
    for (int i = 0; i < menuSize; ++i)
    {
        if (menuItems[i].GetItemID() == itemId)
        {
            itemIndex = i;
            break;
        }
    }

    // If the item is found, set the discount/promotion
    if (itemIndex != -1)
    {
        double discount;
        cout << "Enter the discount/promotion percentage: ";
        cin >> discount;


        double discounted_Price = menuItems[itemIndex].GetPrice() * (1.0 - discount / 100);
        menuItems[itemIndex].SetPrice(discounted_Price);

        cout << "Discount/promotion applied successfully.\n";
    }
    else
    {
        cout << "Item with ID " << itemId << " not found.\n";
    }
}


void CafeStaff::Logout() const 
{
    cout << "Logging out as Cafe Staff.\n";
}

void CafeStaff::ManageTableReservations() 
{
    cout << "Do you want to accept the reservation or cancel it? (y/n)";
    string r;
    cin >> r;

    if (r == "y")
    {
        cout << "Table reservation Accepted\n";
    }
    else if (r == "n")
    {
        cout << "Table reservation Rejected\n";
    }
}