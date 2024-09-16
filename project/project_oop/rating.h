#ifndef RATING_H
#define RATING_H

#include <string>
#include<iostream>
using namespace std;

class Rating  // class of Rating with protected data members and public member functions
{
protected:
    int RatingID;
    int MenuItemID;
    int CustomerID;
    int Score;
    string Comment;

public:
    Rating(); // default constructor
    Rating(int id, int menuitemID, int customerID, int score, string comment); // parameterrized constructor

    // Getters
    int GetRatingID() const;
    int GetMenuItemID() const;
    int GetCustomerID() const;
    int GetScore() const;
    string GetComment() const;

    // Setters
    void SetRatingID(int id);
    void SetMenuItemID(int menuItemID);
    void SetCustomerID(int customerID);
    void SetScore(int score);
    void SetComment(const string& comment);

    // Methods
    void Rate();
};
#endif