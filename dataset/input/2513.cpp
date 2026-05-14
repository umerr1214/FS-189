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
    User(const std::string& username, const std::string& password) :
        username(username), password(password) {
        userID = nextUserID++;
    }

    // Logical error: returns password instead of username
    std::string getUsername() const {
        return password; // Should be 'return username;'
    }

    int getUserID() const {
        return userID;
    }
};

int User::nextUserID = 1; // User IDs start from 1

int main() {
    User user1("alice", "pass123");
    std::cout << "User 1 Username: " << user1.getUsername() << ", ID: " << user1.getUserID() << std::endl;

    User user2("bob", "securepwd");
    std::cout << "User 2 Username: " << user2.getUsername() << ", ID: " << user2.getUserID() << std::endl;

    User user3("charlie", "secret");
    std::cout << "User 3 Username: " << user3.getUsername() << ", ID: " << user3.getUserID() << std::endl;

    return 0;
}