#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse
#include <limits>    // Required for std::numeric_limits

bool is_palindrome(int num) {
    // Readability / Efficiency Issue:
    // This implementation converts the integer to a string to check for palindrome.
    // While correct, it's generally less efficient than a purely arithmetic approach
    // due to string conversion overhead, memory allocation, and string manipulation.
    // It's also less "idiomatic" for integer palindrome checks in competitive programming
    // contexts where performance matters.

    std::string s = std::to_string(num);
    std::string reversed_s = s;
    std::reverse(reversed_s.begin(), reversed_s.end());
    return s == reversed_s;
}

int main() {
    std::cout << "--- Readability / Efficiency Issue Test ---" << std::endl;
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