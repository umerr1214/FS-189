#include <iostream>

// Function to calculate base raised to the power of exponent
int calculatePower(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int base, exponent;

    std::cout << "Enter base: ";
    std::cin >> base;

    std::cout << "Enter exponent (non-negative): ";
    std::cin >> exponent;

    // This line has a missing semicolon, causing a syntax error
    std::cout << "Result: " << calculatePower(base, exponent) 

    return 0;
}