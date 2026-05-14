#include <iostream>
#include <string>
#include <algorithm> // For std::tolower, std::isalnum
#include <cctype>    // For std::tolower, std::isalnum

// This version is correct, readable, and efficient.
// It uses a two-pointer approach to compare characters on the fly,
// skipping non-alphanumeric characters and converting to lowercase as needed,
// thus avoiding the creation of temporary strings.
bool isPalindromeSolution(const std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        // Move left pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
            left++;
        }
        // Move right pointer past non-alphanumeric characters
        while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
            right--;
        }

        // If pointers meet or cross, all remaining characters are processed or it's an empty/single-char string
        if (left >= right) {
            break;
        }

        // Compare characters, ignoring case
        if (std::tolower(static_cast<unsigned char>(s[left])) != std::tolower(static_cast<unsigned char>(s[right]))) {
            return false;
        }

        left++;
        right--;
    }
    return true;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);

    if (isPalindromeSolution(input)) {
        std::cout << "The string is a palindrome." << std::endl;
    } else {
        std::cout << "The string is not a palindrome." << std::endl;
    }

    return 0;
}