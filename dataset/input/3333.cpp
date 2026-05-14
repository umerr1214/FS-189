#include <iostream>
#include <limits> // Required for std::numeric_limits

bool is_palindrome(int num) {
    // Correct Version:
    // Handles negative numbers, zero, and uses an efficient arithmetic approach
    // that prevents integer overflow during reversal by using a 'long long' type
    // for the reversed number.

    if (num < 0) {
        return false; // Negative numbers are generally not considered palindromes
    }
    if (num == 0) {
        return true; // 0 is a palindrome
    }

    int original_num = num;
    long long reversed_num = 0; // Use long long to safely store the reversed number, preventing overflow

    while (num != 0) {
        int digit = num % 10;
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    // Compare the original integer with the reversed number (which might be long long)
    // Implicit conversion of original_num to long long happens for comparison.
    // This correctly handles cases where the reversed number might exceed INT_MAX
    // (though the original input 'num' is guaranteed to be within int range).
    return original_num == reversed_num;
}

int main() {
    std::cout << "--- Correct Version Test ---" << std::endl;
    std::cout << "is_palindrome(121): " << (is_palindrome(121) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(0): " << (is_palindrome(0) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(12345): " << (is_palindrome(12345) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(-121): " << (is_palindrome(-121) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(10): " << (is_palindrome(10) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(11): " << (is_palindrome(11) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(" << std::numeric_limits<int>::max() << "): " << (is_palindrome(std::numeric_limits<int>::max()) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(1000000001): " << (is_palindrome(1000000001) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(123454321): " << (is_palindrome(123454321) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(123456789): " << (is_palindrome(123456789) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(" << std::numeric_limits<int>::min() << "): " << (is_palindrome(std::numeric_limits<int>::min()) ? "true" : "false") << " (Expected: false)" << std::endl;
    return 0;
}