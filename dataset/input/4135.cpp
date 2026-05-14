#include <iostream>
#include <string>

int main() {
    std::cout << "Please enter your full name: ";
    std::string fullName;

    // Robustness Issue:
    // This program does not check the state of std::cin after the input operation.
    // If std::cin is already in a failed state (e.g., due to EOF being piped,
    // or a previous invalid input operation if this wasn't the first read),
    // std::getline will fail to read anything, 'fullName' will remain empty,
    // but the program will proceed as if an empty name was entered,
    // without informing the user of the input error.
    // A robust program would check std::cin.fail() or std::cin.bad() and handle it.
    std::getline(std::cin, fullName);

    std::cout << "Your full name is: " << fullName << std::endl;
    std::cout << "Total characters: " << fullName.length() << std::endl;

    return 0;
}