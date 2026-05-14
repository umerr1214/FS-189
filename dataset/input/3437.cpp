#include <iostream>

// Function to calculate base raised to the power of exp using a loop
int power(int base, int exp) {
    if (exp < 0) {
        std::cerr << "Error: Exponent cannot be negative for integer power." << std::endl;
        return 0;
    }
    if (exp == 0) {
        return 1;
    }

    int result = 0; // Logical error: Should be initialized to 1
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

    std::cout << "Result: " << power(base_val, exp_val) << std::endl;

    return 0;
}