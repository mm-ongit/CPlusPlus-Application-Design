// Prevents header file from being imported more than once
#pragma once

#include <string>
#include <vector>
#include "Transaction.h"
#include "Interaction.h"

class Customer
{

private:
    int customer_id;
    std::string first;
    std::string last;
    std::string organization;
    std::string email;
    std::string phone_number;
    std::string city;
    std::string state;
    std::string address;
    std::string representative;
    bool is_active;

    // Lists of interactions and transactions with each customer
    std::vector<Transaction> transactions;
    std::vector<Interaction> interactions;

public:
    // Class Constructor
    Customer(
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
    int getID() const
    {
        return customer_id;
    }
    std::string getName() const
    {
        return (first + " " + last);
    }
    std::string getEmail() const
    {
        return email;
    }
    std::string getPhoneNumber() const
    {
        return phone_number;
    }
    std::string getOrganization() const
    {
        return organization;
    }
    std::string getLocation() const
    {
        return (address + " " + city + "," + state);
    }
    std::string getRepresentative() const
    {
        return representative;
    }
    bool getIsActive() const
    {
        return is_active;
    }

    // Setters
    void updateName(const std::string &newFirst, const std::string &newLast)
    {
        first = newFirst;
        last = newLast;
    }
    void updateEmail(const std::string &newEmail)
    {
        email = newEmail;
    }
    void updatePhoneNumber(const std::string &newPhoneNumber)
    {
        phone_number = newPhoneNumber;
    }
    void updateOrganization(const std::string &newOrganization)
    {
        organization = newOrganization;
    }
    void updateLocation(const std::string &newAddress, const std::string &newCity, const std::string &newState)
    {
        address = newAddress;
        city = newCity;
        state = newState;
    }
    void updateRepresentative(const std::string &newRepresentative)
    {
        representative = newRepresentative;
    }

    // Methods
    void deactivate()
    {
        is_active = false;
    }
    void activate()
    {
        is_active = true;
    }
    double calculateLifetimeCustomerValue() const;

    void addTransaction(const Transaction &transaction);
    void addInteraction(const Interaction &interaction);

    // void viewTransactions()
    // void viewInteractions()
};