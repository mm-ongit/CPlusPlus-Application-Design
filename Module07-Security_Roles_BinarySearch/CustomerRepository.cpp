#include "CustomerRepository.h"
#include "Customer.h"

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