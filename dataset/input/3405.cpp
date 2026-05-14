#include <iostream>
#include <string>
#include <algorithm> // For std::tolower
#include <cctype>    // For std::isspace

// This version is correct, robust, and efficient.
// It filters the string in one pass and then uses a two-pointer approach.
bool isPalindrome(const std::string& s) {
    std::string filtered_s;
    filtered_s.reserve(s.length()); // Optimize allocation to avoid reallocations

    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            filtered_s += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // An empty string (or a string that becomes empty after filtering) is a palindrome.
    // This handles cases like "", "   " correctly.
    if (filtered_s.empty()) {
        return true;
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
    std::cout << "Test '': " << isPalindrome("") << " (Expected: true)" << std::endl;
    std::cout << "Test '   ': " << isPalindrome("   ") << " (Expected: true)" << std::endl;
    std::cout << "Test 'A': " << isPalindrome("A") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Aa': " << isPalindrome("Aa") << " (Expected: true)" << std::endl;
    std::cout << "Test 'A.A': " << isPalindrome("A.A") << " (Expected: true)" << std::endl;
    std::cout << "Test 'No lemon, no melon': " << isPalindrome("No lemon, no melon") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Was it a car or a cat I saw?': " << isPalindrome("Was it a car or a cat I saw?") << " (Expected: true)" << std::endl;
    std::cout << "Test 'A Santa at NASA': " << isPalindrome("A Santa at NASA") << " (Expected: true)" << std::endl;
    std::cout << "Test 'Eva, can I see bees in a cave?': " << isPalindrome("Eva, can I see bees in a cave?") << " (Expected: true)" << std::endl;
    std::cout << "Test '12321': " << isPalindrome("12321") << " (Expected: true)" << std::endl;
    std::cout << "Test '123 321': " << isPalindrome("123 321") << " (Expected: true)" << std::endl;
    std::cout << "Test 'not a palindrome': " << isPalindrome("not a palindrome") << " (Expected: false)" << std::endl;

    return 0;
}