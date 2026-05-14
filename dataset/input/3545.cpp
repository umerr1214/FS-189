#include <iostream>
#include <string>
#include <algorithm> // Required for std::tolower
#include <cctype>    // Required for std::tolower

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
        // Logical error: Using std::tolower, which ignores case,
        // despite the problem statement requiring an "exact match".
        if (std::tolower(input_str[i]) != std::tolower(input_str[length - 1 - i])) {
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