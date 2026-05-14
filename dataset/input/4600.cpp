#include <iostream>
#include <string>
#include <algorithm> // For std::transform
#include <cctype>    // For tolower, isalnum

// Function to check if a string is a palindrome, ignoring case and non-alphanumeric characters
bool isPalindrome(const std::string& str) {
    std::string cleaned_str;
    for (char c : str) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            cleaned_str += std::tolower(static_cast<unsigned char>(c));
        }
    }

    if (cleaned_str.empty()) {
        return true; // An empty string is considered a palindrome
    }

    // Use two pointers to check for palindrome
    size_t left = 0;
    size_t right = cleaned_str.length() - 1;

    while (left < right) {
        if (cleaned_str[left] != cleaned_str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input_str;
    std::cout << "Enter a string: " // Missing semicolon here
    std::getline(std::cin, input_str);

    if (isPalindrome(input_str)) {
        std::cout << "\"" << input_str << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input_str << "\" is not a palindrome." << std::endl;
    }

    return 0;
}