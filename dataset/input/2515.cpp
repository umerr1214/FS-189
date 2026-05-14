#include <iostream>
#include <string>
#include <vector>

class User {
private:
    std::string username;
    std::string password;
    int userID;
    static int nextUserID;

public:
    // Constructor: Lacks input validation for username/password length or content.
    // This allows creating users with empty or very short credentials,
    // which is a robustness issue in a real application, as such users might be
    // considered invalid from a business logic perspective.
    User(const std::string& uname, const std::string& pwd)
        : username(uname), password(pwd) {
        userID = nextUserID++;
        std::cout << "User " << username << " created with ID: " << userID << std::endl;
    }

    std::string getUsername() const {
        return username;
    }

    int getUserID() const {
        return userID;
    }
};

// Initialize static member
int User::nextUserID = 1001; // Start IDs from 1001

// Driver code
int main() {
    // Test case 1: Normal user creation
    User user1("alice", "securepassword123");
    std::cout << "User1 - Username: " << user1.getUsername() << ", ID: " << user1.getUserID() << std::endl;

    // Test case 2: Another normal user
    User user2("bob", "another_pass");
    std::cout << "User2 - Username: " << user2.getUsername() << ", ID: " << user2.getUserID() << std::endl;

    // Test case 3: Robustness Issue - Creating a user with an empty username and password.
    // The class allows this without any checks, which might be undesirable in a robust system.
    User user3("", "");
    std::cout << "User3 - Username: '" << user3.getUsername() << "', ID: " << user3.getUserID() << std::endl;

    // Test case 4: User with very short username/password
    User user4("x", "y");
    std::cout << "User4 - Username: '" << user4.getUsername() << "', ID: " << user4.getUserID() << std::endl;

    return 0;
}