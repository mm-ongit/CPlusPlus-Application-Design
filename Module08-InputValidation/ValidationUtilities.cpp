#include "ValidationUtilities.h"

// Data Type Checks
bool ValidationUtilities::validString(const std::string &input)
{
    std::istringstream iss(input);
    int check;

    // If stream can NOT be inserted into int input is valid
    if (iss >> check)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool ValidationUtilities::validInt(const std::string &input)
{
    std::istringstream iss(input);
    int check;

    // If stream CAN be inserted into int input is valid
    if (iss >> check)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidationUtilities::validDouble(const std::string &input)
{
    std::istringstream iss(input);
    double check;

    // If stream CAN be inserted into double the input is valid
    if (iss >> check)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Data Formatting Checks
bool ValidationUtilities::validName(std::string_view input)
{
    /*
    Accepts:
    Ashanti
    Michael Henry
    Naih'ah
    bell
    El-Sayed

    Rejects:
    El_Sayed
    0Ashanti
    <Michael Henry>
    /Naih'ah
    b
    */

    if (input.length() < 2)
    {
        return false;
    }

    const std::string_view forbiddenCharacters = R"(\\\"<>[]{}()/`~;:!@#$^&*.?=+_|0123456789)";

    for (char c : input)
    {
        if (forbiddenCharacters.find(c) != std::string_view::npos)
        {
            return false; // This means the name contains a forbidden character
        }
    }

    return true;
}

bool ValidationUtilities::validEmail(const std::string &input)
{
    /*
    Accepts:
    testname@test.com
    test_name@test.com
    test.name@test.com
    test1name@test.com
    testname@test.co.uk
    TestName@Test.com
    TestName@Test.co.uk

    Rejects:
    TESTNAME@TEST.COM
    {testname}@test.com
    <testname>@test.com
    testname@test.c
    testname
    testname@test
    */
    std::regex pattern(R"([a-zA-Z0-9._-]+@[a-zA-Z]+\.[a-z]{2,}(?:\.?[a-z]{2,})*)");

    if (std::regex_match(input, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidationUtilities::validPassword(std::string_view input)
{
    /*
    Accepts:
    Password1!

    Rejects:
    123456789
    abcdefghi
    ABCDEFGHI
    !@#$&*
    {Password1!}
    <Password>
    [text]
    (text)
    password1!
    password1
    password
    pass
    p
    */

    if (input.length() < 8)
    {
        return false;
    }

    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;

    const std::string_view forbiddenCharacters = R"(\\\"'<>[]{}()/`~;:+=)";
    const std::string_view allowedCharacters = R"(!@#$^&*.?_-|)";

    // checks each character in password string against 5 conditions; all flags must be true by end of string to pass check
    for (char c : input)
    {
        if (forbiddenCharacters.find(c) != std::string_view::npos)
        {
            return false; // This means the password contains a forbidden character
        }

        if (std::islower(static_cast<unsigned char>(c)))
        {
            has_lower = true; // at least one character is lowercase a-z
        }
        else if (std::isupper(static_cast<unsigned char>(c)))
        {
            has_upper = true; // at least one charactter is uppercase A-Z
        }
        else if (std::isdigit(static_cast<unsigned char>(c))) // chars evaluate to digits
        {
            has_digit = true; // at least one character is a digit 0-9
        }
        else if (allowedCharacters.find(c) != std::string::npos)
        {
            has_special = true; // at least one character is a special character !@#$^&*.?|
        }
    }

    return has_lower && has_upper && has_digit && has_digit && has_special; // if any are false the password fails the check
}

// Needs Strengthening + Clarity about what input you expect
bool ValidationUtilities::validAddress(std::string_view input)
{
    /*
    Accepts:
    123 Oak st.
    12 B ave. bldg #10
    4958 Lark ct. apt 4
    739 Luka Weiss pl.
    233 Bartz-Cline st.

    Rejects:
    B st.


    */

    // address must be at least 7 characters e.g. "9 B st."
    if (input.size() < 7)
    {
        return false;
    }

    bool has_lower = false;
    bool has_upper = false;
    bool has_digit = false;
    bool has_special = false;

    const std::string_view forbiddenCharacters = R"(\\\"<>[]{}()/`~;:+=!@$%^&*?_|)";
    const std::string_view allowedCharacters = R"( #.'-)";

    // checks each character in address string against 5 conditions; all flags must be true by end of string to pass check
    for (char c : input)
    {
        if (forbiddenCharacters.find(c) != std::string_view::npos)
        {
            return false; // This means the password contains a forbidden character
        }

        if (std::islower(static_cast<unsigned char>(c)))
        {
            has_lower = true; // at least one character is lowercase a-z
        }
        else if (std::isupper(static_cast<unsigned char>(c)))
        {
            has_upper = true; // at least one charactter is uppercase A-Z
        }
        else if (std::isdigit(static_cast<unsigned char>(c))) // chars evaluate to digits
        {
            has_digit = true; // at least one character is a digit 0-9
        }
        else if (allowedCharacters.find(c) != std::string::npos)
        {
            has_special = true; // at least one character is a special character !@#$^&*.?|
        }
    }

    return has_lower && has_upper && has_digit && has_digit && has_special; // if any are false the address fails the check
}

bool ValidationUtilities::validCity(const std::string &input)
{
    /*
    Accepts:
    New York
    Martha's Vineyard
    St. Paul

    Rejects:
    New_York
    Martha"s Vineyard
    <St. Paul>
    */

    if (input.length() < 2)
    {
        return false;
    }

    const std::string_view forbiddenCharacters = R"(\\\"<>[]{}()/`~;:!@#$^&*?=+_|0123456789)";

    for (char c : input)
    {
        if (forbiddenCharacters.find(c) != std::string_view::npos)
        {
            return false; // This means the name contains a forbidden character
        }
    }

    return true;
}

bool ValidationUtilities::validState(const std::string &input)
{
    /*
    Accepts:
    AZ
    CT
    NV


    Rejects:
    az
    ct
    nv
    p
    1
    ?
    >
    AZX
    */

    // must be 2 characters long
    if (input.length() != 2)
    {
        return false;
    }

    // both characters must be capital letters
    if (!(std::isupper(static_cast<unsigned char>(input[0])) && std::isupper(static_cast<unsigned char>(input[1]))))
    {
        std::cout << "One or more characters are not capitalized";
        return false;
    }
    else
    {
        return true;
    }
}

bool ValidationUtilities::validDate(const std::string &input)
{
    /*
    Expects:
    MM/DD/YYYY

    Accepts:
    12/25/2026
    02/14/2038
    04/33/1992 (add more logic to prevent)

    Rejects:
    31/04/1992 (month too high)
    05/43/1976 (day too high)
    10/13/3008 (year too high)
    1992-04-22 (YYYY-MM-DD)
    */

    std::regex pattern(R"(([0-1]){1}([0-2]{1})/([0-3]){1}([0-9]{1})/([1-2]){1}([0-9]{3}))");

    if (std::regex_match(input, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidationUtilities::validPhoneNumber(std::string_view input)
{
    /*
    Accepts:
    5557643327

    Rejects:
    2223334
    */

    // tolerates phone numbers up to 15 digits long to accomodate international numbers
    if (input.length() < 10 | input.length() > 15)
    {
        return false;
    }

    for (char c : input)
    {
        if (!(std::isdigit(c)))
        {
            return false;
        }
    }

    return true;
}

bool ValidationUtilities::validFileName(const std::string &input)
{
    /*
    Accepts:
    test.csv
    test-data.csv
    test_data.csv
    users.csv
    customers.csv
    a.csv

    Rejects:
    test.pdf
    test.docx
    test.txt
    .csv
    */

    if (input.length() < 5)
    {
        return false;
    }

    std::regex pattern(R"([a-zA-Z0-9_\-]+\.{1}csv)");

    if (std::regex_match(input, pattern))
    {
        return true;
    }
    else
    {
        return false;
    }
}