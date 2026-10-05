#include "CLIUtilities.h"
#include "Transaction.h"
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

// Gets relevant Customer object needed to run void cliUtilities::createTransactionFromInput(Customer &customer)
void cliUtilities::initiateTransactionFromInput(CustomerRepository &repository)
{
    int target;

    std::cout << "Enter customer ID: ";
    std::cin >> target;

    Customer *customer = repository.findCustomerByID(target);

    if (customer == nullptr)
    {
        std::cout << "Customer not found.\n";
        return;
    }

    createTransactionFromInput(*customer);
}

void cliUtilities::createTransactionFromInput(Customer &customer)
{
    std::string initType;
    std::string initDate;
    double initAmount;

    std::cout << "Enter transaction type: ";
    std::getline(std::cin >> std::ws, initType);

    std::cout << "Enter transaction date: ";
    std::getline(std::cin >> std::ws, initDate);

    std::cout << "Enter transaction amount: $";
    std::cin >> initAmount;

    Transaction newTransaction(
        initType,
        initDate,
        initAmount);

    customer.addTransaction(newTransaction);

    return;
}
// Gets relevant Customer object needed to run void cliUtilities::createInteractionFromInput(Customer &customer)
void cliUtilities::initiateInteractionFromInput(CustomerRepository &repository)
{
    int target;

    std::cout << "Enter customer ID: ";
    std::cin >> target;

    Customer *customer = repository.findCustomerByID(target);

    if (customer == nullptr)
    {
        std::cout << "Customer not found.\n";
        return;
    }

    createInteractionFromInput(*customer);
}

void cliUtilities::createInteractionFromInput(Customer &customer)
{
    std::string initType;
    std::string initDate;
    std::string initNotes;

    std::cout << "Enter interaction type: ";
    std::getline(std::cin >> std::ws, initType);

    std::cout << "Enter interaction date: ";
    std::getline(std::cin >> std::ws, initDate);

    std::cout << "Enter interaction notes: ";
    std::cin >> initNotes;

    Interaction newInteraction(
        initType,
        initDate,
        initNotes);

    customer.addInteraction(newInteraction);

    return;
}

void cliUtilities::displayCustomers(CustomerRepository &repository)
{
    for (const Customer &customer : repository.getCustomers())
    {
        std::cout << std::endl;
        std::cout << "Customer ID: " << customer.getID() << "\n";
        std::cout << "Customer Name: " << customer.getName() << "\n";
        std::cout << "Customer Organization: " << customer.getOrganization() << "\n";
        std::cout << "Customer Email: " << customer.getEmail() << "\n";
        std::cout << "Customer Location: " << customer.getLocation() << "\n";
        std::cout << "Customer Representative: " << customer.getRepresentative() << "\n";
        std::cout << "Is Active Customer: " << customer.getIsActive() << "\n";
        std::cout << "Liftime Customer Value: $" << customer.calculateLifetimeCustomerValue() << "\n";
    }
};