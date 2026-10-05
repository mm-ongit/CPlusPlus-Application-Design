#pragma once

#include <iostream>
#include "CustomerRepository.h"

class cliUtilities
{
public:
    void createCustomerFromInput(CustomerRepository &repository);
    void initiateTransactionFromInput(CustomerRepository &repository);
    void createTransactionFromInput(Customer &customer);
    void initiateInteractionFromInput(CustomerRepository &repository);
    void createInteractionFromInput(Customer &customer);
    void displayCustomers(CustomerRepository &repository);
};