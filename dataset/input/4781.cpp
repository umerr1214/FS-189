#include <iostream>

// Function to calculate base raised to the power of exponent (with a logical error)
int calculatePower(int base, int exponent) {
    // Logical error: This function calculates base * exponent, not base^exponent
    if (exponent == 0) {
        return 1; // Correct for exponent 0, but the rest is wrong
    }
    return base * exponent; // Incorrect calculation for power
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