#include "CLIUtilities.h"
#include "CustomerRepository.h"
#include <iostream>

int main()
{
    CustomerRepository repository;
    cliUtilities cli;
    int choice = 0;

    while (choice != 5)
    {
        std::cout << "\n ;) CHARM CRM <3" << std::endl;
        std::cout << "1. Create Customer Record" << std::endl;
        std::cout << "2. View Customer Records" << std::endl;
        std::cout << "3. Create New Transaction" << std::endl;
        std::cout << "4. Create New Interaction" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            cli.createCustomerFromInput(repository);
            break;
        case 2:
            cli.displayCustomers(repository);
            break;
        case 3:
            cli.initiateTransactionFromInput(repository);
            break;
        case 4:
            cli.initiateInteractionFromInput(repository);
            break;
        case 5:
            std::cout << "Thanks for using CHARM!" << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please select option 1 - 5." << std::endl;
        }
    }

    return 0;
}