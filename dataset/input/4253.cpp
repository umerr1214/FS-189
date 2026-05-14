#include <iostream>
#include <string>
#include <algorithm> // Included but not used, demonstrating logical omission

int main() {
    std::string input_string;
    std::cout << "Enter a string: ";
    std::cin >> input_string;

    // Logical Error: The program prints the string in its original order
    // instead of reversing it. The reverse logic is entirely missing.
    std::cout << "Reversed string: " << input_string << std::endl;

    return 0;
}