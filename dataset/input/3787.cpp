#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for the two-pointer approach, but often included

// Robustness Issue: This function incorrectly classifies single-character strings as non-palindromes.
// For example, "a" will be reported as "not a palindrome".
bool isPalindrome(const std::string& s) {
    if (s.empty()) {
        return true; // An empty string is generally considered a palindrome.
    }

    size_t left = 0;
    size_t right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false; // Mismatch found, not a palindrome.
        }
        left++;
        right--;
    }

    // INTENTIONAL BUG: For single-character strings (e.g., "a"), the loop above does not run
    // because left (0) is not less than right (0). It correctly proceeds here.
    // However, this explicit check then wrongly marks them as non-palindromes.
    if (s.length() == 1) {
        return false;
    }

    return true; // No mismatches found, it's a palindrome.
}

int main() {
    std::string word;
    std::cout << "Enter a word: ";

    // Basic input reading, but lacks robust error handling for stream failures
    if (!(std::cin >> word)) {
        std::cerr << "Error: Failed to read input word." << std::endl;
        return 1; // Indicate an error
    }

    if (isPalindrome(word)) {
        std::cout << "\"" << word << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << word << "\" is not a palindrome." << std::endl;
    }

    return 0;
}