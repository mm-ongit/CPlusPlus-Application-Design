#pragma once

#include <iostream>
#include "CustomerRepository.h"
#include "UserRepository.h"
#include "ValidationUtilities.h"

class cliUtilities
{
private:
    bool initializeProgramFlag = true;
    std::string usersSaveFileName = "users.csv";
    std::string customersSaveFileName = "customers.csv";

public:
    // Methods
    void start();
    void displayInitializationMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU); // tested - done
    int displayLogInMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU);           // tested - 1 issue - entering 12 passes check to proceed with log in, why?

    int displayStandardMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU); // checked
    int displayAdminMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU);    // checked

    void createCustomerFromInput(CustomerRepository &cRep, ValidationUtilities &vU); // teested
    void createUserFromInput(UserRepository &uRep, ValidationUtilities &vU);         // tested

    void findCustomerByID(CustomerRepository &cRep); // checked
    void findUserByID(UserRepository &uRep);         // checked

    void initiateTransactionFromInput(CustomerRepository &cRep, ValidationUtilities &vU); // tested
    void createTransactionFromInput(Customer &customer, ValidationUtilities &vU);         // tested
    void initiateInteractionFromInput(CustomerRepository &cRep, ValidationUtilities &vU); // tested
    void createInteractionFromInput(Customer &customer, ValidationUtilities &vU);         // tested

    void displayCustomers(CustomerRepository &cRep); // checked
    void displayUsers(UserRepository &uRep);         // checked

    int initiateSaveUsersToFile(UserRepository &uRep, std::string &usersSaveFileName, ValidationUtilities &vU); // tested
    int initiateLoadUserDataFromFile(UserRepository &uRep, std::string &usersSaveFileName);
    int initiateSaveCustomersToFile(CustomerRepository &cRep, std::string &customersSaveFileName, ValidationUtilities &vU); // testing - 1 issue - .csv passes validFileNName check, why?
    int initiateLoadCustomerDataFromFile(CustomerRepository &cRep, std::string &customersSaveFileName);

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