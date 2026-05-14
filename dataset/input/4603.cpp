#include <iostream>
#include <string>
#include <algorithm> // For std::tolower and std::isalnum (often included with cctype)
#include <cctype>    // For std::tolower and std::isalnum

// This version contains a robustness issue:
// It incorrectly identifies an empty string or a string consisting only of non-alphanumeric characters as NOT a palindrome.
// An empty string, or a string that becomes empty after filtering, should be considered a palindrome.
bool isPalindromeSolution(const std::string& s) {
    std::string filtered_s;
    for (char c : s) {
        if (std::isalnum(static_cast<unsigned char>(c))) {
            filtered_s += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // ROBUSTNESS ISSUE: If filtered_s is empty (e.g., input was "", "!", "  "),
    // this function incorrectly returns false. An empty string is a palindrome.
    if (filtered_s.empty()) {
        return false; // BUG: Should be true
    }

    int left = 0;
    int right = filtered_s.length() - 1;

    while (left < right) {
        if (filtered_s[left] != filtered_s[right]) {
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