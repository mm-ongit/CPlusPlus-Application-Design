#include "CustomerRepository.h"
#include "Customer.h"

// Class Constructor
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
// void CustomerRepository::findCustomerById() {};

// void CustomerRepository::findCustomerByName() {};

// void CustomerRepository::findCustomerByOrganization() {};

// void  CustomerRepository::findCustomerByRole() {};

// void  CustomerRepository::findCustomerByEmail() {};

// void  CustomerRepository::findCustomerByCity() {};

// void CustomerRepository::findCustomerByState() {};