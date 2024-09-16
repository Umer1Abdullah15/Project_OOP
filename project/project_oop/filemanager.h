#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "user.h"
#include "menuitem.h"
#include "order.h"
#include "rating.h"
#include "payment.h"

class FileManager // class of FileManager public member functions
{
public:
    void SaveUserToFile(const User& user);
    void SaveMenuItemToFile(const MenuItem* item, int menuSize);
    void SaveOrderToFile(const Order& order);
    void SaveRatingToFile(const Rating& rating);
    void SavePaymentToFile(const Payment& payment);
};
#endif