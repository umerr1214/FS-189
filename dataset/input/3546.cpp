#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse (if used)

int main() {
    std::string input_str;
    // std::cout << "Enter a string: "; // Commented out for automated testing
    std::getline(std::cin, input_str);

    if (input_str.empty()) {
        std::cout << "Palindrome" << std::endl;
        return 0;
    }

    bool is_palindrome = true;
    int length = input_str.length();

    for (int i = 0; i < length / 2; ++i) {
        // Semantic error: Accessing s[length - i] instead of s[length - 1 - i].
        // When i = 0, this attempts to access s[length], which is one past the end of the string,
        // leading to undefined behavior. While it might not crash on all systems/inputs,
        // it's an incorrect and potentially dangerous memory access.
        if (input_str[i] != input_str[length - i]) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        std::cout << "Palindrome" << std::endl;
    } else {
        std::cout << "Not a palindrome" << std::endl;
    }

    return 0;
}