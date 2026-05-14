#include <iostream>
#include <string> // Required for driver, not for problem logic

// Function to calculate power using exponentiation by squaring (efficient and robust)
long long calculatePower(int base, int exponent) {
    // Input validation for positive integers is handled in solve() function.
    // This function assumes base >= 1 and exponent >= 1 as per problem constraints.

    long long result = 1;
    long long currentBase = base; // Use long long for currentBase to prevent overflow during squaring intermediate steps

    while (exponent > 0) {
        if (exponent % 2 == 1) { // If exponent is odd, multiply result by currentBase
            result *= currentBase;
        }
        currentBase *= currentBase; // Square the base for the next iteration
        exponent /= 2; // Halve the exponent
    }
    return result;
}

// Function containing the core logic
void solve() {
    int baseInput, exponentInput;
    std::cout << "Enter base (positive integer): ";
    std::cin >> baseInput;
    std::cout << "Enter exponent (positive integer): ";
    std::cin >> exponentInput;

    if (baseInput <= 0 || exponentInput <= 0) {
        std::cerr << "Error: Both base and exponent must be positive integers." << std::endl;
        return;
    }

    long long finalResult = calculatePower(baseInput, exponentInput);
    std::cout << "Result: " << finalResult << std::endl;
}

int main() {
    solve();
    return 0;
}