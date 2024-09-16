#include "rating.h"
#include <iostream>
#include<fstream>

Rating::Rating() : RatingID(0), MenuItemID(0), CustomerID(0), Score(0), Comment("") {}


Rating::Rating(int id, int mi_ID, int c_ID, int s, string c) : RatingID(id), MenuItemID(mi_ID), CustomerID(c_ID), Score(s), Comment(c) {}

void Rating::Rate() 
{
    cout << "Enter the item ID for which you want to rate: ";
    cin >> MenuItemID;
    cout << "Enter rating (1-10) for menu item with ID " << MenuItemID << ": ";
    cin >> Score;

    if (Score >= 1 && Score <= 10) 
    {
        cout << "Enter optional comment for the rating: ";
        cin.ignore(); // Ignore the newline character 
        getline(cin, Comment);

        // Savings the rating to the file
        ofstream write("ratings.txt", ios::app); // by append mode the previous data will not be deleted

        if (write.is_open()) 
        {
            write << "ID: " << MenuItemID << ", Rating: " << Score << ", Comment: " << Comment << "\n";
            write.close();
            cout << "Thank you for your rating and feedback!" << endl;
        }
        else 
        {
            cout << "Unable to open file" << endl;
        }
    }
    else
    {
        cout << "Invalid rating. Please provide a rating between 1 and 10" << endl;
    }
}


// Getters
int Rating::GetRatingID() const 
{
    return RatingID;
}

int Rating::GetMenuItemID() const 
{
    return MenuItemID;
}

int Rating::GetCustomerID() const 
{
    return CustomerID;
}

int Rating::GetScore() const 
{
    return Score;
}

string Rating::GetComment() const 
{
    return Comment;
}

// Setters
void Rating::SetRatingID(int id) 
{
    RatingID = id;
}

void Rating::SetMenuItemID(int menuItemID) 
{
    MenuItemID = menuItemID;
}

void Rating::SetCustomerID(int customerID) 
{
    CustomerID = customerID;
}

void Rating::SetScore(int score) 
{
    Score = score;
}

void Rating::SetComment(const string& comment) 
{
    Comment = comment;
}