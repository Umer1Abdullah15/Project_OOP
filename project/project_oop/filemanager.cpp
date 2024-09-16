#include "filemanager.h"
#include "user.h"
#include "menuitem.h"
#include "order.h"
#include "rating.h"
#include "payment.h"
#include <fstream>

void FileManager::SaveUserToFile(const User& user) 
{
    ofstream write("users.txt", ios::app); // save the data to to users.txt by append mode the previous data will not be deleted
    if (write.is_open()) 
    {
        write << user.GetUserID() << "," << user.GetUserName() << "," << user.GetUserType() << "\n";
        write.close();
        cout << "User data saved to file\n";
    }
    else 
    {
        cout << "Unable to open file\n";
    }
}

void FileManager::SaveMenuItemToFile(const MenuItem* item, int menuSize)
{
    ofstream write("menu_items.txt", ios::app); // save the data to to menu_items.txt by append mode the previous data will not be deleted
    if (write.is_open())
    {
        for (int i = 0; i < menuSize; ++i)
        {
            write << item[i].GetItemID() << "," << item[i].GetItemName() << "," << item[i].GetItemDescription() << ","
                << item[i].GetPrice() << "," << item[i].GetQuantityInStock() << "\n";
        }
        write.close();
        cout << "Menu item data saved to file\n";
    }
    else
    {
        cout << "Unable to open file\n";
    }
}

void FileManager::SaveOrderToFile(const Order& order) 
{
    ofstream write("place_order.txt", ios::app); // save the data to to place_order.txt by append mode the previous data will not be deleted
    if (write.is_open()) 
    {
        for (int i = 0; i < order.GetNumItems(); ++i) 
        {
            write << order.GetOrderID() << "," << order.GetCustomerID() << ","
                << order.GetItemsOrdered()[i].GetItemID() << "," << order.GetTotalPrice() << "\n";
        }
        write.close();
        cout << "Order data saved to file\n";
    }
    else 
    {
        cout << "Unable to open file\n";
    }
}

void FileManager::SaveRatingToFile(const Rating& rating) 
{
    ofstream write("ratings.txt", ios::app); // save the data to to ratings.txt by append mode the previous data will not be deleted
    if (write.is_open()) 
    {
        write << rating.GetRatingID() << "," << rating.GetMenuItemID() << ","
            << rating.GetCustomerID() << "," << rating.GetScore() << "," << rating.GetComment() << "\n";
        write.close();
        cout << "Rating data saved to file\n";
    }
    else 
    {
        cout << "Unable to open file\n";
    }
}

void FileManager::SavePaymentToFile(const Payment& payment) 
{
    std::ofstream write("payment.txt", ios::app); // save the data to to payment.txt by append mode the previous data will not be deleted
    if (write.is_open()) 
    {
        write << payment.GetPaymentID() << "," << payment.GetOrderID() << "," << payment.GetAmount() << "\n";
        write.close();
        cout << "Payment data saved to file\n";
    }
    else 
    {
        cout << "Unable to open file\n";
    }
}