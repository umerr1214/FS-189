#include <iostream>
#include <string>
#include <algorithm> // Not directly used in the erroneous line, but common for string manipulation

int main() {
    std::string input_string;
    std::cout << "Enter a string: ";
    std::cin >> input_string;

    // Syntax Error: Missing semicolon after the std::cout statement
    std::cout << "Reversed string: " 
    for (int i = input_string.length() - 1; i >= 0; --i) {
        std::cout << input_string[i];
    }
    std::cout << std::endl;

    return 0;
}