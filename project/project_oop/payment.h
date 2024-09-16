#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include <iostream>
using namespace std;

class Payment // class of Payment with protected data members and public member functions
{
protected:
    int PaymentID;
    int OrderID;
    double Amount;
    string PaymentStatus;

public:
    Payment(); // default constructor
    Payment(int id, int orderID, double amount); // parameterrized constructor

    // Getters
    int GetPaymentID() const;
    int GetOrderID() const;
    double GetAmount() const;
    string GetPaymentStatus() const;

    // Setters
    void SetPaymentID(int id);
    void SetOrderID(int orderID);
    void SetAmount(double amount);
    void SetPaymentStatus(const string& paymentStatus);

    // Methods
    bool ProcessPayment();
};
#endif 