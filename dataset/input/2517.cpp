#include <iostream>
#include <string>
#include <vector> // Included for common C++ library usage, though not strictly used by User class

class User {
private:
    std::string username;
    std::string password;
    int userID;
    static int nextUserID; // Static member for unique ID generation

public:
    // Constructor: Takes const std::string& to avoid unnecessary copies.
    // Uses initializer list for efficient member initialization.
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd), userID(nextUserID++) {
        // Constructor's primary job is to initialize, not to print.
    }

    // Public getter for username: Returns const std::string& to avoid copies
    // and ensures the method does not modify the object state (const).
    std::string const& getUsername() const {
        return username;
    }

    // Public getter for userID: Returns int by value (efficient for primitive types)
    // and ensures the method does not modify the object state (const).
    int getUserID() const {
        return userID;
    }
};

// Initialize the static member counter outside the class definition
int User::nextUserID = 1; // Start User IDs from 1

// Driver code to demonstrate functionality
int main() {
    std::cout << "--- Creating and Displaying User Information ---" << '\n';

    // Create User objects
    User user1("alice_smith", "pass123");
    User user2("bob_johnson", "secure_pwd");
    User user3("charlie_brown", "mysecret");
    User user4("diana_prince", "wonderwoman");

    // Display user information using getters
    std::cout << "User 1 -> Username: " << user1.getUsername() << ", ID: " << user1.getUserID() << '\n';
    std::cout << "User 2 -> Username: " << user2.getUsername() << ", ID: " << user2.getUserID() << '\n';
    std::cout << "User 3 -> Username: " << user3.getUsername() << ", ID: " << user3.getUserID() << '\n';
    std::cout << "User 4 -> Username: " << user4.getUsername() << ", ID: " << user4.getUserID() << '\n';

    // Demonstrate that IDs are unique and incrementing
    User user5("eve_adams", "final_pass");
    std::cout << "User 5 -> Username: " << user5.getUsername() << ", ID: " << user5.getUserID() << '\n';

    std::cout << "--- All Users Processed ---" << '\n';

    return 0;
}