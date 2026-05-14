#include <iostream>
#include <limits> // For std::numeric_limits<int>::max()

bool is_palindrome(int num) {
    if (num < 0) {
        return false; // Negative numbers are not palindromes
    }
    // Single digit numbers (including 0) are palindromes
    if (num < 10) { 
        return true;
    }

    int originalNum = num;
    // SEMANTIC ERROR: 'reversedNum' is declared as 'int'.
    // For large input numbers whose true reversed value exceeds INT_MAX,
    // 'reversedNum' will overflow, leading to undefined behavior (typically wrap-around).
    // This means 'reversedNum' might not semantically represent the actual reversed number.
    int reversedNum = 0; 

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit; 
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() {
    std::cout << std::boolalpha;

    std::cout << "is_palindrome(121): " << is_palindrome(121) << std::endl;
    std::cout << "is_palindrome(123): " << is_palindrome(123) << std::endl;
    std::cout << "is_palindrome(0): " << is_palindrome(0) << std::endl;
    std::cout << "is_palindrome(7): " << is_palindrome(7) << std::endl;
    std::cout << "is_palindrome(1221): " << is_palindrome(1221) << std::endl;
    std::cout << "is_palindrome(-121): " << is_palindrome(-121) << std::endl;
    std::cout << "is_palindrome(10): " << is_palindrome(10) << std::endl;
    
    // Test cases for semantic error (integer overflow of intermediate result)
    // 1000000009: Not a palindrome. Its true reverse (9000000001) overflows a 32-bit signed int.
    // The `reversedNum` variable will become an incorrect value due to overflow,
    // but the final comparison `originalNum == reversedNum` will still correctly return `false`.
    std::cout << "is_palindrome(1000000009): " << is_palindrome(1000000009) << std::endl;

    // 2147483647 (INT_MAX): Not a palindrome. Its true reverse (7463847412) overflows an int.
    std::cout << "is_palindrome(2147483647): " << is_palindrome(2147483647) << std::endl;

    // 1000000001: A palindrome that fits within int limits and does not cause overflow.
    std::cout << "is_palindrome(1000000001): " << is_palindrome(1000000001) << std::endl;

    return 0;
}