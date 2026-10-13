Week 7 Assignment:

"Create Admin and Regular User roles. Restrict actions based on the user's role. Store records in sorted order and implement a binary search to find a record by ID or another unique field."

-------------------------------
1. Create Admin and Standard User roles:
- Write User.h & Write User.cpp -
Since there is no behavioral difference between regular users and admin users I have decided not to implement two separate classes or a parent and derivative class. User objects have a UserRole attribute which can be defined as 1 or 2 options, UserRole::Standard UserRole::Admin. UserRole's value is checked by the CLI Utility, which determines which menu options are shown to which users. Creation/deletion/update of User objects will be handled by the UserRepository class.


- Write UserRepository.h & Write UserRepository.cpp -
- This class operates the same way as my CustomerRepository class. It owns a vector of Users and an ascending counter to procedurally create sequential ID numbers for new Users. This counter is accessed by the class' logic for creating new Users. The class can also search for Users.

2. Store records in sorted order, implement binary search in findbyID()
- Change linear search to binary search CustomerRepository.cpp 

Instructor Brooks provided the following example of Binary Search:
https://gist.github.com/christophewang/da7e308c627dcc816831


I was already working in UserRepository so I went ahead and implemented binary search there first, then copied that logic into CustomerRepository. Initially, I attempted to pass in a pointer to a vector and a size variable to the search funtion, as in the example, but there's no need to pass a vector as an argument to the search because the class already owns the vector. Additionally, a pointer to a User is not the User object itself which means it parameters/functions cannot be accessed for comparison with the target.

My implementation is as follows:
/*
User *UserRepository::findUserByID(int target)
{
    // Binary Search
    int low = 0;
    int high = static_cast<int>(users.size()) - 1;

    while (low <= high)
    {
        int middle = (low + high) / 2;
        if (users[middle].getID() == target)
        {
            return &users[middle];
        }
        else if (users[middle].getID() < target)
        {
            low = middle + 1;
        }
        else
        {
            high = middle - 1;
        }
    }

    return nullptr;
}
*/


3. Restrict actions based on User's role:
- With the User and UserRepository classes in place I moved to updating the logic within CLIUtilities. Mirroring functions to create, display, and find Customers, I wrote 3 functions to do the same for Users.
    
- Move menu logic to CLIUtilities.cpp -
- I cut and pasted the main menu logic from main.cpp into in a function called displayAdminMenu() in my CLI Utilities class. I added options for creating, viewing and finding Users to the menu. I used this as the base for another function called displayStandardMenu() which dsplays options for read-only functions.

- Write Login/Logout flow in CLIUtilities.cpp -
- Here I had a problem. I needed a log in system in order to make use of the two levels of access, and a Standard User and an Admin User had to be made However, creating new Users is an Admin privilege and shouldn't be available from the log in screen. For the time, my solution is an initialization menu that assumes the program is being set up for the first time by an admin/owner user. It guides the user through the creation of an Admin User and a Stadard User, then the log in menu is displayed. The log in menu checks if input matches records of log in credentials for a User. Right now the program cheats and sets the password hash to an empty string for convenience, but I will find a library to handle hashing/checking in the future. Finally, I wrote start(), which creates the CustomerRepository and UserRepository objects required by the rest of the program and passes them as arguments to either displayInitilizationMenu() or displayLogInMenu() accordingly.


- Update main.cpp
Now, instead of containing what was previously the main menu, main.cpp simply creates a cliUtilities object and calls cli.start()

After compilation I realized I never wrote a way to log out. I added the option to log out to the Standard Menu and Admin Menu. I also added an option to exit the program from the log in menu. Last, I added a flag to my CLI Utility. This is set to false after succcessful creation of Admin and Standard Users objects in displayInitializationMenu() so initialization only happens once.

4. Result:
- The week's goals have been achieved. Binary search is implemented to find Users and Customers by ID number and two levels of access exist.

Admin Users now have access to the following read and write feeatures within the program:
- Initialize Program
- Create New Customer Record
- Create New User Record
- View Customer Records
- View User Records
- Find Customer By ID
- Find User By ID
- Create New Transaction
- Create New Interaction
- Log Out

Standard Users have access to the following read-only features:
- View Customer Records
- View User Records
- Find Customer By ID
- Find User By ID
- Log Out

