#pragma once

#include <vector>
#include <string>

enum class UserRole
{
    Standard,
    Admin,
};

class User
{
private:
    int user_id;
    std::string first;
    std::string last;
    std::string email;
    std::string passwordHash;
    std::string department;
    UserRole role;

public:
    // Class Constructor
    User(
        int initUserID,
        const std::string &initFirst,
        const std::string &initLast,
        const std::string &initEmail,
        const std::string &initPasswordHash,
        const std::string &initDepartment,
        UserRole initRole);

    // Getters
    int getID() const
    {
        return user_id;
    }
    std::string getFirstName() const
    {
        return first;
    }
    std::string getLastName() const
    {
        return last;
    }
    std::string getEmail() const
    {
        return email;
    }
    std::string getPasswordHash() const
    {
        return passwordHash;
    }
    std::string getDepartment() const
    {
        return department;
    }
    UserRole getAdminStatus() const
    {
        return role;
    }

    // Setters
    void updateName(const std::string &newFirst, const std::string &newLast)
    {
        first = newFirst;
        last = newLast;
    }
    void updateEmail(const std::string &newEmail)
    {
        email = newEmail;
    }
    void updatePasswordHash(const std::string &newPasswordHash)
    {
        passwordHash = newPasswordHash;
    }
    void updateDepartment(const std::string &newDepartment)
    {
        department = newDepartment;
    }
    void updateAdminStatus()
    {
        if (role == UserRole::Standard)
        {
            role = UserRole::Admin;
            return;
        }

        role = UserRole::Standard;
    }
};
