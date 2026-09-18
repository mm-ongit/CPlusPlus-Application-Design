#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    // 1. Open the CSV file - creates an input-file-stream object to read in .csv
    std::ifstream file("penguins.csv");

    // 2. Check if the file opened successfully - error message if fail
    if (!file.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    // Notify user of successful data access
    std::cout << "\n"
              << "File opened successfully!" << "\n"
              << "\n";

    // Create a variable called line to contain data from each row of dataset
    std::string line;

    // Initialize a counter to iterate dataset
    // std::size_t creates object of unsigned int type, can represent size/non-negative index of any object, always positive
    // Choose over int to avoid comparison of signed and unsigned values when iterating
    std::size_t count = 0;

    // Create a vector specifically for storing data of first row of penguin records
    std::vector<std::string> firstPenguinData;

    // 3. Read the file line by line - limited to first 10 records (skipping headers)
    // Note: Whe getline() succeeds it evaluates to true, can be used as boolean flag in loop
    while (std::getline(file, line) && count < 11)
    {
        // Skip header row in csv
        if (count == 0)
        {
            ++count;
            continue;
        }

        // Create a string stream object to hold data in each line
        // Note: getline() can only act on stream objects, so string line must be converted to stream with ss()
        std::stringstream ss(line);
        // Create a variable called cell to hold individual data points
        std::string cell;
        // Create a list called row to hold data in cells
        std::vector<std::string> row;

        // 4. Split the string stream object by commas, save result in cell
        while (std::getline(ss, cell, ','))
        {
            // Append data in each cell to row
            row.push_back(cell);
        }

        // 5. Print every cell in this row
        // & allows direct reference to value, no copying of data occurs, const promises read-only access
        for (const auto &val : row)
        {
            std::cout << val << " | ";
        }

        std::cout << '\n';

        // Copy data from first row into a vector
        if (count == 1)
        {
            firstPenguinData = row;
        }

        ++count;
    }

    // 6. Create pointer and print value to the screen
    // If makees sure the 7th element in list exists before creating pointer
    if (firstPenguinData.size() > 6)
    {
        std::string *bodyMassPointer = &firstPenguinData[6];

        std::cout << "\n"
                  << "Body mass of first penguin via pointer: " << *bodyMassPointer << "g." << "\n";
    }

    // 7. Close the file stream
    file.close();
    return 0;
}