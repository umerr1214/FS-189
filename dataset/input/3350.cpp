#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Required for std::fabs

// Function with Readability / Efficiency Issue:
// 1. Efficiency Issue: Uses a naive O(n) recursive approach, which is correct
//    but significantly less efficient than the O(log n) exponentiation by squaring method.
// 2. Readability Issue: Variable names 'b' and 'e' are less descriptive than 'base' and 'n'.
double calculate_power(double b, int e) { // 'b' for base, 'e' for exponent
    if (e == 0) {
        return 1.0;
    }
    // This is the O(n) recursive approach. It's correct but inefficient.
    return b * calculate_power(b, e - 1);
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
        {0.0, 5, 0.0, "Base zero, positive exponent"},
        {1.0, 100, 1.0, "Base one, large exponent"},
        {3.0, 7, 2187.0, "Another positive base, positive exponent"},
        {-2.0, 2, 4.0, "Negative base, even exponent"},
        {-2.0, 3, -8.0, "Negative base, odd exponent"},
        {0.0, 0, 1.0, "Base zero, exponent zero"} // This version handles 0^0 correctly
    };

    bool all_passed = true;
    for (const auto& tc : testCases) {
        double result = calculate_power(tc.base, tc.n);
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