#include <iostream>

int main() {
    int base, exponent;
    long long result = 0; // Logical error: Should be initialized to 1

    std::cout << "Enter base: ";
    std::cin >> base;
    std::cout << "Enter exponent: ";
    std::cin >> exponent;

    if (exponent < 0) {
        std::cout << "Exponent must be a positive integer." << std::endl;
        return 1;
    }
    // Base case for exponent 0 is usually 1, but problem states positive exponent.
    // If exponent is 0, the loop won't run, and result will be 0, which is incorrect.
    // For positive exponents, multiplying by 0 will always result in 0.

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    std::cout << "Result: " << result << std::endl;

    return 0;
}