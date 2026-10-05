#pragma once

#include <string>

class Interaction
{
private:
    std::string type;
    std::string date;
    std::string notes;

public:
    Interaction(
        const std::string &initType,
        const std::string &initDate,
        const std::string &initNotes);

    // Getters
    std::string getNotes() const
    {
        return notes;
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
    void updateNotes(std::string newNotes)
    {
        notes = newNotes;
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