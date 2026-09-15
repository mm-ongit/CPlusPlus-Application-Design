#include <iostream>
#include <string>
#include <chrono>
using namespace std;

int main()
{
    // System Manager Variables
    string app_name = "Charm CRM";
    float version_number = 0.1f;
    string current_username = "malik@charmcrm.com";
    int current_user_id = 001;

    // Customer Variables
    int customer_id = 001;
    string first = "John";
    string last = "Smith";
    string organization = "John's Diner";
    string email = "john@johnsdiner.com";
    string phone_number = "5552687843";
    string city = "Oakland";
    string state = "California";
    string address = "222 Lake St.";
    string representative = "malik@charmcrm.com";
    bool is_active = true;
    double lifetime_customer_value = 500.75;

    // User Variables
    int user_id = 001;
    string username = "malik@charmcrm.com";
    string password = "some_hash";
    string department = "engineering";
    bool is_admin = true;

    // Table Variables
    int table_id = 001;
    string table_name = "customers";

    cout << "--SYSTEM MANAGER VARIABLES--" << endl;
    cout << "Application Name: " << app_name << endl;
    cout << "Version Number: " << version_number << endl;
    cout << "Current User Name: " << current_username << endl;
    cout << "Current User ID: " << current_user_id << endl
         << endl;

    cout << "--CUSTOMER VARIABLES--" << endl;
    cout << "Customer ID: " << customer_id << endl;
    cout << "First Name: " << first << endl;
    cout << "Last Name: " << last << endl;
    cout << "Organization: " << organization << endl;
    cout << "Email: " << email << endl;
    cout << "Phone Number: " << phone_number << endl;
    cout << "City: " << city << endl;
    cout << "State: " << state << endl;
    cout << "Address: " << address << endl;
    cout << "Representative: " << representative << endl;
    cout << "Is Active Customer: " << is_active << endl;
    cout << "Lifetime Customer Value: " << lifetime_customer_value << endl
         << endl;

    cout << "--USER VARIABLES--" << endl;
    cout << "User ID: " << user_id << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Department: " << department << endl;
    cout << "Is Admin: " << is_admin << endl
         << endl;

    cout << "--TABLE VARIABLES--" << endl;
    cout << "Table ID: " << table_id << endl;
    cout << "Table Name: " << table_name << endl
         << endl;

    return 0;
}