#pragma once

#include <vector>
#include <string>
#include "User.h"

class UserRepository
{
private:
    std::vector<User> users;
    int next_user_id = 1;

public:
    void addUser(
        const std::string &initFirst,
        const std::string &initLast,
        const std::string &initEmail,
        const std::string &initPasswordHash,
        const std::string &initDepartment,
        UserRole initRole);

    // Getters
    const std::vector<User> &getUsers() const;

    // Setters
    // void updateUser();
    // void removeUser();

    // Searchers
    User *findUserByID(int target);
    User *findUserByEmail(std::string &email);

    // User *findUserByName(std::string target)
};