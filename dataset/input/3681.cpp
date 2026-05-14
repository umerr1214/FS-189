#include <iostream>
#include <string>
#include <algorithm> // For std::tolower
#include <cctype>    // For std::isalnum

// Function to check if a string is a palindrome, ignoring case and non-alphanumeric characters.
bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true;
    }

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move left pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(s[left])) {
            left++;
        }
        // Move right pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(s[right])) {
            right--;
        }

        // If pointers meet or cross, the remaining part is a palindrome
        if (left >= right) {
            break;
        }

        // Compare characters, ignoring case
        if (std::tolower(s[left]) != std::tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
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