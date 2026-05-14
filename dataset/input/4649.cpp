#include <iostream>
#include <string>
#include <algorithm> // Included, but not used for reversal in this logically incorrect version

int main() {
    std::string s;
    std::cout << "Enter a string: ";
    std::getline(std::cin, s);

    // Logical error: The program prints the original string instead of its reverse.
    std::cout << s << std::endl;

    return 0;
}