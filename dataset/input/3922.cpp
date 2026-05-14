#include <iostream>
#include <string>
#include <limits> // Required for numeric_limits

int main() {
    std::string inputString;
    char searchChar;

    std::cout << "Enter a string: ";
    std::getline(std::cin, inputString) // Syntax Error: Missing semicolon here

    std::cout << "Enter a character to count: ";
    std::cin >> searchChar;

    // Clear the input buffer after reading a char with >>
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int count = 0;
    for (char c : inputString) {
        if (c == searchChar) {
            count++;
        }
    }

    std::cout << "The character '" << searchChar << "' appears " << count << " times in \"" << inputString << "\"." << std::endl;

    return 0;
}