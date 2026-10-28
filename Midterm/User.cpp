#include "User.h"

User::User(
    int initUserID,
    const std::string &initFirst,
    const std::string &initLast,
    const std::string &initEmail,
    const std::string &initPasswordHash,
    const std::string &initDepartment,
    UserRole initRole) : user_id(initUserID),
                         first(initFirst),
                         last(initLast),
                         email(initEmail),
                         passwordHash(initPasswordHash),
                         department(initDepartment),
                         role(initRole) {}