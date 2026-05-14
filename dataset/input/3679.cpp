#include <iostream>
#include <string>
#include <algorithm> // For std::reverse

// Function to check if a string is a palindrome (case-sensitive, ignores non-alphanumeric)
// This version has a robustness issue: it is case-sensitive and does not ignore punctuation or spaces.
bool isPalindrome(const std::string& s) {
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    std::cout << "Enter a string to check if it's a palindrome: ";
    std::string input_string;
    std::getline(std::cin, input_string);

    if (isPalindrome(input_string)) {
        std::cout << "Yes, \"" << input_string << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "No, \"" << input_string << "\" is not a palindrome." << std::endl;
    }

    return 0;
}