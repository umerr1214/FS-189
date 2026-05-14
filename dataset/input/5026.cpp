#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse (though not used in final palindrome logic for this example)

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& s) {
    size_t len = s.length();
    if (len == 0 || len == 1) {
        return true;
    }

    for (size_t i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string inputString;
    std::cout << "Enter a string: " // Missing semicolon here
    std::getline(std::cin, inputString);

    if (isPalindrome(inputString)) {
        std::cout << "\"" << inputString << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << inputString << "\" is not a palindrome." << std::endl;
    }

    return 0;
}