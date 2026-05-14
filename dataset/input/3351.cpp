#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Required for std::fabs

// Correct Version:
// Implements the recursive exponentiation by squaring (binary exponentiation) algorithm.
// This approach is highly efficient (O(log n) time complexity) and handles edge cases
// like n=0 and base=0 correctly, while maintaining good readability.
double power_correct(double base, int n) {
    // Base case: Any number to the power of 0 is 1.0
    // (This includes 0.0^0, which is conventionally 1.0)
    if (n == 0) {
        return 1.0;
    }

    // Handle 0^n for n > 0.
    // If base is 0.0 and n > 0, the result is 0.0.
    // This optimization prevents unnecessary recursion if base is 0.
    if (base == 0.0) {
        return 0.0;
    }

    // Recursive step for exponentiation by squaring
    // Calculate base^(n/2) once to avoid redundant computations
    double half_power = power_correct(base, n / 2);

    if (n % 2 == 0) {
        // If n is even, base^n = (base^(n/2)) * (base^(n/2))
        return half_power * half_power;
    } else {
        // If n is odd, base^n = base * (base^(n/2)) * (base^(n/2))
        return base * half_power * half_power;
    }
}

struct TestCase {
    double base;
    int n;
    double expected;
    std::string description;
};

int main() {
    std::vector<TestCase> testCases = {
        {2.0, 3, 8.0, "Positive base, positive exponent"},
        {5.0, 0, 1.0, "Positive base, zero exponent"},
        {0.0, 0, 1.0, "Base zero, exponent zero (Correct)"},
        {0.0, 5, 0.0, "Base zero, positive exponent"},
        {1.0, 100, 1.0, "Base one, large exponent"},
        {-2.0, 2, 4.0, "Negative base, even exponent"},
        {-2.0, 3, -8.0, "Negative base, odd exponent"},
        {3.0, 7, 2187.0, "Another positive base, positive odd exponent"},
        {2.5, 2, 6.25, "Decimal base, even exponent"},
        {10.0, 6, 1000000.0, "Larger base and exponent"}
    };

    bool all_passed = true;
    for (const auto& tc : testCases) {
        double result = power_correct(tc.base, tc.n);
        if (std::fabs(result - tc.expected) > 1e-9) {
            std::cerr << "Test Failed: " << tc.description
                      << " | Input: base=" << tc.base << ", n=" << tc.n
                      << " | Expected: " << tc.expected
                      << " | Got: " << result << std::endl;
            all_passed = false;
        } else {
            // std::cout << "Test Passed: " << tc.description << std::endl;
        }
    }

    if (!all_passed) {
        return 1; // Indicate failure
    }
    return 0; // Indicate success
}