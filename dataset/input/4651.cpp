#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

int main() {
    std::cout << "Enter a string (single word): ";
    std::string userString;
    
    // Robustness Issue: Using std::cin >> userString will only read up to the first whitespace.
    // If the user enters "hello world", only "hello" will be read and reversed.
    // It also doesn't check for potential input stream failures.
    std::cin >> userString;

    // Check if input failed
    if (std::cin.fail()) {
        std::cerr << "Error reading input." << std::endl;
        return 1;
    }

    std::reverse(userString.begin(), userString.end());

    std::cout << "Reversed string: " << userString << std::endl;

    return 0;
}