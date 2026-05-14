#include <iostream>
#include <string>
#include <algorithm> // For std::swap

int main() {
    std::string input_string;
    std::cout << "Enter a string: ";
    std::cin >> input_string;

    // Semantic Error: Incorrect indexing in the manual string reversal loop.
    // 'input_string.length() - i' can access one past the end of the string
    // (e.g., input_string[input_string.length()] when i=0), leading to
    // out-of-bounds access and undefined behavior. It should be 'input_string.length() - 1 - i'.
    for (int i = 0; i < input_string.length() / 2; ++i) {
        std::swap(input_string[i], input_string[input_string.length() - i]);
    }

    std::cout << "Reversed string: " << input_string << std::endl;

    return 0;
}