#include <iostream>
#include <vector>
#include <cmath> // For comparing doubles
#include <iomanip> // For std::fixed and std::setprecision

// Correct and clean implementation of the power function.
// It handles all specified conditions and edge cases (like exponent = 0, base = 0) correctly and concisely.
double power(double base, int exponent) {
    // Initialize result to 1.0. This handles the x^0 = 1 case correctly.
    // If exponent is 0, the loop will not execute, and 1.0 will be returned.
    double result = 1.0;

    // The problem states exponent is non-negative.
    // If base is 0 and exponent is > 0, the first iteration of the loop
    // will set result to 0.0, and subsequent multiplications will keep it 0.0,
    // which is correct (0^positive = 0).
    // If base is 0 and exponent is 0, result remains 1.0 (0^0 = 1.0), which is standard.
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}

int main() {
    std::vector<std::pair<std::pair<double, int>, double>> test_cases = {
        {{2.0, 3}, 8.0},
        {{5.0, 0}, 1.0},
        {{1.0, 10}, 1.0},
        {{0.0, 5}, 0.0},
        {{0.0, 0}, 1.0},
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