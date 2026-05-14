#include <iostream> // Required for std::cout, std::cin, std::endl
#include <string>   // Required for std::string

void solve() {
    std::string userName; // Descriptive variable name for the user's name
    int userAge;          // Descriptive variable name for the user's age

    // Prompt the user to enter their name
    std::cout << "Enter your name: ";
    std::cin >> userName; // Read the name (single word) from standard input

    // Prompt the user to enter their age
    std::cout << "Enter your age: ";
    std::cin >> userAge;  // Read the age (integer) from standard input

    // Print the greeting message displaying both pieces of information
    std::cout << "Hello, " << userName << "! You are " << userAge << " years old." << std::endl;
}

int main() {
    solve(); // Call the core logic function
    return 0; // Indicate successful execution
}