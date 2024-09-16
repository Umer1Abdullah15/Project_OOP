#include "user.h"

User::User(int id, string name, string password, string userType) : UserID(id), UserName(name), Password(password), UserType(userType) {}

void User::Register() 
{
    cin >> *this;
}

istream& operator>>(istream& i, User& u) 
{
    cout << "Enter ID: ";
    i >> u.UserID;
    cout << "Enter Username: ";
    i.ignore(); // Ignore the newline character
    getline(i, u.UserName);
    cout << "Enter Password: ";
    i >> u.Password;
    return i;
}

void User::Login() 
{
    string ep; // ep = enteredPassword
    cout << "\nEnter password for user " << GetUserName() << ": ";
    cin >> ep;

    if (ep == GetPassword()) 
    {
        cout << "Login successful!" << endl;
    }
    else 
    {
        cout << "Incorrect password. Login failed." << endl;
        Logout();
    }
    ofstream write("users.txt", ios::app); // saving the user information in users.txt
    if (write.is_open())
    {
        write << "ID: " << GetUserID() << ", " << "Name: " << GetUserName() << ", " << "UserType: " << GetUserType() << "\n";
        write.close();
    }
    else
    {
        cout << "Unable to open file\n";
    }
}

void User::Logout() 
{
    cout << "Logging out user " << GetUserName() << endl;
}

// Setters
void User::SetUserName(const string& name) 
{
    UserName = name;
}

void User::SetPassword(const string& password) 
{
    Password = password;
}

void User::SetUserType(const string& userType) 
{
    UserType = userType;
}

// Getters
int User::GetUserID() const
{
    return UserID; 
}

string User::GetUserName() const
{ 
    return UserName;
}

string User::GetUserType() const
{
    return UserType; 
}

string User::GetPassword() const
{
    return Password;
}