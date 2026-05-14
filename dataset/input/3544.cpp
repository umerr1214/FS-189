#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse (if used)

int main() {
    std::string input_str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, input_str);

    if (input_str.empty()) {
        std::cout << "Palindrome" << std::endl;
        return 0;
    }

    std::string reversed_str = input_str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    if (input_str == reversed_str) {
        std::cout << "Palindrome" << std::endl
    } else {
        std::cout << "Not a palindrome" << std::endl;
    }

    return 0;
}