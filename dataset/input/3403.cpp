#include <iostream>
#include <string>
#include <algorithm> // For std::tolower
#include <cctype>    // For std::isspace

// This version has a robustness issue: it incorrectly returns false for empty strings
// or strings that become empty after removing spaces.
bool isPalindrome(const std::string& s) {
    std::string filtered_s;
    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            filtered_s += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // Robustness issue: If filtered_s is empty, it should be considered a palindrome (true).
    // This implementation will proceed to the loop and return false.
    // An empty string is a palindrome.
    // Example: "", "   " should return true. This will return false.
    if (filtered_s.empty()) {
        return false; // BUG: Should be true for empty strings
    }

    int left = 0;
    int right = filtered_s.length() - 1;

    while (left < right) {
        if (filtered_s[left] != filtered_s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

// Driver code for local testing
int main() {
    std::cout << std::boolalpha;
    std::cout << "Test 'Race car': " << isPalindrome("Race car") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Madam': " << isPalindrome("Madam") << " (Expected: true)" << std::endl;
    std::cout << "Test 'hello': " << isPalindrome("hello") << " (Expected: false)" << std::endl;
    std::cout << "Test '': " << isPalindrome("") << " (Expected: true, Actual: false - Robustness Issue)" << std::endl;
    std::cout << "Test '   ': " << isPalindrome("   ") << " (Expected: true, Actual: false - Robustness Issue)" << std::endl;
    std::cout << "Test 'A': " << isPalindrome("A") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Aa': " << isPalindrome("Aa") << " (Expected: true)" << std::endl;
    std::cout << "Test 'A.A': " << isPalindrome("A.A") << " (Expected: true)" << std::endl;
    std::cout << "Test 'No lemon, no melon': " << isPalindrome("No lemon, no melon") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Was it a car or a cat I saw?': " << isPalindrome("Was it a car or a cat I saw?") << " (Expected: true)" << std::endl;

    return 0;
}