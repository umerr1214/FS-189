#include <iostream>
#include <string>
#include <algorithm> // Included for potential use of std::reverse, though not used in direct printing.

// Renamed main to user_main for testing harness compatibility
int user_main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s); // Correctly reads the entire line, including spaces

    // Correct and efficient way to print a string in reverse order
    // Iterates from the last character to the first.
    // Handles empty strings gracefully (the loop condition `i >= 0` will immediately be false if s.length() is 0,
    // as `s.length() - 1` would be -1, making the loop not run).
    for (int i = s.length() - 1; i >= 0; --i) {
        std::cout << s[i];
    }
    std::cout << std::endl; // Ensures a newline after the reversed string

    return 0;
}