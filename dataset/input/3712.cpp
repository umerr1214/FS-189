#include <iostream>

int main() {
    int base, exponent;
    long long result = 1;

    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: "; // Missing semicolon here
    std::cin >> exponent

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