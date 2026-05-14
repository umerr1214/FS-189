#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
#include <cctype>    // For std::tolower, std::isspace

// Function to check if a string is a palindrome, ignoring case and spaces
bool isPalindrome(const std::string& s) {
    std::string processed_s;
    for (char c : s) {
        // Semantic Error: Passing 'char' directly to std::isspace and std::tolower.
        // These functions expect an 'int' that can be represented as an 'unsigned char' or EOF.
        // If 'char' is signed and 'c' holds a negative value (e.g., for extended ASCII characters),
        // this results in undefined behavior.
        if (!std::isspace(c)) { // Should be static_cast<unsigned char>(c)
            processed_s += std::tolower(c); // Should be static_cast<unsigned char>(c)
        }
    }

    std::string reversed_s = processed_s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    return processed_s == reversed_s;
}

int main()
{
    // Test cases
    std::cout << "Is 'Race car' a palindrome? " << (isPalindrome("Race car") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'Madam' a palindrome? " << (isPalindrome("Madam") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'A man, a plan, a canal: Panama' a palindrome? " << (isPalindrome("A man, a plan, a canal: Panama") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'hello' a palindrome? " << (isPalindrome("hello") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'No lemon, no melon' a palindrome? " << (isPalindrome("No lemon, no melon") ? "Yes" : "No") << std::endl;
    std::cout << "Is '12321' a palindrome? " << (isPalindrome("12321") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'Was it a car or a cat I saw?' a palindrome? " << (isPalindrome("Was it a car or a cat I saw?") ? "Yes" : "No") << std::endl;

    return 0;
}