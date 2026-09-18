This week's assignment is to find a dataset on Kaggle and use it to learn about arrays and pointers. 

"Choose a small Kaggle dataset. Select 5–10 records and at least 2–3 fields. Represent the data in C++ arrays. Display the records and demonstrate accessing one value through a pointer."

I've chosen the classic "penguins" dataset, which contains physical measurements of various species of penguin.

https://www.kaggle.com/datasets/larsen0966/penguins

After downloading .csv located at the link above and placing in the root for this module I...

1. Use fstream to open the csv.

2. Check to make sure I opened the file successfully.
    If the file is not opened successfully an error message is displayed and the program exits.
    If successful, a variable to contain each line in the csv, a counter, and an empty vector to hold desired data for access via pointer later are created

3. Use a while loop and getline() to read the file line by line. 
    The first line of the .csv is headers so I skip the first iteration.
    Then I create a string stream object out of each line, an empty string to hold substrings of created from each line, and a list to hold collections of substrings.


4. Within above while loop, I split each line at the delimiter 
    and saved the result of each split in an empty string.
    Then I add each of those strings to a list representing each row in the .csv

5. Iterate through each list and print its values to the terminal

6. Create a pointer and assign it the value of the 7th element in an array containing
    the data for the first penguin in the source data.
    And I print the value located at this pointer to the terminal.

Succesful output from the program is as follows:


File opened successfully!

 |  | "Adelie" | "Torgersen" | 39.1 | 18.7 | 181 | 3750 | "male" | 2007
 |  | "Adelie" | "Torgersen" | 39.5 | 17.4 | 186 | 3800 | "female" | 2007
 |  | "Adelie" | "Torgersen" | 40.3 | 18 | 195 | 3250 | "female" | 2007
 |  | "Adelie" | "Torgersen" | NA | NA | NA | NA | NA | 2007
 |  | "Adelie" | "Torgersen" | 36.7 | 19.3 | 193 | 3450 | "female" | 2007
 |  | "Adelie" | "Torgersen" | 39.3 | 20.6 | 190 | 3650 | "male" | 2007
 |  | "Adelie" | "Torgersen" | 38.9 | 17.8 | 181 | 3625 | "female" | 2007
 |  | "Adelie" | "Torgersen" | 39.2 | 19.6 | 195 | 4675 | "male" | 2007
 |  | "Adelie" | "Torgersen" | 34.1 | 18.1 | 193 | 3475 | NA | 2007
 | " | "Adelie" | "Torgersen" | 42 | 20.2 | 190 | 4250 | NA | 2007

Body mass of first penguin via pointer: 3750g.


Now that I have a method for reading data from file I have the basis for data persistence for my CRM project. I will adapt the code I wrote for this week's module accordingly.