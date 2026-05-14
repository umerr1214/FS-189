#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
#include <vector>

// Function to check if an integer is a palindrome
bool is_palindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are not palindromes
    }
    if (num < 10) {
        retun true; // SYNTAX ERROR: Typo 'retun' instead of 'return'
    }

    std::string s = std::to_string(num);
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    return s == reversed_s;
}

int main() {
    // Test cases
    std::cout << std::boolalpha; // Print true/false instead of 1/0

    std::cout << "is_palindrome(121): " << is_palindrome(121) << std::endl;
    std::cout << "is_palindrome(123): " << is_palindrome(123) << std::endl;
    std::cout << "is_palindrome(0): " << is_palindrome(0) << std::endl;
    std::cout << "is_palindrome(7): " << is_palindrome(7) << std::endl;
    std::cout << "is_palindrome(1221): " << is_palindrome(1221) << std::endl;
    std::cout << "is_palindrome(-121): " << is_palindrome(-121) << std::endl;
    std::cout << "is_palindrome(10): " << is_palindrome(10) << std::endl;

    return 0;
}