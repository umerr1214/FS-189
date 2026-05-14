#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Function to check if a number is a palindrome.
// Readability/Efficiency Issue: This implementation converts the integer to a string,
// which is generally less efficient than pure integer arithmetic for this problem.
// Additionally, variable names are short and not very descriptive, impacting readability.
bool isPalindrome(int n) { // 'n' is a less descriptive variable name than 'num' or 'number'
    if (n < 0) {
        return false; // Correctly handles negative numbers (not palindromes)
    }
    
    std::string s = std::to_string(n); // Inefficient: converts integer to string
    std::string rs = s; // Redundant copy, 'rs' is not descriptive
    std::reverse(rs.begin(), rs.end()); // Efficient string reversal, but overall efficiency is hurt by conversion

    return s == rs;
}

int main() {
    int v; // 'v' is a less descriptive variable name than 'userInput' or 'number'
    std::cout << "Enter an integer: ";
    std::cin >> v;

    if (isPalindrome(v)) {
        std::cout << v << " is a palindrome." << std::endl;
    } else {
        std::cout << v << " is not a palindrome." << std::endl;
    }

    return 0;
}