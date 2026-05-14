#include <iostream>
#include <string>
#include <algorithm> // For std::tolower, std::reverse
#include <cctype>    // For std::isspace

// This version is correct but less efficient and potentially less readable
// than a two-pointer approach, as it creates an entirely new reversed string.
bool isPalindrome(const std::string& s) {
    std::string filtered_s;
    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            filtered_s += std::tolower(static_cast<unsigned char>(c));
        }
    }

    // Inefficient part: creating a reversed copy and then comparing.
    // A two-pointer approach on filtered_s would be more efficient (O(N) time, O(1) extra space for check).
    // This approach uses O(N) extra space for the reversed string.
    std::string reversed_s = filtered_s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    return filtered_s == reversed_s;
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
    std::cout << "Test 'A Santa at NASA': " << isPalindrome("A Santa at NASA") << " (Expected: true)" << std::endl; // Longer palindrome

    return 0;
}