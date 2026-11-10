#pragma once

#include <string>
#include <string_view>
#include <sstream>
#include <cctype> // isupper, islower, etc.
#include <regex>
#include <iostream>

class ValidationUtilities
{
public:
    // Methods

    // Data Type Checks
    bool validString(const std::string &input); // done

    bool validInt(const std::string &input); // done

    bool validDouble(const std::string &input); // done

    // Data Formatting Checks
    bool validName(std::string_view input); // done

    bool validEmail(const std::string &input); // done

    bool validPassword(std::string_view input); // done

    bool validAddress(std::string_view input); // done

    bool validCity(const std::string &input); // done

    bool validState(const std::string &input); // done

    bool validDate(const std::string &input); // done

    bool validPhoneNumber(std::string_view input); // done

    bool validFileName(const std::string &input); // to do
};