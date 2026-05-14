#include <iostream>
#include <vector>
#include <cmath> // For comparing doubles
#include <iomanip> // For std::fixed and std::setprecision

// Readability / Efficiency Issue: This function contains redundant conditional checks
// that make the code longer and less straightforward than necessary,
// even though the logic is functionally correct.
// The variable names are also slightly verbose.
double power_calculation_func(double input_base_val, int num_exponent_val) {
    double result_accumulator = 1.0;

    // Redundant check: If num_exponent_val is 0, the loop below won't run,
    // and result_accumulator (initialized to 1.0) would correctly be returned.
    if (num_exponent_val == 0) {
        return 1.0;
    } 
    // Redundant check: If input_base_val is 0.0 and num_exponent_val > 0,
    // the loop below will correctly multiply by 0, making result_accumulator 0.0.
    else if (input_base_val == 0.0) {
        return 0.0;
    } 
    // The 'else' block is where the actual computation happens for all other valid cases.
    // The previous 'if' and 'else if' are unnecessary.
    else {
        for (int idx = 0; idx < num_exponent_val; ++idx) {
            result_accumulator *= input_base_val;
        }
    }
    return result_accumulator;
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
        double actual = power_calculation_func(base, exponent); // Call the specific function

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