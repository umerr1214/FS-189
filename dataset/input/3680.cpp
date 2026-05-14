#include <iostream>
#include <string>
#include <vector> // Not strictly needed but sometimes included for other tasks, adding for slight "clutter" effect
#include <algorithm> // For std::tolower (not used in primary logic but could be)

// Function to check if a string is a palindrome.
// This version has an efficiency issue as it manually constructs a reversed string
// character by character, which is less efficient than a two-pointer approach or
// using std::string(s.rbegin(), s.rend()). It's also slightly less readable
// due to the manual loop compared to std::reverse.
bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true;
    }

    std::string reversed_str_manual;
    reversed_str_manual.reserve(s.length()); // Pre-allocate memory, slight optimization

    for (int i = s.length() - 1; i >= 0; --i) {
        reversed_str_manual += s[i];
    }

    // This comparison is also character by character internally
    return s == reversed_str_manual;
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