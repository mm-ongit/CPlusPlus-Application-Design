#include <iostream>
#include <string>
using namespace std;

void addCustomer()
{
    cout << "Add Customer selected." << endl;
}

void viewCustomer()
{
    cout << "View Customer selected." << endl;
}

void searchCustomers()
{
    cout << "Search Customers selected." << endl;
}

void updateCustomer()
{
    cout << "Update Customer selected." << endl;
}

int main()
{
    int choice = 0;

    while (choice != 4)
    {
        cout << "\n ;) CHARM CRM <3" << endl;
        cout << "1. Create Customer Record" << endl;
        cout << "2. View Customer Record" << endl;
        cout << "3. Search Customer Records" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            viewCustomer();
            break;
        case 3:
            searchCustomers();
            break;
        case 4:
            cout << "Thanks for using CHARM!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select option 1 - 4." << endl;
        }
    }

    return 0;
}