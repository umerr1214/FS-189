#include <iostream>
#include <vector>
#include <cmath> // For comparing doubles
#include <iomanip> // For std::fixed and std::setprecision

double power(double base, int exponent) {
    // Robustness Issue: This implementation incorrectly handles the case where exponent is 0.
    // According to mathematical definition, x^0 should be 1.0 (including 0^0 = 1.0).
    // This code returns 'base' for exponent = 0, which is incorrect unless base is 1.0.
    // Specifically, power(5.0, 0) will return 5.0 instead of 1.0.
    // And power(0.0, 0) will return 0.0 instead of 1.0.

    if (exponent == 0) {
        return base; // INCORRECT: Should return 1.0
    }

    // Assume exponent is non-negative as per problem statement, so no negative exponent handling needed.
    // For exponent > 0, the loop calculates correctly.
    double result = base; // Initialize with base
    for (int i = 1; i < exponent; ++i) { // Loop exponent-1 times
        result *= base;
    }
    return result;
}

int main() {
    std::vector<std::pair<std::pair<double, int>, double>> test_cases = {
        {{2.0, 3}, 8.0},
        {{5.0, 0}, 1.0}, // Fails here: expects 1.0, gets 5.0
        {{1.0, 10}, 1.0},
        {{0.0, 5}, 0.0},
        {{0.0, 0}, 1.0}, // Fails here: expects 1.0, gets 0.0
        {{-2.0, 2}, 4.0},
        {{-2.0, 3}, -8.0},
        {{10.0, 1}, 10.0},
        {{0.5, 2}, 0.25},
        {{3.0, 4}, 81.0}
    };

    bool all_passed = true;
    double epsilon = 1e-9; // For floating point comparison

    std::cout << std::fixed << std::setprecision(10);

    for (const auto& tc : test_cases) {
        double base = tc.first.first;
        int exponent = tc.first.second;
        double expected = tc.second;
        double actual = power(base, exponent);

        if (std::abs(actual - expected) > epsilon) {
            std::cout << "Test failed for power(" << base << ", " << exponent << ")\n";
            std::cout << "Expected: " << expected << ", Actual: " << actual << "\n";
            all_passed = false;
        } else {
            std::cout << "Test passed for power(" << base << ", " << exponent << ")\n";
        }
    }

    if (all_passed) {
        std::cout << "\nAll test cases passed!\n";
    } else {
        std::cout << "\nSome test cases failed.\n";
    }

    return 0;
}