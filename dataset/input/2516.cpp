#include <iostream>
#include <string>
#include <vector> // Not strictly needed, but often included

class User {
private:
    std::string the_user_name_string; // Verbose and inconsistent naming
    std::string the_password_string;  // Verbose and inconsistent naming
    int the_user_id_value;            // Verbose and inconsistent naming
    static int static_next_user_id_counter; // Verbose and inconsistent naming

public:
    // Constructor: Takes std::string by value, leading to unnecessary copies.
    // The parameters are copied when passed to the function, and then copied again
    // when assigned to member variables.
    User(std::string p_username, std::string p_password) {
        this->the_user_name_string = p_username; // Another copy here
        this->the_password_string = p_password;   // Another copy here
        this->the_user_id_value = static_next_user_id_counter++;
        // Excessive use of std::endl, which flushes the buffer every time
        std::cout << "New User with long name '" << this->the_user_name_string << "' assigned ID: " << this->the_user_id_value << std::endl << std::endl;
    }

    // Getter for username: Returns std::string by value, causing an unnecessary copy
    // of the string object every time it's called.
    std::string get_the_user_name() const {
        return this->the_user_name_string;
    }

    // Getter for userID: Returns int by value (fine for primitive types), but verbose name.
    int get_the_user_identifier() const {
        return this->the_user_id_value;
    }
};

// Initialize static member with a different starting value
int User::static_next_user_id_counter = 5001;

// Driver code
int main() {
    std::cout << "--- Creating Users ---" << std::endl;
    User user_one("john_doe_username", "super_secret_password");
    std::cout << "Retrieved User One - Name: " << user_one.get_the_user_name() << ", ID: " << user_one.get_the_user_identifier() << std::endl << std::endl;

    User user_two("jane_smith_account", "another_top_secret");
    std::cout << "Retrieved User Two - Name: " << user_two.get_the_user_name() << ", ID: " << user_two.get_the_user_identifier() << std::endl << std::endl;

    User user_three("guest_user", "temp_pass");
    std::cout << "Retrieved User Three - Name: " << user_three.get_the_user_name() << ", ID: " << user_three.get_the_user_identifier() << std::endl << std::endl;

    std::cout << "--- All Users Processed ---" << std::endl;

    return 0;
}