#include <iostream>

int main() {
    int base, exponent;
    int result = 1; // Semantic error: 'int' might overflow for large results

    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    if (exponent < 0) {
        std::cout << "Exponent must be a positive integer." << std::endl;
        return 1;
    }

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}