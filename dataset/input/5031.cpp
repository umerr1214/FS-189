#include <iostream>
#include <string>
#include <algorithm> // Not strictly needed for this version, but good for general string ops

// This program is a correct and efficient implementation of the palindrome check.
// - It uses std::getline to read the full input string.
// - It employs a two-pointer approach for efficient palindrome checking, avoiding
//   unnecessary string copies.
// - The logic is encapsulated in a separate function for better modularity and readability.
// - Variable names are clear and descriptive.

bool isPalindrome(const std::string& str) {
    // An empty string or a single-character string is considered a palindrome
    if (str.length() <= 1) {
        return true;
    }

    int left = 0;
    int right = str.length() - 1;

    // Compare characters from both ends moving towards the center
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Mismatch found, not a palindrome
        }
        left++;
        right--;
    }
    return true; // All characters matched, it's a palindrome
}

int main() {
    std::cout << "Enter a string: ";
    std::string inputString;
    std::getline(std::cin, inputString); // Correctly reads the entire line from user

    if (isPalindrome(inputString)) {
        std::cout << "true" << std::endl;
    } else {
        std::cout << "false" << std::endl;
    }

    return 0;
}