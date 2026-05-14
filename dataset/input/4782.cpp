#include <iostream>

// Function to calculate base raised to the power of exponent (with a semantic error for 0^0)
int calculatePower(int base, int exponent) {
    if (exponent == 0) {
        // Semantic error: For 0^0, standard mathematical interpretation in computing is usually 1.
        // This implementation returns 0 for 0^0, which is a common point of confusion.
        if (base == 0) {
            return 0; // This is the semantic error: 0^0 should typically be 1.
        }
        return 1;
    }

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

    std::cout << "Result: " << calculatePower(base, exponent) << std::endl;

    return 0;
}