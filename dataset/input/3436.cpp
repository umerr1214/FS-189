#include <iostream>

// Function to calculate base raised to the power of exp using a loop
int power(int base, int exp) {
    if (exp < 0) {
        // For negative exponents, the result is typically a fraction,
        // which cannot be represented by an integer.
        // Or it could be considered an error condition.
        // For this problem, we'll assume non-negative exponents as per common usage.
        std::cerr << "Error: Exponent cannot be negative for integer power." << std::endl;
        return 0; // Or throw an exception
    }
    if (exp == 0) {
        return 1; // Any number to the power of 0 is 1
    }

    int result = 1;
    for (int i = 0; i < exp; ++i) {
        result *= base;
    }
    return result;
}

int main() {
    int base_val, exp_val;

    std::cout << "Enter base: ";
    std::cin >> base_val;

    std::cout << "Enter exponent: ";
    std::cin >> exp_val;

    std::cout << "Result: " << power(base_val, exp_val) std::endl; // Missing semicolon here

    return 0;
}