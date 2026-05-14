#include <iostream>
#include <string>
#include <algorithm> // For std::equal or std::reverse (not used in this version but good to include)
#include <vector>    // Not strictly needed for this problem, but common

// This program demonstrates a robustness issue:
// It uses std::cin >> s, which only reads a single word,
// ignoring any spaces or subsequent words.
// This means inputs like "race car" will be incorrectly processed as "race".

bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true; // An empty string is considered a palindrome
    }

    // Two-pointer approach
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    std::cout << "Enter a string: ";
    std::string inputString;
    // Robustness issue: Using std::cin >> inputString will only read up to the first whitespace.
    // For inputs like "race car", it will only read "race".
    std::cin >> inputString;

    if (isPalindrome(inputString)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}