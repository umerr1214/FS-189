#include <iostream>
#include <limits> // Required for std::numeric_limits

bool is_palindrome(int num) {
    // Robustness Issue:
    // 1. Does not handle negative numbers according to common palindrome definition
    //    (e.g., -121 will be considered a palindrome).
    // 2. Uses 'int' for reversed_num, which can lead to integer overflow
    //    for large numbers, resulting in undefined behavior and incorrect results.

    int original_num = num;
    int reversed_num = 0;

    // Handle 0 as a special case, though the loop handles it too (reversed_num remains 0)
    // For this buggy version, we want to demonstrate issues, so no special handling for 0 or negative.

    while (num != 0) {
        int digit = num % 10;
        // Potential integer overflow here if reversed_num * 10 + digit exceeds INT_MAX or falls below INT_MIN
        reversed_num = reversed_num * 10 + digit;
        num /= 10;
    }

    return original_num == reversed_num;
}

int main() {
    std::cout << "--- Robustness Issue Test ---" << std::endl;
    std::cout << "is_palindrome(121): " << (is_palindrome(121) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(0): " << (is_palindrome(0) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(12345): " << (is_palindrome(12345) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(-121): " << (is_palindrome(-121) ? "true" : "false") << " (Expected: false - BUG: returns true)" << std::endl;
    std::cout << "is_palindrome(10): " << (is_palindrome(10) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(11): " << (is_palindrome(11) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(" << std::numeric_limits<int>::max() << "): " << (is_palindrome(std::numeric_limits<int>::max()) ? "true" : "false") << " (Expected: false - might be incorrect due to overflow)" << std::endl;
    std::cout << "is_palindrome(1000000001): " << (is_palindrome(1000000001) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(123454321): " << (is_palindrome(123454321) ? "true" : "false") << " (Expected: true)" << std::endl;
    std::cout << "is_palindrome(123456789): " << (is_palindrome(123456789) ? "true" : "false") << " (Expected: false)" << std::endl;
    std::cout << "is_palindrome(" << std::numeric_limits<int>::min() << "): " << (is_palindrome(std::numeric_limits<int>::min()) ? "true" : "false") << " (Expected: false - might be incorrect due to overflow/UB)" << std::endl;
    return 0;
}