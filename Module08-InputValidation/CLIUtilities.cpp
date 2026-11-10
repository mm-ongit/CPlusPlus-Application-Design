#include "CLIUtilities.h"
#include "Transaction.h"
#include "Interaction.h"
#include <sstream>
#include <cstdlib>

void cliUtilities::start()
{
    CustomerRepository cRep;
    UserRepository uRep;
    ValidationUtilities vU;

    if (initiateLoadUserDataFromFile(uRep, usersSaveFileName) == 0 && initiateLoadCustomerDataFromFile(cRep, customersSaveFileName) == 0 && getInitializeProgramFlag())
    {
        displayLogInMenu(cRep, uRep, vU);
    }
    else
    {
        if (getInitializeProgramFlag())
        {
            displayInitializationMenu(cRep, uRep, vU);
        }
        else
        {
            std::cerr << "Error: Loading Data Unsuccessful" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

void cliUtilities::displayInitializationMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU)
{
    int choice;

    std::cout << "\n ;) CHARM CRM - Initialization (1/2) <3" << std::endl;
    std::cout << "Welcome to Charm CRM" << std::endl;
    std::cout << "Enter 1 To Create An Admin User" << std::endl;
    std::cout << "Enter Any Other Number To Exit" << std::endl;
    std::cout << "Choose An Option: ";

    while (!(std::cin >> choice))
    {
        std::cout << "Input invalid. Please enter a number 0 - 9: ";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cin.ignore();

    switch (choice)
    {
    case 1:
        createUserFromInput(uRep, vU);
        break;
    default:
        std::cout << "Thanks for using CHARM!" << std::endl;
        return;
    }

    std::cout << std::endl;
    std::cout << "\n ;) CHARM CRM - Initialization (2/2) <3" << std::endl;
    std::cout << "Enter 1 To Create A Standard User" << std::endl;
    std::cout << "Enter Any Other Number To Exit" << std::endl;
    std::cout << "Choose An Option: ";

    while (!(std::cin >> choice))
    {
        std::cout << "Input invalid. Please enter a number 0 - 9: ";
    }

    std::cin.ignore();

    switch (choice)
    {
    case 1:
        createUserFromInput(uRep, vU);
        break;
    default:
        std::cout << "Thanks for using CHARM!" << std::endl;
        return;
    }

    updateInitializeProgramFlag();
    displayLogInMenu(cRep, uRep, vU);
}

// Note: passwordHash is saved as plaintext password while construction is ongoing, will change to real hash later
int cliUtilities::displayLogInMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU)
{
    char log_in_flag;
    std::string email;
    std::string password;

    while (true)
    {
        std::cout << "\n ;) CHARM CRM - Login (1/3) <3" << std::endl;
        std::cout << "Enter 1 To Log In " << std::endl;
        std::cout << "Enter 2 To Exit " << std::endl;
        std::cout << "Choose Option: ";

        while (!(std::cin >> log_in_flag))
        {
            std::cout << "Input invalid. Please enter 1 or 2: ";
            std::cin.clear();
        }

        if (!(std::isdigit(static_cast<unsigned char>(log_in_flag))))
        {
            std::cout << "Input invalid. Please enter 1 or 2: ";
            std::cin.clear();
            std::cin >> log_in_flag;
        }

        std::cin.ignore();

        if (log_in_flag != '1' && log_in_flag != '2')
        {
            std::cout << std::endl;
            std::cout << "Input invalid. Please enter 1 or 2: " << std::endl;
            displayLogInMenu(cRep, uRep, vU);
        }

        if (log_in_flag == '2')
        {
            std::cout << "Thanks for using CHARM!" << std::endl;
            break;
        }

        std::cout << "\n ;) CHARM CRM - Login (2/3) <3" << std::endl;
        std::cout << "Enter Email: ";
        std::cin >> email;

        while (!(vU.validEmail(email)))
        {
            std::cout << "Input invalid. Please enter email: ";
            std::cin >> email;
        }

        std::cin.ignore();

        std::cout << "\n ;) CHARM CRM - Login (3/3) <3" << std::endl;
        std::cout << "Enter Password: ";
        std::cin >> password;

        while (!(vU.validPassword(password)))
        {
            std::cout << "Input invalid. Please enter password: ";
            std::cin >> email;
        }

        std::cin.ignore();

        User *user = uRep.findUserByEmail(email);

        if (user == nullptr)
        {
            std::cout << "No Record Found" << std::endl;
            continue;
        }

        // You should insert a password hash check here
        if (user->getPasswordHash() == password) // change password to check_hash(password) etc.
        {
            if (user->getAdminStatus() == UserRole::Admin)
            {
                displayAdminMenu(cRep, uRep, vU);
            }
            else
            {
                displayStandardMenu(cRep, uRep, vU);
            }
        }
        else
        {
            std::cout << "No Record Found";
        }
    }

    return 0;
}

int cliUtilities::displayStandardMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU)
{
    int choice = 0;

    while (choice != 6)
    {
        std::cout << "\n ;) CHARM CRM <3" << std::endl;
        std::cout << "1. View Customer Records" << std::endl;
        std::cout << "2. View User Records" << std::endl;
        std::cout << "3. Find Customer By ID" << std::endl;
        std::cout << "4. Find User By ID" << std::endl;
        std::cout << "5. Log Out" << std::endl;
        std::cout << "Choose an option: ";

        while (!(std::cin >> choice))
        {
            std::cout << "Input invalid. Please enter a number 1 - 5: ";
            std::cin.clear();
        }

        std::cin.ignore();

        switch (choice)
        {
        case 1:
            displayCustomers(cRep);
            break;
        case 2:
            displayUsers(uRep);
            break;
        case 3:
            findCustomerByID(cRep);
            break;
        case 4:
            findUserByID(uRep);
            break;
        case 5:
            std::cout << "Thanks for using CHARM!" << std::endl;
            return 0;
        default:
            std::cout << "Input invalid. Please select option 1 - 5." << std::endl;
        }
    }

    return 0;
}

int cliUtilities::displayAdminMenu(CustomerRepository &cRep, UserRepository &uRep, ValidationUtilities &vU)
{
    int choice = 0;

    while (choice != 10)
    {
        std::cout << "\n ;) CHARM CRM <3" << std::endl;
        std::cout << "1. Create New Customer Record" << std::endl;
        std::cout << "2. Create New User Record" << std::endl;
        std::cout << "3. View Customer Records" << std::endl;
        std::cout << "4. View User Records" << std::endl;
        std::cout << "5. Find Customer By ID" << std::endl;
        std::cout << "6. Find User By ID" << std::endl;
        std::cout << "7. Create New Transaction" << std::endl;
        std::cout << "8. Create New Interaction" << std::endl;
        std::cout << "9. Save And Log Out" << std::endl;
        std::cout << "Choose an option: ";

        while (!(std::cin >> choice))
        {
            std::cout << "Input invalid. Please enter a number 1 - 9: ";
        }

        std::cin.ignore();

        switch (choice)
        {
        case 1:
            createCustomerFromInput(cRep, vU);
            break;
        case 2:
            createUserFromInput(uRep, vU);
            break;
        case 3:
            displayCustomers(cRep);
            break;
        case 4:
            displayUsers(uRep);
            break;
        case 5:
            findCustomerByID(cRep);
            break;
        case 6:
            findUserByID(uRep);
            break;
        case 7:
            initiateTransactionFromInput(cRep, vU);
            break;
        case 8:
            initiateInteractionFromInput(cRep, vU);
            break;
        case 9:
            initiateSaveUsersToFile(uRep, usersSaveFileName, vU);
            initiateSaveCustomersToFile(cRep, customersSaveFileName, vU);
            std::cout << "Thanks for using CHARM!" << std::endl;
            return 0;
        default:
            std::cout << "Input invalid. Please select option 1 - 9." << std::endl;
        }
    }

    return 0;
}

void cliUtilities::createCustomerFromInput(CustomerRepository &cRep, ValidationUtilities &vU)
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

    std::cout << "First name: " << std::flush;
    std::getline(std::cin, initFirstName);

    while (!(vU.validName(initFirstName)))
    {
        std::cout << "Input invalid. Please enter first name: ";
        std::getline(std::cin, initFirstName);
    }

    std::cout << "Last name: ";
    std::getline(std::cin, initLastName);

    while (!(vU.validName(initLastName)))
    {
        std::cout << "Input invalid. Please enter last name: ";
        std::getline(std::cin, initLastName);
    }

    std::cout << "Organization: ";
    std::getline(std::cin, initOrganization);

    while (!(vU.validName(initOrganization)))
    {
        std::cout << "Input invalid. Please enter organization name: ";
        std::getline(std::cin, initOrganization);
    }

    std::cout << "Email: ";
    std::getline(std::cin, initEmail);

    while (!(vU.validEmail(initEmail)))
    {
        std::cout << "Input invalid. Please enter email: ";
        std::getline(std::cin, initEmail);
    }

    std::cout << "Phone number: ";
    std::getline(std::cin, initPhoneNumber);

    while (!(vU.validPhoneNumber(initPhoneNumber)))
    {
        std::cout << "Input invalid. Please enter phone number: ";
        std::getline(std::cin, initPhoneNumber);
    }

    std::cout << "City: ";
    std::getline(std::cin, initCity);

    while (!(vU.validCity(initCity)))
    {
        std::cout << "Input invalid. Please enter city: ";
        std::getline(std::cin, initCity);
    }

    std::cout << "State: ";
    std::getline(std::cin, initState);

    while (!(vU.validState(initState)))
    {
        std::cout << "Input invalid. Please enter state abbreviation: ";
        std::getline(std::cin, initPhoneNumber);
    }

    std::cout << "Address: ";
    std::getline(std::cin, initAddress);

    while (!(vU.validAddress(initAddress)))
    {
        std::cout << "Input invalid. Please enter address: ";
        std::getline(std::cin, initAddress);
    }

    std::cout << "Representative: ";
    std::getline(std::cin, initRepresentative);

    while (!(vU.validEmail(initRepresentative)))
    {
        std::cout << "Input invalid. Please enter representative email address: ";
        std::getline(std::cin, initPhoneNumber);
    }

    cRep.addCustomer(
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

// Note: passwordHash is saved as plaintext password while construction is ongoing, will change to real hash later
void cliUtilities::createUserFromInput(UserRepository &uRep, ValidationUtilities &vU)
{
    std::string initFirst;
    std::string initLast;
    std::string initEmail;
    std::string initPasswordHash = "";
    std::string initDepartment;
    UserRole initRole;
    std::string initPassword = "";
    std::string initAccessLevel = "";

    std::cout << "First name: " << std::flush;
    std::getline(std::cin, initFirst);

    while (!(vU.validName(initFirst)))
    {
        std::cout << "Input invalid. Please enter first name: " << std::flush;
        std::getline(std::cin, initFirst);
    }

    std::cout << "Last name: ";
    std::getline(std::cin, initLast);

    while (!(vU.validName(initLast)))
    {
        std::cout << "Input invalid. Please enter last name: ";
        std::getline(std::cin, initLast);
    }

    std::cout << "Email: ";
    std::getline(std::cin, initEmail);

    while (!(vU.validEmail(initEmail)))
    {
        std::cout << "Input invalid. Please enter email address: ";
        std::getline(std::cin, initEmail);
    }

    // Loop to validate Password
    while (initPassword == "")
    {
        std::cout << "Password: ";
        std::getline(std::cin, initPassword);

        while (!(vU.validPassword(initPassword)))
        {
            std::cout << "Input invalid. Please enter password: ";
            std::getline(std::cin, initPassword);
        }

        // Add password hasher here
        initPasswordHash = initPassword; // change initPassword to password_hasher(initPassword)

        break;
    }

    std::cout << "Department: ";
    std::getline(std::cin, initDepartment);

    while (!(vU.validName(initDepartment)))
    {
        std::cout << "Input invalid. Please enter department name: ";
        std::getline(std::cin, initDepartment);
    }

    // Loop to validate Access Level
    while (initAccessLevel != "Standard" && initAccessLevel != "Admin")
    {
        std::cout << "Access Level: ";
        std::getline(std::cin, initAccessLevel);

        if (initAccessLevel != "Standard" && initAccessLevel != "Admin")
        {
            std::cout << "Please enter either Standard or Admin.\n";
        }

        if (initAccessLevel == "Admin")
        {
            initRole = UserRole::Admin;
        }
        else if (initAccessLevel == "Standard")
        {
            initRole = UserRole::Standard;
        }
    }

    uRep.addUser(
        initFirst,
        initLast,
        initEmail,
        initPasswordHash,
        initDepartment,
        initRole);
}

void cliUtilities::findCustomerByID(CustomerRepository &cRep)
{
    int target;

    std::cout << "\n";
    std::cout << "Enter Customer ID: ";
    while (!(std::cin >> target))
    {
        std::cout << "Input invalid. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cin.ignore();

    Customer *customer = cRep.findCustomerByID(target);

    if (customer != nullptr)
    {
        std::cout << std::endl;
        std::cout << "Customer ID: " << customer->getID() << '\n';
        std::cout << "Name: " << customer->getFirstName() << " " << customer->getLastName() << '\n';
        std::cout << "Email: " << customer->getEmail() << '\n';
        std::cout << "Phone: " << customer->getPhoneNumber() << '\n';
        std::cout << "Organization: " << customer->getOrganization() << '\n';
        std::cout << "Location: " << customer->getAddress() << " " << customer->getCity() << ", " << customer->getState() << '\n';
        std::cout << "Representative: " << customer->getRepresentative() << '\n';
        std::cout << "Is Active Customer: " << customer->getIsActive() << "\n";
        std::cout << "Liftime Customer Value: $" << customer->calculateLifetimeCustomerValue() << "\n";
    }
    else
    {
        std::cout << "No Customer Found With That ID.";
    }

    return;
}

void cliUtilities::findUserByID(UserRepository &uRep)
{
    int target;

    std::cout << "Enter User ID: ";
    while (!(std::cin >> target))
    {
        std::cout << "Input invalid. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore();
    }

    std::cin.ignore();

    User *user = uRep.findUserByID(target);

    if (user != nullptr)
    {
        std::cout << std::endl;
        std::cout << "User ID: " << user->getID() << '\n';
        std::cout << "Name: " << user->getFirstName() << " " << user->getLastName() << '\n';
        std::cout << "Email: " << user->getEmail() << '\n';
        std::cout << "Department: " << user->getDepartment() << '\n';
    }
    else
    {
        std::cout << "No User Found With That ID.";
    }

    return;
}

// Gets relevant Customer object needed to run void cliUtilities::createTransactionFromInput(Customer &customer)
void cliUtilities::initiateTransactionFromInput(CustomerRepository &cRep, ValidationUtilities &vU)
{
    int target;

    std::cout << "Enter Customer ID: ";
    while (!(std::cin >> target))
    {
        std::cout << "Input invalid. Please enter a customer ID number: ";
        std::cin.clear();
    }

    std::cin.ignore();

    Customer *customer = cRep.findCustomerByID(target);

    if (customer == nullptr)
    {
        std::cout << "Customer not found.\n";
        return;
    }

    createTransactionFromInput(*customer, vU);
}

void cliUtilities::createTransactionFromInput(Customer &customer, ValidationUtilities &vU)
{
    std::string initType;
    std::string initDate;
    double initAmount;

    std::cout << "Enter transaction type: " << std::flush;
    std::getline(std::cin >> std::ws, initType);

    while (!(vU.validName(initType)))
    {
        std::cout << "Input invalid. Please enter transaction type: ";
        std::getline(std::cin, initType);
    }

    std::cout << "Enter transaction date: ";
    std::getline(std::cin >> std::ws, initDate);

    while (!(vU.validDate(initDate)))
    {
        std::cout << "Input invalid. Please enter transaction date: ";
        std::getline(std::cin, initDate);
    }

    std::cout << "Enter transaction amount: $";
    while (!(std::cin >> initAmount))
    {
        std::cout << "Invalid input. Please enter transaction amount: ";
        std::cin.clear();
        std::cin.ignore();
    }

    Transaction newTransaction(
        initType,
        initDate,
        initAmount);

    customer.addTransaction(newTransaction);

    return;
}
// Gets relevant Customer object needed to run void cliUtilities::createInteractionFromInput(Customer &customer)
void cliUtilities::initiateInteractionFromInput(CustomerRepository &cRep, ValidationUtilities &vU)
{
    int target;

    std::cout << "Enter Customer ID: ";
    while (!(std::cin >> target))
    {
        std::cout << "Input invalid. Please enter a customer ID number: ";
        std::cin.clear();
    }

    std::cin.ignore();

    Customer *customer = cRep.findCustomerByID(target);

    if (customer == nullptr)
    {
        std::cout << "Customer not found.\n";
        return;
    }

    createInteractionFromInput(*customer, vU);
}

void cliUtilities::createInteractionFromInput(Customer &customer, ValidationUtilities &vU)
{
    std::string initType;
    std::string initDate;
    std::string initNotes;

    std::cout << "Enter interaction type: " << std::flush;
    std::getline(std::cin >> std::ws, initType);

    while (!(vU.validName(initType)))
    {
        std::cout << "Input invalid. Please enter interaction type: ";
        std::getline(std::cin, initType);
    }

    std::cout << "Enter interaction date: ";
    std::getline(std::cin >> std::ws, initDate);

    while (!(vU.validDate(initDate)))
    {
        std::cout << "Input invalid. Please enter interaction date: ";
        std::getline(std::cin, initDate);
    }

    // Can be anything - how do I harden this?
    std::cout << "Enter interaction notes: ";
    std::getline(std::cin >> std::ws, initNotes);

    Interaction newInteraction(
        initType,
        initDate,
        initNotes);

    customer.addInteraction(newInteraction);

    return;
}

void cliUtilities::displayCustomers(CustomerRepository &cRep)
{
    for (const Customer &customer : cRep.getCustomers())
    {
        std::cout << std::endl;
        std::cout << "Customer ID: " << customer.getID() << "\n";
        std::cout << "Customer Name: " << customer.getFirstName() << " " << customer.getLastName() << "\n";
        std::cout << "Customer Organization: " << customer.getOrganization() << "\n";
        std::cout << "Customer Email: " << customer.getEmail() << "\n";
        std::cout << "Customer Location: " << customer.getAddress() << " " << customer.getCity() << ", " << customer.getState() << "\n";
        std::cout << "Customer Representative: " << customer.getRepresentative() << "\n";
        std::cout << "Is Active Customer: " << customer.getIsActive() << "\n";
        std::cout << "Liftime Customer Value: $" << customer.calculateLifetimeCustomerValue() << "\n";
    }
};

void cliUtilities::displayUsers(UserRepository &uRep)
{
    for (const User &user : uRep.getUsers())
    {
        std::cout << std::endl;
        std::cout << "User ID: " << user.getID() << "\n";
        std::cout << "User Name: " << user.getFirstName() << " " << user.getLastName() << "\n";
        std::cout << "User Email: " << user.getEmail() << "\n";
        std::cout << "User Department: " << user.getDepartment() << "\n";
    }
}

int cliUtilities::initiateSaveUsersToFile(UserRepository &uRep, std::string &usersSaveFileName, ValidationUtilities &vU)
{
    char response;

    std::cout << "Current User Data Filename: " << usersSaveFileName << "\n";
    std::cout << "Would you like to change the filename for user data? [y/n] \n";
    std::cout << "Choose Option: ";
    std::cin >> response;

    while (response != 'y' && response != 'n')
    {
        std::cout << "Input invalid. Please enter y or n: ";
        std::cin >> response;
    }

    std::cin.ignore();

    if (response == 'y')
    {
        std::cout << std::endl;
        std::cout << "Enter a New Filename: ";
        std::getline(std::cin >> std::ws, usersSaveFileName);

        while (!(vU.validFileName(usersSaveFileName)))
        {
            std::cout << "Input invalid. Please enter a filename. Include .csv: ";
            std::getline(std::cin >> std::ws, usersSaveFileName);
        }
    }

    if (uRep.saveUsersToFile(usersSaveFileName) == 0)
    {
        std::cout << "Users Saved Successfully" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error: Save Users Unsuccessful" << std::endl;
        return 1;
    }
}

int cliUtilities::initiateLoadUserDataFromFile(UserRepository &uRep, std::string &usersSaveFileName)
{
    if (uRep.loadUserDataFromFile(usersSaveFileName) == 0)
    {
        std::cout << "User Data Loaded Successfully" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error: Load Users Unsuccessful" << std::endl;
        return 1;
    }
}

int cliUtilities::initiateSaveCustomersToFile(CustomerRepository &cRep, std::string &customersSaveFileName, ValidationUtilities &vU)
{
    char response;

    std::cout << "Current Customer Data Filename: " << customersSaveFileName << "\n";
    std::cout << "Would you like to change the filename for customer data? [y/n] \n";
    std::cout << "Choose Option: ";
    std::cin >> response;

    while (response != 'y' && response != 'n')
    {
        std::cout << "Input invalid. Please enter y or n: ";
        std::cin >> response;
    }

    std::cin.ignore();

    if (response == 'y')
    {
        std::cout << std::endl;
        std::cout << "Enter a New Filename: ";
        std::getline(std::cin >> std::ws, customersSaveFileName);

        while (!(vU.validFileName(usersSaveFileName)))
        {
            std::cout << "Input invalid. Please enter a filename. Include .csv: ";
            std::getline(std::cin >> std::ws, customersSaveFileName);
        }
    }

    if (cRep.saveCustomersToFile(customersSaveFileName) == 0)
    {
        std::cout << "Customer Data Saved Successfully" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error: Save Customers Unsuccessful" << std::endl;
        return 1;
    }
}

int cliUtilities::initiateLoadCustomerDataFromFile(CustomerRepository &cRep, std::string &customersSaveFileName)
{
    if (cRep.loadCustomerDataFromFile(customersSaveFileName) == 0)
    {
        std::cout << "Customer Data Loaded Successfully" << std::endl;
        return 0;
    }
    else
    {
        std::cerr << "Error: Load Customers Unsucceessful" << std::endl;
        return 1;
    }
}