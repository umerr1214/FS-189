#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end()) // SYNTAX ERROR: Missing semicolon here
    return s == reversed_s;
}

int main() {
    std::cout << "Enter a string: ";
    std::string userString;
    std::getline(std::cin, userString);

    if (isPalindrome(userString)) {
        std::cout << userString << " is a palindrome." << std::endl;
    } else {
        std::cout << userString << " is not a palindrome." << std::endl;
    }

    return 0;
}