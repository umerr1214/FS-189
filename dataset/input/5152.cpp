#include <iostream>
#include <string>

int main() {
    int num1, num2;

    std::cout << "Enter the first integer: ";
    std::cin >> num1;

    std::cout << "Enter the second integer: " // Syntax Error: Missing semicolon
    std::cin >> num2;

    // Determine the larger using the ternary operator
    int larger = (num1 > num2) ? num1 : num2;
    std::string message = (num1 == num2) ? "Both integers are equal: " : "The larger integer is: ";

    std::cout << message << larger << std::endl;

    return 0;
}