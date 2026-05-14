#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Required for std::fabs

// Function with Robustness Issue:
// 1. Incorrectly handles 0.0^0, returning 0.0 instead of 1.0.
// 2. Uses a simple O(n) recursive approach, which can lead to stack overflow
//    for very large 'n', demonstrating a lack of robustness for extreme inputs.
double power_robustness(double base, int n) {
    if (n < 0) {
        // The problem statement specifies 'n' is a non-negative integer.
        // A truly robust function might throw an error or handle it,
        // but for this "robustness issue" example, we'll assume valid 'n'.
        // If it were allowed, not handling it would be an issue.
        // For now, let's assume n >= 0 as per problem description.
    }

    if (n == 0) {
        // Robustness Issue: 0.0^0 is mathematically defined as 1.0.
        // This implementation incorrectly returns 0.0 if base is 0.0.
        if (base == 0.0) {
            return 0.0; // Incorrect: Should be 1.0 for 0.0^0
        }
        return 1.0;
    }
    
    // This simple recursion can lead to stack overflow for very large 'n'.
    // A more robust solution would use iterative or exponentiation by squaring
    // to prevent deep recursion.
    return base * power_robustness(base, n - 1);
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
        {0.0, 0, 0.0, "Base zero, exponent zero (Robustness Issue: Expected 1.0)"},
        {0.0, 5, 0.0, "Base zero, positive exponent"},
        {1.0, 100, 1.0, "Base one, large exponent"},
        {-2.0, 2, 4.0, "Negative base, even exponent"},
        {-2.0, 3, -8.0, "Negative base, odd exponent"}
    };

    bool all_passed = true;
    for (const auto& tc : testCases) {
        double result = power_robustness(tc.base, tc.n);
        // Using a small epsilon for double comparison
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