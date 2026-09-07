#include <iostream>
#include <string>
using namespace std;

void createCustomer()
{
    cout << "Create Customer selected." << endl;
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

void deleteCustomer()
{
    cout << "Delete Customer selected" << endl;
}

int main()
{
    int choice = 0;

    while (choice != 6)
    {
        cout << "\n ;) CHARM CRM <3" << endl;
        cout << "1. Create Customer Record" << endl;
        cout << "2. View Customer Record" << endl;
        cout << "3. Search Customer Records" << endl;
        cout << "4. Update Customer Record" << endl;
        cout << "5. Delete Customer Record" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            createCustomer();
            break;
        case 2:
            viewCustomer();
            break;
        case 3:
            searchCustomers();
            break;
        case 4:
            updateCustomer();
            break;
        case 5:
            deleteCustomer();
            break;
        case 6:
            cout << "Thanks for using CHARM!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select option 1 - 6." << endl;
        }
    }

    return 0;
}