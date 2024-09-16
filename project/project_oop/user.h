#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User // class of User with protected data members and public member functions
{
protected:
    int UserID;
    string UserName;
    string Password;
    string UserType;

public:
    User(int id, string name, string password, string userType); // parametarized constructor
    virtual void Register(); // late binding by virtual key-word [Polymorphism] 
    virtual void Login(); // late binding by virtual key-word [Polymorphism] 
    virtual void Logout(); // late binding by virtual key-word [Polymorphism] 

    // Getters 
    int GetUserID() const;
    string GetUserName() const;
    string GetUserType() const;
    string GetPassword() const;

    // Setters
    void SetUserName(const string& name);
    void SetPassword(const string& password);
    void SetUserType(const string& userType);

    friend istream& operator>>(istream& i, User& u); // [OPERATOR OVERLOADING] using extraction operator for taking inputs 
};

#endif