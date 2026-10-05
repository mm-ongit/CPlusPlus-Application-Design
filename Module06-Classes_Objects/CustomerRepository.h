#pragma once

#include <vector>
#include <string>
#include "Customer.h"

class CustomerRepository
{
private:
    std::vector<Customer> customers;
    int next_customer_id = 1;

public:
    void addCustomer(
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
        bool initIsActive);

    // Getters
    const std::vector<Customer> &getCustomers() const;

    // Setters
    // void updateCustomer();
    // void removeCustomer();

    // Searchers
    Customer *findCustomerByID(int target);

    // Customer* findCustomerByName(std::string target);

    // Customer* findCustomerByOrganization(std::string target);

    // Customer* findCustomerByRole(std::string target);

    // Customer* findCustomerByEmail(std::string target);

    // Customer* findCustomerByCity(std::string target);

    // Customer* findCustomerByState(std::string target);
};