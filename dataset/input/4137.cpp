#include <iostream> // Required for std::cout, std::cin, std::endl
#include <string>   // Required for std::string, std::getline

int main() {
    // Prompt the user to enter their full name
    std::cout << "Please enter your full name: ";

    // Declare an std::string to store the full name
    std::string fullName;

    // Read the entire line, including spaces, into the std::string.
    // std::getline is the correct, robust, and idiomatic way to achieve this.
    std::getline(std::cin, fullName);

    // Print the full name back to the user
    std::cout << "Your full name is: " << fullName << std::endl;

    // Display the total number of characters in the name.
    // std::string::length() (or .size()) is the efficient and clear way to get the length.
    std::cout << "Total characters: " << fullName.length() << std::endl;

    return 0; // Indicate successful program execution
}