#include "Customer.h"

// Implement Constructor method
Customer::Customer(
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
    bool initIsActive) : customer_id(initCustomerID),
                         first(initFirstName),
                         last(initLastName),
                         organization(initOrganization),
                         email(initEmail),
                         phone_number(initPhoneNumber),
                         city(initCity),
                         state(initState),
                         address(initAddress),
                         representative(initRepresentative),
                         is_active(initIsActive) {}

// Derive LCV
double Customer::calculateLifetimeCustomerValue() const
{
    double total = 0.0;

    for (const Transaction &transaction : transactions)
    {
        total += transaction.getAmount();
    }

    return total;
}

// Add new Transaction to list of transactions
void Customer::addTransaction(const Transaction &transaction)
{
    transactions.push_back(transaction);
}

// Add new Interaction to list of interactions
void Customer::addInteraction(const Interaction &interaction)
{
    interactions.push_back(interaction);
}

// void Customer::viewTransactions() const;
// void Customer::viewInteractions() const;