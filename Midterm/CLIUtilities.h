#pragma once

#include <iostream>
#include "CustomerRepository.h"
#include "UserRepository.h"

class cliUtilities
{
private:
    bool initializeProgramFlag = true;
    std::string usersSaveFileName = "users.csv";

public:
    // Methods
    void start();
    void displayInitializationMenu(CustomerRepository &cRep, UserRepository &uRep);
    int displayLogInMenu(CustomerRepository &cRep, UserRepository &uRep);
    int displayStandardMenu(CustomerRepository &cRep, UserRepository &uRep);
    int displayAdminMenu(CustomerRepository &cRep, UserRepository &uRep);
    void createCustomerFromInput(CustomerRepository &cRep);
    void createUserFromInput(UserRepository &uRep);
    void findCustomerByID(CustomerRepository &cRep);
    void findUserByID(UserRepository &uRep);
    void initiateTransactionFromInput(CustomerRepository &cRep);
    void createTransactionFromInput(Customer &customer);
    void initiateInteractionFromInput(CustomerRepository &cRep);
    void createInteractionFromInput(Customer &customer);
    void displayCustomers(CustomerRepository &cRep);
    void displayUsers(UserRepository &uRep);

    int initiateSaveUsersToFile(UserRepository &uRep, std::string &usersSaveFileName);
    int initiateLoadUserDataFromFile(UserRepository &uRep, std::string &usersSaveFileName);

    // Getter
    bool getInitializeProgramFlag()
    {
        return initializeProgramFlag;
    }

    // Setter
    void updateInitializeProgramFlag()
    {
        if (getInitializeProgramFlag())
        {
            initializeProgramFlag = false;
        }
        else
        {
            initializeProgramFlag = true;
        }
    }
};