#include <iostream>
#include <string>
#include <algorithm> // For std::reverse
#include <cctype>    // For std::tolower, std::isspace

// Function to clean and normalize the string (ignore case and spaces)
std::string cleanString(const std::string& str) {
    std::string cleaned;
    for (char c : str) {
        if (!std::isspace(static_cast<unsigned char>(c))) {
            cleaned += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

// Function to check if a string is a palindrome
bool isPalindrome(const std::string& str) {
    std::string cleaned_str = cleanString(str);
    std::string reversed_str = cleaned_str;
    std::reverse(reversed_str.begin(), reversed_str.end());
    return cleaned_str == reversed_str;
}

int main() {
    std::string input;
    std::cout << "Enter a string: ";
    // SEMANTIC ERROR: Using std::cin >> input instead of std::getline.
    // This will only read the first word of the input, ignoring the rest of the line.
    std::cin >> input; 
    if (isPalindrome(input)) {
        std::cout << "\"" << input << "\" is a palindrome." << std::endl;
    } else {
        std::cout << "\"" << input << "\" is NOT a palindrome." << std::endl;
    }
    return 0;
}