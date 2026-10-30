#include "CustomerRepository.h"
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void CustomerRepository::addCustomer(
    int initCustomerID,
    const std::string &initFirstName,
    const std::string &initLastName,
    const std::string &initOrganization,
    const std::string &initEmail,
    const std::string &initPhoneNumber,
    const std::string &initCity,
    const std::string &initState,
    const std::string &initAddress,
    const std::string &initRepresentative,
    bool initIsActive)
{
    Customer newCustomer(
        next_customer_id,
        initFirstName,
        initLastName,
        initOrganization,
        initEmail,
        initPhoneNumber,
        initCity,
        initState,
        initAddress,
        initRepresentative,
        initIsActive);

    customers.push_back(newCustomer);
    next_customer_id += 1;
};

// Getters
const std::vector<Customer> &CustomerRepository::getCustomers() const
{
    return customers;
};

// Setters
// void CustomerRepository::updateCustomer() {};

// void CustomerRepository::removeCustomer() {};

// Searchers
Customer *CustomerRepository::findCustomerByID(int target)
{
    // Binary Search
    int low = 0;
    int high = static_cast<int>(customers.size()) - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (customers[middle].getID() == target)
        {
            return &customers[middle];
        }
        else if (customers[middle].getID() < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return nullptr;
}

// void CustomerRepository::findCustomerByName() {};
// void CustomerRepository::findCustomerByOrganization() {};
// void  CustomerRepository::findCustomerByRole() {};
// void  CustomerRepository::findCustomerByEmail() {};
// void  CustomerRepository::findCustomerByCity() {};
// void CustomerRepository::findCustomerByState() {};

// Functions
int CustomerRepository::saveCustomersToFile(const std::string &customersSaveFileName) const
{
    // open or create file
    std::ofstream file(customersSaveFileName);

    // check if file is open successfully
    if (!file.is_open())
    {
        std::cerr << "Could Not Open or Create Users Save File" << std::endl;
        return 1;
    }

    // write header row
    // "\n" end line break signals start of new row
    file << "customer_id,first,last,organization,email,phone_number,city,state,address,representative,is_active\n";

    // write data rows with a loop
    for (const Customer &customer : customers)
    {
        file << customer.getID() << ","
             << customer.getFirstName() << ","
             << customer.getLastName() << ","
             << customer.getOrganization() << ","
             << customer.getEmail() << ","
             << customer.getPhoneNumber() << ","
             << customer.getCity() << ","
             << customer.getState() << ","
             << customer.getAddress() << ","
             << customer.getRepresentative() << ",";

        if (customer.getIsActive() == true)
        {
            file << "1";
        }
        else
        {
            file << "0";
        }

        file << "\n";
    }

    // close the file
    file.close();
    return 0;
}

int CustomerRepository::loadCustomerDataFromFile(const std::string &customersSaveFileName)
{
    // Open CSV
    std::ifstream file(customersSaveFileName);

    // Check if file opened successfully - error if not
    if (!file.is_open())
    {
        std::cerr << "Error: Load Customer Data Unsuccessful" << std::endl;
        return 1;
    }

    // Create a string to hold data from each row of dataset
    std::string line;

    // Initialize a counter to iterate dataset
    // std::size_t is unsigned int type, can represent size/non-negative index of any object, always 0 or greater
    // Choose over int to avoid comparison of signed and unsigned values when iterating
    std::size_t count = 0;

    // Read the file line by line
    // Note: When getline() succeeds it evaluates to true, can be used as boolean flag in loop
    while (std::getline(file, line))
    {
        // Skip header row in csv
        if (count == 0)
        {
            ++count;
            continue;
        }

        // Create a string stream object to hold data in each line
        // Note: getline() can only act on stream objects, so stream object containing contents of string line is created with ss()
        std::stringstream ss(line);
        // Create a variable called cell to hold individual data points
        std::string cell;
        // Create a list called row to hold data in cells
        std::vector<std::string> row;

        // Split the string stream object by commas, save result in cell
        while (std::getline(ss, cell, ','))
        {
            // Append data in each cell to row
            row.push_back(cell);
        }

        // Check if row has data for all 11 params
        if (row.size() < 11)
        {
            continue;
        }

        // Create placeholder for Customer ID (because IDs are int not strings)
        // Convert text ID to appropriate int object
        int customer_id = std::stoi(row[0]);

        // next_user_id only exists when program is in use
        // Ensures next_user_id tracks most recently used ID# and increments new IDs from there
        if (customer_id >= next_customer_id)
        {
            next_customer_id = customer_id + 1;
        }

        // Create placeholder for is_admin (because is_admin flags are bool objects, not strings)
        bool is_admin;

        // Convert text role to appropriate UserRole object
        // If index does not contain "Admin" or "Standard" skip row altogether
        if (row[10] == "1")
        {
            is_admin = true;
        }
        else
        {
            is_admin = false;
        }

        // Construct new Customer object
        Customer customerFromFile(
            customer_id,
            row[1],
            row[2],
            row[3],
            row[4],
            row[5],
            row[6],
            row[7],
            row[8],
            row[9],
            is_admin);
        // Add new User object to users
        customers.push_back(customerFromFile);

        ++count;
    }

    return 0;
}