#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include "user.h"
#include "customer.h"
#include "cafeStaff.h"
#include "administrator.h"
#include"rating.h"
using namespace std;


// Function to set the console text color
void  Console_Screen_Color(WORD color) // WORD = a data type representing a 16-bit unsigned integer
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // HANDLE = Handle is needed to interact with the console window
    SetConsoleTextAttribute(console, color); //     SetConsoleTextAttribute = Sets the text attributes of the console csreen according to the color
}


void print_title()
{ 
    Console_Screen_Color(FOREGROUND_RED | FOREGROUND_GREEN); // color will be YELLOW
    cout << R"( 
__        _______ _     ____ ___  __  __ _____   _____ ___                
\ \      / / ____| |   / ___/ _ \|  \/  | ____| |_   _/ _ \               
 \ \ /\ / /|  _| | |  | |  | | | | |\/| |  _|     | || | | |              
  \ V  V / | |___| |__| |__| |_| | |  | | |___    | || |_| |              
  _\_/\_/  |_____|_____\____\___/|_|  |_|_____|   |_| \___/               
 / ___|__ _ / _| ___                                                      
| |   / _` | |_ / _ \                                                     
| |__| (_| |  _|  __/                                                     
 \____\__,_|_|  \___|                                     _               
|  \/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_             
| |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|            
| |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_             
|_|__|_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__|            
/ ___| _   _ ___| |_ ___ _|___/__                                         
\___ \| | | / __| __/ _ \ '_ ` _ \                                        
 ___) | |_| \__ \ ||  __/ | | | | |                                       
|____/ \__, |___/\__\___|_| |_| |_|                                       
       |___/                         )"; // R = raw string literal
  
    cout << "\n\n\nMADE BY : HAMMAD ALI_22I0628";
}


int main()
{
    print_title();
    Sleep(4000);
    system("cls");
    Console_Screen_Color(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // color will be WHITE

    User* currentUser = nullptr;
    Customer customer; // making object of class Customers
    CafeStaff cafestaff; // making object of class Cafe
    Administrator administrator; // making object of class Administrator
    Order order; // making object of class Order 
    Rating rate; // making object of class rates

    while (true)
    {
        cout << setw(70) << "--------------------------\n";
        cout << setw(70) << "|  CAFE MANAGEMENT SYSTEM  |" << endl;
        cout << setw(70) << "--------------------------\n";
        cout << endl;
        cout << setw(70) << "--------------------------\n";
        cout << setw(70) << "| 1. Customer Login        |" << endl;
        cout << setw(70) << "| 2. Cafe Staff Login      |" << endl;
        cout << setw(70) << "| 3. Administrator Login   |" << endl;
        cout << setw(70) << " | 4. Exit                  |" << endl;
        cout << setw(70) << "--------------------------\n";
        int c; // c = choice of user
        cout << "Enter your choice: ";
        cin >> c;

        switch (c)
        {
        case 1:
        {
            currentUser = new Customer(1, "Sajjad", "123", "Customer");

            // Asking the customer which type of user he is?
            string ct; // ct = customerType 
            cout << "Are you a student, faculty, or non-faculty? ";
            cin >> ct;

            // based on the user type setting the currentuser to that type
            currentUser->SetUserType(ct);
            break;
        }
        case 2:
        {
            currentUser = new CafeStaff(2, "Murtaza", "456", "CafeStaff");
            break;
        }
        case 3:
        {
            currentUser = new Administrator(3, "Hammad", "789", "Administrator");
            break;
        }
        case 4:
        {
            cout << "Exiting the program." << endl;
            return 0;
        }
        default:
        {
            cout << "Invalid choice. Please try again." << endl;
            continue;
        }
        }

        currentUser->Register(); // every user will first register
        currentUser->Login(); // after registration they will be asked about login details

        while (true)
        {
            //-------------------------------------------- STUDENT ----------------------------------------------
            if (currentUser->GetUserType() == "student")
            {
                cout << endl;
                cout << setw(70 - 2 + 1) << "--------------------------" << endl;
                cout << setw(70) << "|      STUDENT MENU        |" << endl;
                cout << setw(70) << "--------------------------\n";
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(70) << "| 1. View Menu             |" << endl;
                cout << setw(70) << "| 2. Place Order           |" << endl;
                cout << setw(70) << "| 3. View Order History    |" << endl;
                cout << setw(70) << "| 4. Rate Item             |" << endl;
                cout << setw(70) << "| 5. Reserve Table         |" << endl;
                cout << setw(70) << "| 6. Logout                |" << endl;
                cout << setw(69) << "--------------------------" << endl;
                int cc; // cc = customerChoice
                cout << "Enter your choice: ";
                cin >> cc;

                // Menuitems that have total 10 items
                MenuItem menuItems[10] =
                {
                    MenuItem(1, "Burger", "Delicious burger", 250, 30),
                    MenuItem(2, "Pizza", "Tasty pizza", 1200, 25),
                    MenuItem(3, "Salad", "Healthy salad", 50, 20),
                    MenuItem(4, "Pasta", "Classic pasta", 150, 15),
                    MenuItem(5, "Ice Cream", "Sweet and cool ice cream", 90, 20),
                    MenuItem(6, "Steak", "Juicy and flavorful steak", 1500, 10),
                    MenuItem(7, "Chicken Salad", "Grilled chicken with fresh greens", 100, 15),
                    MenuItem(8, "Sushi", "Assorted sushi rolls", 200, 18),
                    MenuItem(9, "Vegetarian Pizza", "Delicious pizza with assorted veggies", 1400, 12),
                    MenuItem(10, "Chocolate Cake", "Rich and moist chocolate cake", 2000, 8)
                };

                switch (cc)
                {
                case 1:
                {
                    customer.ViewMenu(menuItems, 10);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }

                case 2:
                {
                    customer.PlaceOrder(order, menuItems, 10);
                    break;
                }
                case 3:
                {
                    customer.ViewOrderHistory();
                    break;
                }
                case 4:
                {
                    rate.Rate(); // calling the function to rate the item according to the user
                    break;
                }
                case 5:
                {
                    customer.ReserveTable();
                }
                case 6:
                {
                    cout << "Logging out as Student" << endl;
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                if (cc == 6)
                {
                    break;
                }
            }

            //-------------------------------------------- NON-FACULTY ----------------------------------------------
            else if (currentUser->GetUserType() == "nonfaculty")
            {
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(70) << " |     NON-FACULTY MENU     |" << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(70) << " | 1. View Menu             |" << endl;
                cout << setw(70) << " | 2. Place Order           |" << endl;
                cout << setw(70) << " | 3. View Order History    |" << endl;
                cout << setw(70) << " | 4. Rate Item             |" << endl;
                cout << setw(70) << " | 5. Reserve Table         |" << endl;
                cout << setw(70) << " | 6. Logout                |" << endl;
                cout << setw(69) << "--------------------------" << endl;
                int cc; // cc = customerChoice
                cout << "Enter your choice: ";
                cin >> cc;

                // Menuitems that have total 5 items
                MenuItem menuItems[5] =
                {
                    MenuItem(1, "Chicken Biryani", "Fragrant rice with spiced chicken", 220, 20),
                    MenuItem(2, "Paneer Tikka", "Grilled cottage cheese marinated in spices", 150, 15),
                    MenuItem(3, "Palak Paneer", "Creamy spinach curry with cottage cheese", 300, 18),
                    MenuItem(4, "Dal Makhani", "Lentils cooked with butter and cream", 400, 25),
                    MenuItem(5, "Gulab Jamun", "Sweet dumplings in sugar syrup", 150, 30)
                };

                switch (cc)
                {
                case 1:
                {
                    customer.ViewMenu(menuItems, 5);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }

                case 2:
                {
                    customer.PlaceOrder(order, menuItems, 5);
                    break;
                }

                case 3:
                {
                    customer.ViewOrderHistory();
                    break;
                }
                case 4:
                {
                    rate.Rate(); // calling the function to rate the item according to the user
                    break;
                }
                case 5:
                {
                    customer.ReserveTable();
                }
                case 6:
                {
                    cout << "Logging out as Non-Faculty" << endl;
                    //currentUser->Logout();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                if (cc == 6)
                {
                    break;
                }
            }

            //-------------------------------------------- FACULTY ----------------------------------------------
            else if (currentUser->GetUserType() == "faculty")
            {
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(71) << " |       FACULTY MENU       | " << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(70) << " | 1. View Menu             |" << endl;
                cout << setw(70) << " | 2. Place Order           |" << endl;
                cout << setw(70) << " | 3. View Order History    |" << endl;
                cout << setw(70) << " | 4. Rate Item             |" << endl;
                cout << setw(70) << " | 5. Reserve Table         |" << endl;
                cout << setw(70) << " | 6. Logout                |" << endl;
                cout << setw(69) << "--------------------------" << endl;
                int cc; // fc = faculty choice
                cout << "Enter your choice: ";
                cin >> cc; // cc = customerChoice

                // Menuitems that have total 15 items
                MenuItem menuItems[15] =
                {
                    MenuItem(1, "Burger", "Delicious burger", 250, 30),
                    MenuItem(2, "Pizza", "Tasty pizza", 1200, 25),
                    MenuItem(3, "Salad", "Healthy salad", 50, 20),
                    MenuItem(4, "Pasta", "Classic pasta", 150, 15),
                    MenuItem(5, "Ice Cream", "Sweet and cool ice cream", 90, 20),
                    MenuItem(6, "Steak", "Juicy and flavorful steak", 1500, 10),
                    MenuItem(7, "Chicken Salad", "Grilled chicken with fresh greens", 100, 15),
                    MenuItem(8, "Sushi", "Assorted sushi rolls", 200, 18),
                    MenuItem(9, "Vegetarian Pizza", "Delicious pizza with assorted veggies", 1400, 12),
                    MenuItem(10, "Chocolate Cake", "Rich and moist chocolate cake", 2000, 8),
                    MenuItem(11, "Chicken Biryani", "Fragrant rice with spiced chicken", 220, 20),
                    MenuItem(12, "Paneer Tikka", "Grilled cottage cheese marinated in spices", 150, 15),
                    MenuItem(13, "Palak Paneer", "Creamy spinach curry with cottage cheese", 300, 18),
                    MenuItem(14, "Dal Makhani", "Lentils cooked with butter and cream", 400, 25),
                    MenuItem(15, "Gulab Jamun", "Sweet dumplings in sugar syrup", 150, 30)
                };

                switch (cc)
                {
                case 1:
                {
                    customer.ViewMenu(menuItems, 15);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }

                case 2:
                {
                    customer.PlaceOrder(order, menuItems, 15);
                    break;
                }

                case 3:
                {
                    customer.ViewOrderHistory();
                    break;
                }
                case 4:
                {
                    rate.Rate(); // calling the function to rate the item according to the user
                    break;
                }
                case 5:
                {
                    customer.ReserveTable();
                }
                case 6:
                {
                    cout << "Logging out as a Faculty" << endl;
                    //currentUser->Logout();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                if (cc == 6)
                {
                    break;
                }
            }

            //-------------------------------------------- CAFE-STAFF ----------------------------------------------
            else if (currentUser->GetUserType() == "CafeStaff")
            {
                cout << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << setw(71) << "|    CAFE STAFF MENU       | " << endl;
                cout << setw(69) << "--------------------------" << endl;
                cout << endl;
                cout << setw(72) << "--------------------------------" << endl;
                cout << setw(73) << " | 1. View Menu                   |" << endl;
                cout << setw(73) << " | 2. Process Order               |" << endl;
                cout << setw(73) << " | 3. Add/Remove Menu Item        |" << endl;
                cout << setw(73) << " | 4. Manage Table Reservations   |" << endl;
                cout << setw(73) << " | 5. Logout                      |" << endl;
                cout << setw(72) << "--------------------------------" << endl;
                int sc; // sc = staffChoice
                cout << "Enter your choice: ";
                cin >> sc;

                // Menuitems that have total 15 items
                MenuItem menuItems[15] =
                {
                        MenuItem(1, "Burger", "Delicious burger", 250, 30),
                        MenuItem(2, "Pizza", "Tasty pizza", 1200, 25),
                        MenuItem(3, "Salad", "Healthy salad", 50, 20),
                        MenuItem(4, "Pasta", "Classic pasta", 150, 15),
                        MenuItem(5, "Ice Cream", "Sweet and cool ice cream", 90, 20),
                        MenuItem(6, "Steak", "Juicy and flavorful steak", 1500, 10),
                        MenuItem(7, "Chicken Salad", "Grilled chicken with fresh greens", 100, 15),
                        MenuItem(8, "Sushi", "Assorted sushi rolls", 200, 18),
                        MenuItem(9, "Vegetarian Pizza", "Delicious pizza with assorted veggies", 1400, 12),
                        MenuItem(10, "Chocolate Cake", "Rich and moist chocolate cake", 2000, 8),
                        MenuItem(11, "Chicken Biryani", "Fragrant rice with spiced chicken", 220, 20),
                        MenuItem(12, "Paneer Tikka", "Grilled cottage cheese marinated in spices", 150, 15),
                        MenuItem(13, "Palak Paneer", "Creamy spinach curry with cottage cheese", 300, 18),
                        MenuItem(14, "Dal Makhani", "Lentils cooked with butter and cream", 400, 25),
                        MenuItem(15, "Gulab Jamun", "Sweet dumplings in sugar syrup", 150, 30)
                };

                switch (sc)
                {
                case 1:
                {
                    cafestaff.ViewMenu(menuItems, 15);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }

                case 2:
                {
                    cafestaff.ProcessOrder();
                    break;
                }

                case 3:
                {
                    int item;
                    cout << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << setw(73) << "| 1: Add Item                    |" << endl;
                    cout << setw(73) << " | 2: Remove Item                 |" << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << "Enter your choice: ";
                    cin >> item;

                    if (item == 1)
                    {

                        int id;
                        string n, d; // n = item_name, d = item_description
                        double p; // p = price
                        int q; // q = quantity

                        cout << "Enter Item ID: ";
                        cin >> id;

                        cout << "Enter Item Name: ";
                        cin >> n;

                        cout << "Enter Item Description: ";
                        cin >> d;

                        cout << "Enter Item Price: RS_";
                        cin >> p;

                        cout << "Enter Quantity in Stock: ";
                        cin >> q;

                        MenuItem newItem(id, n, d, p, q);
                        cafestaff.AddMenuItem(newItem); // calling function to add the item

                        for (int i = 0; i < 15; ++i)
                        {
                            if (menuItems[i].GetItemID() == id)
                            {
                                menuItems[i] = newItem;
                                break;
                            }
                        }

                        cafestaff.ViewMenu(menuItems, 15);
                        cafestaff.ViewMenu_for_new_items();
                        break;
                    }

                    else if (item == 2)
                    {
                        int itemId;
                        cout << "Enter the ID of the item to remove: ";
                        cin >> itemId;

                        cafestaff.RemoveMenuItem(itemId); // calling function to remove the item
                        cafestaff.ViewMenu(menuItems, 15);
                        cafestaff.ViewMenu_for_new_items();
                        break;
                    }
                    break;

                }
                case 4:
                {
                    cafestaff.ManageTableReservations();
                }
                case 5:
                {
                    cout << "Logging out as a CafeStaff" << endl;
                    currentUser->Logout();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                if (sc == 5)
                {
                    break;
                }
            }

            //-------------------------------------------- ADMINISTRATOR ----------------------------------------------
            else if (currentUser->GetUserType() == "Administrator")
            {
                cout << endl;
                cout << setw(70) << "--------------------------" << endl;
                cout << setw(71) << "|    ADMINISTRATOR MENU    |" << endl;
                cout << setw(70) << "--------------------------" << endl;
                cout << endl;
                cout << setw(73) << "---------------------------------" << endl;
                cout << setw(74) << " | 1. View Menu                    |" << endl;
                cout << setw(74) << " | 2. Add/Remove Menu Item         |" << endl;
                cout << setw(74) << " | 3. Manage Inventory             |" << endl;
                cout << setw(74) << " | 4. Manage Discount/Promotion    |" << endl;
                cout << setw(74) << " | 5. View Order History           |" << endl;
                cout << setw(74) << " | 6. Add/Remove Notification      |" << endl;
                cout << setw(74) << " | 7. Rate Menu Item               |" << endl;
                cout << setw(74) << " | 8. Display from File            |" << endl;
                cout << setw(74) << " | 9. View Users from File         |" << endl;
                cout << setw(74) << " | 10. View Menu Items from File   |" << endl;
                cout << setw(74) << " | 11. View Orders from File       |" << endl;
                cout << setw(74) << " | 12. View Ratings from File      |" << endl;
                cout << setw(74) << " | 13. View Payments From File     |" << endl;
                cout << setw(74) << " | 14. Calculate Monthly Earnings  |" << endl;
                cout << setw(74) << " | 15. Logout                      |" << endl;
                cout << setw(73) << "---------------------------------" << endl;
                int ac; // ac = adminChoice
                cout << "Enter your choice: ";
                cin >> ac;

                // Menuitems that have total 15 items
                MenuItem menuItems[15] =
                {
                        MenuItem(1, "Burger", "Delicious burger", 250, 30),
                        MenuItem(2, "Pizza", "Tasty pizza", 1200, 25),
                        MenuItem(3, "Salad", "Healthy salad", 50, 20),
                        MenuItem(4, "Pasta", "Classic pasta", 150, 15),
                        MenuItem(5, "Ice Cream", "Sweet and cool ice cream", 90, 20),
                        MenuItem(6, "Steak", "Juicy and flavorful steak", 1500, 10),
                        MenuItem(7, "Chicken Salad", "Grilled chicken with fresh greens", 100, 15),
                        MenuItem(8, "Sushi", "Assorted sushi rolls", 200, 18),
                        MenuItem(9, "Vegetarian Pizza", "Delicious pizza with assorted veggies", 1400, 12),
                        MenuItem(10, "Chocolate Cake", "Rich and moist chocolate cake", 2000, 8),
                        MenuItem(11, "Chicken Biryani", "Fragrant rice with spiced chicken", 220, 20),
                        MenuItem(12, "Paneer Tikka", "Grilled cottage cheese marinated in spices", 150, 15),
                        MenuItem(13, "Palak Paneer", "Creamy spinach curry with cottage cheese", 300, 18),
                        MenuItem(14, "Dal Makhani", "Lentils cooked with butter and cream", 400, 25),
                        MenuItem(15, "Gulab Jamun", "Sweet dumplings in sugar syrup", 150, 30)
                };

                switch (ac)
                {
                case 1:
                {
                    administrator.ViewMenu(menuItems, 15);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }

                case 2:
                {
                    int item;
                    cout << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << setw(73) << "| 1: Add Item                    |" << endl;
                    cout << setw(73) << " | 2: Remove Item                 |" << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << "Enter your choice: ";
                    cin >> item;

                    if (item == 1)
                    {
                        int id;
                        string n, d; // n = item_name, d = item_description
                        double p; // p = price
                        int q; // q = quantity

                        cout << "Enter Item ID: ";
                        cin >> id;

                        cout << "Enter Item Name: ";
                        cin >> n;

                        cout << "Enter Item Description: ";
                        cin >> d;

                        cout << "Enter Item Price: RS_";
                        cin >> p;

                        cout << "Enter Quantity in Stock: ";
                        cin >> q;

                        MenuItem newItem(id, n, d, p, q);
                        cafestaff.AddMenuItem(newItem); // calling function to add the item

                        for (int i = 0; i < 15; ++i)
                        {
                            if (menuItems[i].GetItemID() == id)
                            {
                                menuItems[i] = newItem;
                                break;
                            }
                        }

                        administrator.ViewMenu(menuItems, 15);
                        cafestaff.ViewMenu_for_new_items();
                        break;
                    }

                    else if (item == 2)
                    {
                        int itemId;
                        cout << "Enter the ID of the item to remove: ";
                        cin >> itemId;

                        cafestaff.RemoveMenuItem(itemId); // calling function to remove the item
                        administrator.ViewMenu(menuItems, 15);
                        cafestaff.ViewMenu_for_new_items();
                        break;
                    }
                    break;
                }

                case 3:
                {
                    cafestaff.ManageInventory(); // calling function to update the stock
                    administrator.ViewMenu(menuItems, 15);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }
                case 4:
                {
                    cafestaff.ManageDiscountPromotion(); // calling function to manage discount
                    administrator.ViewMenu(menuItems, 15);
                    cafestaff.ViewMenu_for_new_items();
                    break;
                }
                case 5:
                {
                    administrator.ViewOrderHistory();
                    break;
                }
                case 6:
                {
                    int noti;
                    cout << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << setw(73) << "| 1: Add Notification            |" << endl;
                    cout << setw(73) << "| 2: Remove Notification         |" << endl;
                    cout << setw(72) << "--------------------------------" << endl;
                    cout << "Enter your choice: ";
                    cin >> noti;

                    if (noti == 1)
                    {
                        administrator.AddNotification();
                    }

                    else if (noti == 2)
                    {
                        administrator.RemoveNotification();
                    }

                    break;
                }
                case 7:
                {
                    rate.Rate(); // calling the function to rate the item according to the user
                    break;
                }
                case 8:
                {
                    administrator.DisplayFromFile();
                    break;
                }
                case 9:
                {
                    administrator.ViewUsersFromFile();
                    break;
                }
                case 10:
                {
                    administrator.ViewMenuItemsFromFile();
                    break;
                }
                case 11:
                {
                    administrator.ViewOrderHistory();
                    break;
                }
                case 12:
                {
                    administrator.ViewRatingsFromFile();
                    break;
                }
                case 13:
                {
                    administrator.ViewPaymentsFromFile();
                    break;
                }
                case 14:
                {
                    customer.CalculateMonthlyEarnings();
                    break;
                }
                case 15:
                {
                    cout << "Logging out as a Administrator" << endl;
                    currentUser->Logout();
                    break;
                }
                default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
                }
                if (ac == 15)
                {
                    break;
                }

            }
        }
        cout << "\n\n-------------------------------------------------------------------------" << endl;
    }
    return 0;
}