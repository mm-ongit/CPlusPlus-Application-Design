Week 8 Assignment:

"Add validation to your application. (Prevent invalid entries such as negative values, empty names, or incorrectly formatted dates.) Your program should give the user a useful error message and allow them to try again."
-----------------------------------------------------------------------------------------------------------------------------------------

1. Add Validation to your program
- Due to the design of my program, all user input is ingested by a single class, the CLI Utilities class. Users either enter numbers intended to be of type int or double, or words or characters intended to be strings or chars. 

To keep the responsibilities of ingesting user input and validating user input separate I have created an additional class, ValidationUtilities.h/cpp. The CLI Utilities class calls methods from the ValidationUtilities class to ensure proper user input.

User input is required for the following information: 
Numbers
- Menu navigation - int
- Customer ID Search - int
- User ID Search - int
- Transaction Amount - double

Strings
- User First Name - string - name
- User Last Name - string - name
- User Email - string - email
- User Password - string - password
- User Department - string - name
- User Access Level - string

- Customer First Name - string - name
- Customer Last Name - string - name
- Customer Email - string - email
- Customer Phone Number - string - phone number
- Customer Organization - string - name
- Customer Address - string - address
- Customer City - string - city
- Customer State - string - state
- Customer Representative - string - email

- Transaction Type - string - name (for now)
- Transaction Date - string - date
- Interaction Type - string - name (for now)
- Interaction Date - string - date
- Interaction Notes - string

- User Data Filename - string - filename
- Customer Data Filename - string - filename

Chars
- Rename Save File Response - char


As seen above, I identified the need to write custom functions to validate names (first, last, department, organization), emails, passwords, addresses, cities, states (abbreviations), dates, phone numbers, and filenames. 
Ints and doubles are verified with a simple while loop that checks whether input can be inserted into a predefined int or double variable; if the insertion fails (due to a type mismatch) the failure flag is cleared and the buffer is emptied before the user is prompted for input again. (This prevents cin from ingesting a leftover \n and causing an infinite loop. Ask me how I know...)

For the most part, my validation works as intended, however there are two bugs I have yet to fix.
- Bug 1: The log in menu asks users to enter 1 to log in and 2 to exit. Right now if a user enters 12 the program allows them to proceed to log in, but this should not be allowed
- Bug 2: The program asks if users would like to rename the user data and customer data save files before saving and exiting. I wrote a regex to catch any user input that is not a valid .csv file name. The check works when changing the user data filename, but the exact same check fails when a user renames the customer data filename.

-------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------
Week 9 Assignment:

"Choose one AI-powered feature for your application. Describe what the feature does, what data it would need, what the user would see, and where AI would fit into your current application architecture. Build a mock version or prototype if a live AI service is not available."
-------------------------------------------------------------------------------------------------------------

I would love to implement a feature that would allow users to chat with Charm about contacts. The user asks a questions about a contact, then an LLM will ingest that contact's info, transactions, and interactions to answer the user's question.

For example, let's say you have a new customer named Ken Lithgoe. There are a few interactions and transactions with Ken in Charm and you want to ask Charm about Ken. Charm might say "You met Ken Lithgoe at the Stark Gallery opening last weekend. You chatted about custom saltwater fish tanks and told him you know a guy." Or a user might ask “How many gallons was the fish tank Ken Lithgoe mentioned last weekend?” or “Is Ken Lithgoe’s first name Kenneth or Kendall?” and Charm will tell you (assuming the answers to your questions can be found in Charm's data).

Here's how it might work:

- START
- User asks question about contact -> 
- Charm prepares JSON of contact data -> 
- Charm sends data and user request to LLM -> 
- LLM recceives request and parses contact data -> 
- LLM generates output -> 
- Charm receives LLM response -> 
- Charm displays LLM response for user
- END