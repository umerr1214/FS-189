#include <iostream>
#include <string>
#include <algorithm> // For std::equal, though used incorrectly here

// Function to check if a string is a palindrome
bool is_palindrome(std::string s)
{
    // Semantic Error: Using std::equal with incorrect iterator ranges.
    // Specifically, `s.begin() + s.length()` is past-the-end,
    // and `s.rbegin() + s.length()` is also past-the-end of the reverse iterator range.
    // This can lead to undefined behavior or incorrect comparisons.
    // The correct usage for std::equal with a reversed range would be:
    // return std::equal(s.begin(), s.begin() + s.length() / 2, s.rbegin());
    // However, the current implementation attempts to compare the entire string with
    // a reversed version of itself, but the iterator arithmetic is flawed,
    // particularly `s.rbegin() + s.length()` which is not how reverse iterators work for comparison.
    // It's trying to compare `s` with `std::string(s.rbegin(), s.rend())` but using std::equal with wrong ranges.

    if (s.empty()) {
        return true;
    }

    // This line causes the semantic issue.
    // s.begin() + s.length() is equivalent to s.end()
    // s.rbegin() + s.length() is an iterator far past the end of the reverse range.
    // The behavior of comparing elements using such an iterator is undefined.
    // It might compile and run, but produce incorrect results or crash.
    return std::equal(s.begin(), s.begin() + s.length(), s.rbegin());
}

int main() {
    // Test cases
    std::cout << "Is 'madam' a palindrome? " << (is_palindrome("madam") ? "Yes" : "No") << std::endl;      // Expected: Yes, Actual: Unpredictable/Incorrect
    std::cout << "Is 'racecar' a palindrome? " << (is_palindrome("racecar") ? "Yes" : "No") << std::endl;  // Expected: Yes, Actual: Unpredictable/Incorrect
    std::cout << "Is 'hello' a palindrome? " << (is_palindrome("hello") ? "Yes" : "No") << std::endl;      // Expected: No, Actual: Unpredictable/Incorrect
    std::cout << "Is 'A' a palindrome? " << (is_palindrome("A") ? "Yes" : "No") << std::endl;              // Expected: Yes, Actual: Unpredictable/Incorrect
    std::cout << "Is '' a palindrome? " << (is_palindrome("") ? "Yes" : "No") << std::endl;                // Expected: Yes, Actual: Yes (handled by empty check)
    std::cout << "Is 'ab' a palindrome? " << (is_palindrome("ab") ? "Yes" : "No") << std::endl;            // Expected: No, Actual: Unpredictable/Incorrect
    std::cout << "Is 'aba' a palindrome? " << (is_palindrome("aba") ? "Yes" : "No") << std::endl;          // Expected: Yes, Actual: Unpredictable/Incorrect
    std::cout << "Is 'Madam' a palindrome? " << (is_palindrome("Madam") ? "Yes" : "No") << std::endl;      // Expected: No, Actual: Unpredictable/Incorrect

    return 0;
}