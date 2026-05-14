#include <iostream>
#include <string>
#include <algorithm> // Included for potential use, but not directly involved in the syntax error

int main() {
    std::string s;
    std::cout << "Enter a string: " std::endl; // Syntax error: Missing '<<' operator
    std::getline(std::cin, s);

    // If the syntax error were fixed, the intended logic would be:
    // std::reverse(s.begin(), s.end());
    // std::cout << "Reversed string: " << s << std::endl;

    return 0;
}