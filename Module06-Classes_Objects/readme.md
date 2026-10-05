Week 6 Assignment

"Create a class that represents something in your application. Examples include Student, Customer, Product, GameCharacter, Appointment, Book, or Employee. Your class must contain private data members, a constructor, at least two member functions, and at least one getter or setter. Create at least two objects from your class and display their information."

---------------------------

1. Create a Class:
This week I want to highlight my Customer class. 
It owns 11 private data members describing customer info as well as 2 private vectors that serve as lists of transactions and interactions.

I provides a custom constructor that passes data by reference instead of value and uses an initialization list in order to reduce object duplication and improve memory efficiency.

It provides 8 getters to retrieve customer info data for display or manipulation

It provides 6 setters to update customer info data

It provides 5 methods. 2 to activate or deactivate a customer, 1 to calculate lifetime customer value, and 2 to append a new interaction or transaction to a customer's list


This week I wrote Interaction.h and Interaction.cpp to support an Interaction class, based on the Transaction class I wrote last week. I updated my Customer class to include a vector named interactions and added a method to add new interactions to the vector. Additionally I updated the CLI Utilities class to apply the same logic used to generate new transactions to creating new interactions, and fixed a bug that occurred when receiving user input. Last, I added a new menu option for the interactions feature to the menu created by main.cpp.

I haven't quite decided how I intend users of the software to use/access the interaction notes feature, so interactions can be created but they can't be displayed yet

2. Create 2+ Objects, Display their Information:
When you run main, enter the following dummy data using menu option 2:

(Maryanne, Wilton, TypeStrong, Maryanne@typestrong.com, 454 King st., St. Louis, MO, malik@charmcrm.com);
(Omar, Reyes, Filmon Corp, Omar@filcorp.com, 1 Root ave., Raligh, NC, malik@charmcrm.com)

Then use menu option 2 and the expected output is the following:

Customer ID: 1
Customer Name: Maryanne Wilton
Customer Organization: TypeStrong
Customer Email: Maryanne@typestrong.com
Customer Location: 454 King ct. St. Louis,MO
Customer Representative: malik@charmcrm.com
Is Active Customer: 1
Liftime Customer Value: $0

Customer ID: 2
Customer Name: Omar Reyes
Customer Organization: Filmon Corp
Customer Email: Omar@filcorp.com
Customer Location: 1 Root ave. Raligh,NC
Customer Representative: malik@charmcrm.com
Is Active Customer: 1
Liftime Customer Value: $0

