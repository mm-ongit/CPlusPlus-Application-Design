#include "UserRepository.h"
#include "User.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void UserRepository::addUser(
    const std::string &initFirst,
    const std::string &initLast,
    const std::string &initEmail,
    const std::string &initPasswordHash,
    const std::string &initDepartment,
    UserRole initRole)
{
    User newUser(
        next_user_id,
        initFirst,
        initLast,
        initEmail,
        initPasswordHash,
        initDepartment,
        initRole);

    users.push_back(newUser);
    next_user_id += 1;
};

// Getters
const std::vector<User> &UserRepository::getUsers() const
{
    return users;
}

// Setters
// void UserRepository::updateUser() {};
// void UserRepository::removeUser() {};

// Searchers
User *UserRepository::findUserByID(int target)
{
    // Binary Search
    int low = 0;
    int high = static_cast<int>(users.size()) - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (users[middle].getID() == target)
        {
            return &users[middle];
        }
        else if (users[middle].getID() < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return nullptr;
}

User *UserRepository::findUserByEmail(std::string &email)
{
    for (User &user : users)
    {
        if (user.getEmail() == email)
        {
            return &user;
        }
    }

    return nullptr;
}

// Functions
int UserRepository::saveUsersToFile(const std::string &usersSaveFileName) const
{
    // open or create file
    std::ofstream file(usersSaveFileName);

    // check if file is open successfully
    if (!file.is_open())
    {
        std::cerr << "Could Not Open or Create Users Save File" << std::endl;
        return 1;
    }

    // write header row
    // "\n" end line break signals start of new row
    file << "user_id,first,last,email,passwordHash,department,role\n";

    // write data rows with a loop
    for (const User &user : users)
    {
        file << user.getID() << ","
             << user.getFirstName() << ","
             << user.getLastName() << ","
             << user.getEmail() << ","
             << user.getPasswordHash() << ","
             << user.getDepartment() << ",";

        if (user.getAdminStatus() == UserRole::Admin)
        {
            file << "Admin";
        }
        else
        {
            file << "Standard";
        }

        file << "\n";
    }

    // close the file
    file.close();
    return 0;
}

int UserRepository::loadUserDataFromFile(const std::string &usersSaveFileName)
{
    // Open CSV
    std::ifstream file(usersSaveFileName);

    // Check if file opened successfully - error if not
    if (!file.is_open())
    {
        std::cerr << "Error: Load User Data Unsuccessful" << std::endl;
        return 1;
    }

    // Create a string to hold data from each row of dataset
    std::string line;

    // Initialize a counter to iterate dataset
    // std::size_t is unsigned int type, can represent size/non-negative index of any object, always 0 or greater
    // Choose over int to avoid comparison of signed and unsigned values when iterating
    std::size_t count = 0;

    // Read the file line by line
    // Note: When getline() succeeds it evaluates to true, can be used as boolean flag in loop
    while (std::getline(file, line))
    {
        // Skip header row in csv
        if (count == 0)
        {
            ++count;
            continue;
        }

        // Create a string stream object to hold data in each line
        // Note: getline() can only act on stream objects, so stream object containing contents of string line is created with ss()
        std::stringstream ss(line);
        // Create a variable called cell to hold individual data points
        std::string cell;
        // Create a list called row to hold data in cells
        std::vector<std::string> row;

        // Split the string stream object by commas, save result in cell
        while (std::getline(ss, cell, ','))
        {
            // Append data in each cell to row
            row.push_back(cell);
        }

        // Check if row has data for all 7 params
        if (row.size() < 7)
        {
            continue;
        }

        // Create placeholder for User ID (because IDs are int not strings)
        // Convert text ID to appropriate int object
        int user_id = std::stoi(row[0]);

        // next_user_id only exists when program is in use
        // Ensures next_user_id tracks most recently used ID# and increments new IDs from there
        if (user_id >= next_user_id)
        {
            next_user_id = user_id + 1;
        }

        // Create placeholder for role (because User roles are enum objects, not strings)
        UserRole role;

        // Convert text role to appropriate UserRole object
        // If index does not contain "Admin" or "Standard" skip row altogether
        if (row[6] == "Admin")
        {
            role = UserRole::Admin;
        }
        else if (row[6] == "Standard")
        {
            role = UserRole::Standard;
        }
        else
        {
            continue;
        }

        // Construct new User object
        User userFromFile(
            user_id,
            row[1],
            row[2],
            row[3],
            row[4],
            row[5],
            role);
        // Add new User object to users
        users.push_back(userFromFile);

        ++count;
    }

    return 0;
}