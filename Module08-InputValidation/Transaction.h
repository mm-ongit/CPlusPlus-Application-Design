#pragma once

#include <string>

class Transaction
{
private:
    std::string type;
    std::string date;
    double amount;

public:
    Transaction(
        const std::string &initType,
        const std::string &initDate,
        const double initAmount);

    // Getters
    double getAmount() const
    {
        return amount;
    }

    std::string getType() const
    {
        return type;
    }

    std::string getDate() const
    {
        return date;
    }

    // Setters
    void updateAmount(double newAmount)
    {
        amount = newAmount;
    }

    void updateType(std::string newType)
    {
        type = newType;
    }

    void updateDate(std::string newDate)
    {
        date = newDate;
    }
};