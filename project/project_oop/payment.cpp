#include "Payment.h"
#include <fstream>
#include <iostream>

Payment::Payment() : PaymentID(0), OrderID(0), Amount(0) {}

Payment::Payment(int id, int orderID, double amount) : PaymentID(id), OrderID(orderID), Amount(amount) {}

bool Payment::ProcessPayment() 
{
    cout << "Processing payment for order ID: ";
    cin >> OrderID;
    cout << "Amount to be paid: RS_";
    cin >> Amount;

    ofstream out("ADMINISTRATOR.txt", ios::app); // saving the data in ADMINISTRATOR.txt
    if (out.is_open())
    {
        out << "ID: " << OrderID << ", Amount: " << Amount;
    }

    ofstream o("CAFESTAFF.txt", ios::app); // saving the data in CAFESTAFF.txt
    if (o.is_open())
    {
        o << "ID: " << OrderID << ", Amount: " << Amount;
    }

    ofstream write("payment.txt", ios::app); // saving the data in payment.txt
    if (write.is_open())
    {
        write << "\nID: " << OrderID << ", Amount: " << Amount;
    }
    else
    {
        cout << "Unable to open file\n";
    }

    char c;
    cout << "Confirm payment? (y/n): ";
    cin >> c;

    if (c == 'y' || c == 'Y') 
    {
        cout << "Payment successful! Thank you for your purchase" << endl;
        return 1;  
    }
    else 
    {
        cout << "Payment cancelled" << endl;
        return 0; 
    }
}


// Getters
int Payment::GetPaymentID() const 
{
    return PaymentID;
}

int Payment::GetOrderID() const 
{
    return OrderID;
}

double Payment::GetAmount() const 
{
    return Amount;
}

string Payment::GetPaymentStatus() const 
{
    return PaymentStatus;
}

// Setters
void Payment::SetPaymentID(int id) 
{
    PaymentID = id;
}

void Payment::SetOrderID(int orderID) 
{
    OrderID = orderID;
}

void Payment::SetAmount(double amount) 
{
    Amount = amount;
}

void Payment::SetPaymentStatus(const string& paymentStatus) 
{
    PaymentStatus = paymentStatus;
}