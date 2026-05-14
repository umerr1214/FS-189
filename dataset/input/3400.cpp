#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
#include <cctype>    // For std::tolower, std::isspace

// Function to check if a string is a palindrome, ignoring case and spaces
bool isPalindrome(const std::string& s) {
    std::string processed_s; // Missing semicolon here, causing a syntax error
    for (char c : s) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            processed_s += std::tolower(static_cast<unsigned char>(c));
        }
    }

    std::string reversed_s = processed_s;
    std::reverse(reversed_s.begin(), reversed_s.end());

    return processed_s == reversed_s;
}

int main()
{
    // The program is expected to fail compilation due to the syntax error.
    // The following calls would demonstrate functionality if it compiled.
    // std::cout << "Is 'Race car' a palindrome? " << (isPalindrome("Race car") ? "Yes" : "No") << std::endl;
    // std::cout << "Is 'Madam' a palindrome? " << (isPalindrome("Madam") ? "Yes" : "No") << std::endl;
    // std::cout << "Is 'A man, a plan, a canal: Panama' a palindrome? " << (isPalindrome("A man, a plan, a canal: Panama") ? "Yes" : "No") << std::endl;
    return 0;
}