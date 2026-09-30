#pragma once

#include <iostream>
#include "CustomerRepository.h"

class cliUtilities
{
public:
    void createCustomerFromInput(CustomerRepository &repository);
    void displayCustomers(CustomerRepository &repository);
};