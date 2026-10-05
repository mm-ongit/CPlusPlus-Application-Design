Week 5's assignment was to "Create functions to add a record, display records, and calculate a simple result. Move at least one function declaration into your own .h header file and implement it in a .cpp file."

1) Add a record:
I'm building a Customer Relationship Management tool, the core object of which is the customer. To keep a record of customers the program must have a definition for customer, so I started with a Customer class in Customer.h/Customer.cpp.
Customer privately owns standard contact info parameters and publicly provides getters and setters for each of them, plus it defines a constructor that passes initial values by reference to save on memory overhead. I want Customer objects to have unique IDs and lifetime customer value but I don't have that figured out yet.

2) Display records:
Each Customer object knows only of itself, so in order to display all customer records I needed a way to collect and manipulate customer records.
To satisfy that need I created a CustomerRepository class (CustomerRepository.h/CustomerRepository.cpp) to manage Customer objects. It privately owns a vector of type Customer where customers are stored, with a public getter to return that list by reference and a funtion to create new customers and them to that list.
Creating new customers requires user input, which required an additional class to manage I/O in CLI (CLIUtilities.h/CLIUtilities.cpp). It gathers, stores, and passes the values required to create a new Customer object. Customer objects themselves are not iterable so I loop through the list of customers and access their info parameter values with the appropriate getter and print them to the screen with each pass.

3) Side Quest 1: Procedurally generated Customer IDs
At this point my Customer constructor initialized Customer ID to 0. To prevent users manually entering IDs I needed a way to procedurally generate customer ID#s. I went back to the CustomerRepository class and added a private counter for Customer IDs and added a line to increment that counter each time a new Customer object is successfully created and added to repository's list of customers. I updated my Customer constructor in Customer.h and Customer.cpp to reflect this change as well.


4) Calculate a simple result:
I am now required to figure out how to implement the calculation of lifetime customer value. In order to represent value I needed to represent Transaction objects with another class (Transaction.h/Transaction.cpp). It privately owns a transaction amount and transaction type and public offers a simple constructor and getters for both parameters
Next, I added a private vector of transactions to Customer.h and a public method to append transactions to that list.
This took me back to CLIUtilities because I needed a way to get user input to create new transactions. With that in place, I also needed a way to select the customer with which to associate the transaction. I implemented search by ID in CustomerRepository.cpp using linear search (it works well now but does not scale well. will update later). 
Now that I can select customers by ID I can assign transactions to customers and they can derive lifetime customer value.
I added a line to display this derived value when Customer info is displayed.
I copied the application menu created in week 2 to a new main.cpp file and updated it to reflect my application's current features.

Each .h file has at least one function implmented in a complementary .cpp file.

5) Results:
Many errors later it works!
(I need to move the menu logic into CLIUtilities) 

The application menu offers the following options:
1. Create Customer Record
2. View Customer Records
3. Create New Transaction
4. Exit

First, I choose option 1 twice and create 2 customers with the following data:

(Becky, Bright, BrightCo., becky@brightco.com, 2223334444, Cooltown, CA, 222 Cool st., malik@charmcrm.com);
(Andy, Allen, AllenCo., allen@allenco.com, 4445556666, Hottown, CA, 345 Heat st., malik@charmcrm.com)

Then I choose option 3 twice, specifying the Customer with the ID# 1 and creating new transactions:
(450, Consulting Fee);
(700, Consulting Fee)

I do the same for the second Customer:
(18000, Contract);
(2400, Consulting Fee)

Now I can choose option 2 from the menu and display all of the data I have on each Customer, providing the following output:

Customer ID: 1
Customer Name: Becky Bright
Customer Organization: BrightCo.
Customer Email: becky@brightco.com
Customer Location: 222 Cool st. Cooltown,CA
Customer Representative: malik@charmcrm.com
Is Active Customer: 1
Liftime Customer Value: $1150

Customer ID: 2
Customer Name: Andy Allen
Customer Organization: AllenCo.
Customer Email: andy@allenco.com
Customer Location: 345 Heat st. Hottown,CA
Customer Representative: malik@charmcrm.com
Is Active Customer: 1
Liftime Customer Value: $20400
