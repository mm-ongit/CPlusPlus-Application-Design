#include "UserRepository.h"
#include "User.h"
#include <iostream>

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