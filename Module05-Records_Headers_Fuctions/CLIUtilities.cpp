#include "CLIUtilities.h"
#include <sstream>

void cliUtilities::createCustomerFromInput(CustomerRepository &repository)
{
    int initCustomerID;
    std::string initFirstName;
    std::string initLastName;
    std::string initOrganization;
    std::string initEmail;
    std::string initPhoneNumber;
    std::string initCity;
    std::string initState;
    std::string initAddress;
    std::string initRepresentative;
    bool initIsActive = true;

    std::cout << "First name: ";
    std::getline(std::cin, initFirstName);

    std::cout << "Last name: ";
    std::getline(std::cin, initLastName);

    std::cout << "Organization: ";
    std::getline(std::cin, initOrganization);

    std::cout << "Email: ";
    std::getline(std::cin, initEmail);

    std::cout << "Phone number: ";
    std::getline(std::cin, initPhoneNumber);

    std::cout << "City: ";
    std::getline(std::cin, initCity);

    std::cout << "State: ";
    std::getline(std::cin, initState);

    std::cout << "Address: ";
    std::getline(std::cin, initAddress);

    std::cout << "Representative: ";
    std::getline(std::cin, initRepresentative);

    repository.addCustomer(
        initCustomerID,
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
};

void cliUtilities::displayCustomers(CustomerRepository &repository)
{
    for (const Customer &customer : repository.getCustomers())
    {
        // Add customer ID when I figure out how to auto-generate unique ID #s
        std::cout << std::endl;
        std::cout << "Customer ID: " << customer.getID() << "\n";
        std::cout << "Customer Name: " << customer.getName() << "\n";
        std::cout << "Customer Email: " << customer.getEmail() << "\n";
        std::cout << "Customer Organization: " << customer.getOrganization() << "\n";
        std::cout << "Customer Location: " << customer.getLocation() << "\n";
        std::cout << "Customer Representative: " << customer.getRepresentative() << "\n";
        std::cout << "Is Active Customer: " << customer.getIsActive() << "\n";
        // Add LCV when I figure out how to calculate LCV
    }
};