#include <iostream>
#include <string>
#include <vector>

class User {
public: // Semantic error: username should be private according to the question
    std::string username;
private:
    std::string password;
    int userID;
    static int nextUserID;

public:
    User(const std::string& username, const std::string& password) :
        username(username), password(password) {
        userID = nextUserID++;
    }

    std::string getUsername() const {
        return username;
    }

    int getUserID() const {
        return userID;
    }
};

int User::nextUserID = 1; // User IDs start from 1

int main() {
    User user1("alice", "pass123");
    // This direct access compiles and works, demonstrating the semantic error
    std::cout << "User 1 (direct access): Username = " << user1.username << ", ID = " << user1.getUserID() << std::endl;

    User user2("bob", "securepwd");
    std::cout << "User 2 (via getter): Username = " << user2.getUsername() << ", ID = " << user2.getUserID() << std::endl;

    return 0;
}