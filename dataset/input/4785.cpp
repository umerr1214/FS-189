#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Correct and efficient implementation using exponentiation by squaring
long long calculatePower(int base, int exponent) {
    if (exponent == 0) {
        return 1; // Any number to the power of 0 is 1 (including 0^0 by convention)
    }

    // Handle base 0 for non-zero exponent
    if (base == 0) {
        return 0; // 0 raised to any positive exponent is 0
    }

    long long result = 1;
    long long current_base = base; // Use long long for current_base to prevent overflow during squaring

    // Exponentiation by squaring (O(log exponent) complexity)
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If exponent is odd, multiply result by current_base
            result *= current_base;
        }
        current_base *= current_base; // Square the current_base
        exponent /= 2; // Halve the exponent
    }
    return result;
}

int main() {
    int base, exponent;
    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        ss >> base >> exponent;
        long long result = calculatePower(base, exponent);
        std::cout << result << std::endl;
    }
    return 0;
}