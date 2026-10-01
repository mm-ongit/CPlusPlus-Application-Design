#pragma once

#include <string>

class Transaction
{
private:
    double amount;
    std::string type;

public:
    Transaction(
        const double initAmount,
        const std::string &initType);

    double getAmount() const
    {
        return amount;
    }

    std::string getType() const
    {
        return type;
    }
};