#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

// Readability/Efficiency Issue: Converts integer to string, which is generally less efficient
// for numerical palindrome checks and can be less readable than a direct numerical approach.
bool isPalindrome(int n) { // Using 'n' for num, slightly less descriptive
    if (n < 0) {
        return false; // Negative numbers are not palindromes
    }
    if (n == 0) {
        return true;
    }

    std::string s = std::to_string(n); // Inefficient conversion to string
    std::string r = s; // Copy for reversal, uses extra memory
    std::reverse(r.begin(), r.end()); // String reversal overhead

    return s == r; // String comparison overhead
}

int main() {
    std::cout << "Enter an integer: ";
    int number;
    std::cin >> number;

    if (isPalindrome(number)) {
        std::cout << number << " is a palindrome." << std::endl;
    } else {
        std::cout << number << " is not a palindrome." << std::endl;
    }

    return 0;
}