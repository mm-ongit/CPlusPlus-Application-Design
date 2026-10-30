#include "CLIUtilities.h"
#include "Transaction.h"
#include "Interaction.h"
#include <sstream>
#include <cstdlib>

void cliUtilities::start()
{
    CustomerRepository cRep;
    UserRepository uRep;

    if (initiateLoadUserDataFromFile(uRep, usersSaveFileName) == 0 && initiateLoadCustomerDataFromFile(cRep, customersSaveFileName) == 0 && getInitializeProgramFlag())
    {
        displayLogInMenu(cRep, uRep);
    }
    else
    {
        if (getInitializeProgramFlag())
        {
            displayInitializationMenu(cRep, uRep);
        }
        else
        {
            std::cerr << "Error: Loading Data Unsuccessful" << std::endl;
            std::exit(EXIT_FAILURE);
        }
    }
}

void cliUtilities::displayInitializationMenu(CustomerRepository &cRep, UserRepository &uRep)
{
    int choice;

    std::cout << "\n ;) CHARM CRM - Initialization (1/2) <3" << std::endl;
    std::cout << "Welcome to Charm CRM" << std::endl;
    std::cout << "Enter 1 To Create An Admin User" << std::endl;
    std::cout << "Enter Any Other Number To Exit" << std::endl;
    std::cout << "Choose An Option: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
        createUserFromInput(uRep);
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
    std::cin >> choice;
    std::cin.ignore();

    switch (choice)
    {
    case 1:
        createUserFromInput(uRep);
        break;
    default:
        std::cout << "Thanks for using CHARM!" << std::endl;
        return;
    }

    updateInitializeProgramFlag();
    displayLogInMenu(cRep, uRep);
}

// Note: passwordHash is saved as plaintext password while construction is ongoing, will change to real hash later
int cliUtilities::displayLogInMenu(CustomerRepository &cRep, UserRepository &uRep)
{
    std::string log_in_flag;
    std::string email;
    std::string password;

    while (true)
    {
        std::cout << "\n ;) CHARM CRM - Login (1/3) <3" << std::endl;
        std::cout << "Enter 1 To Log In " << std::endl;
        std::cout << "Enter 2 To Exit " << std::endl;
        std::cout << "Choose Option: ";
        std::cin >> log_in_flag;
        std::cin.ignore();

        if (log_in_flag != "1" && log_in_flag != "2")
        {
            std::cout << std::endl;
            std::cout << "Please Enter 1 Or 2" << std::endl;
            displayLogInMenu(cRep, uRep);
        }

        if (log_in_flag == "2")
        {
            std::cout << "Thanks for using CHARM!" << std::endl;
            break;
        }

        std::cout << "\n ;) CHARM CRM - Login (2/3) <3" << std::endl;
        std::cout << "Enter Email: ";
        std::cin >> email;
        std::cin.ignore();

        std::cout << "\n ;) CHARM CRM - Login (3/3) <3" << std::endl;
        std::cout << "Enter Password: ";
        std::cin >> password;
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
                displayAdminMenu(cRep, uRep);
            }
            else
            {
                displayStandardMenu(cRep, uRep);
            }
        }
        else
        {
            std::cout << "Password Does Not Match Record";
        }
    }

    return 0;
}

int cliUtilities::displayStandardMenu(CustomerRepository &cRep, UserRepository &uRep)
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
        std::cin >> choice;
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
            std::cout << "Invalid choice. Please select option 1 - 6." << std::endl;
        }
    }

    return 0;
}

int cliUtilities::displayAdminMenu(CustomerRepository &cRep, UserRepository &uRep)
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
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            createCustomerFromInput(cRep);
            break;
        case 2:
            createUserFromInput(uRep);
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
            initiateTransactionFromInput(cRep);
            break;
        case 8:
            initiateInteractionFromInput(cRep);
            break;
        case 9:
            initiateSaveUsersToFile(uRep, usersSaveFileName);
            initiateSaveCustomersToFile(cRep, customersSaveFileName);
            std::cout << "Thanks for using CHARM!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please select option 1 - 10." << std::endl;
        }
    }

    return 0;
}

void cliUtilities::createCustomerFromInput(CustomerRepository &cRep)
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
void cliUtilities::createUserFromInput(UserRepository &uRep)
{
    std::string initFirst;
    std::string initLast;
    std::string initEmail;
    std::string initPasswordHash = "";
    std::string initDepartment;
    UserRole initRole;
    std::string initPassword = "";
    std::string initAccessLevel = "";

    std::cout << "First name: ";
    std::getline(std::cin, initFirst);

    std::cout << "Last name: ";
    std::getline(std::cin, initLast);

    std::cout << "Email: ";
    std::getline(std::cin, initEmail);

    // Loop to validate Password
    while (initPassword == "")
    {
        std::cout << "Password: ";
        std::getline(std::cin, initPassword);

        // Add password hasher here
        initPasswordHash = initPassword; // change initPassword to password_hasher(initPassword)

        break;
    }

    std::cout << "Depatment: ";
    std::getline(std::cin, initDepartment);

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

    std::cout << "Enter Customer ID: ";
    std::cin >> target;

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
    std::cin >> target;

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
void cliUtilities::initiateTransactionFromInput(CustomerRepository &cRep)
{
    int target;

    std::cout << "Enter customer ID: ";
    std::cin >> target;

    Customer *customer = cRep.findCustomerByID(target);

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
void cliUtilities::initiateInteractionFromInput(CustomerRepository &cRep)
{
    int target;

    std::cout << "Enter customer ID: ";
    std::cin >> target;

    Customer *customer = cRep.findCustomerByID(target);

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

int cliUtilities::initiateSaveUsersToFile(UserRepository &uRep, std::string &usersSaveFileName)
{
    std::string response;

    std::cout << "Would You Like to Change The Filename [y/n]? \n";
    std::cout << "Choose Option: ";
    std::getline(std::cin >> std::ws, response);

    if (response == "y")
    {
        std::cout << std::endl;
        std::cout << "Enter a New Filename: ";
        std::getline(std::cin >> std::ws, usersSaveFileName);
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
        std::cerr << "Error: Load Users Unsucceessful" << std::endl;
        return 1;
    }
}

int cliUtilities::initiateSaveCustomersToFile(CustomerRepository &cRep, std::string &customersSaveFileName)
{
    std::string response;

    std::cout << "Would You Like to Change The Filename [y/n]? \n";
    std::cout << "Choose Option: ";
    std::getline(std::cin >> std::ws, response);

    if (response == "y")
    {
        std::cout << std::endl;
        std::cout << "Enter a New Filename: ";
        std::getline(std::cin >> std::ws, usersSaveFileName);
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