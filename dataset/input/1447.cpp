#include <iostream>
#include <vector>
#include <cmath> // For std::abs
#include <iomanip> // For std::fixed, std::setprecision

class Temperature {
private:
    double celsius;

public:
    // Constructor
    Temperature(double c) : celsius(c) {}

    // Public method to get Fahrenheit temperature
    double getFahrenheit() {
        // Robustness Issue: Using integer division (9/5) instead of floating-point (9.0/5.0)
        // This will result in (1) instead of (1.8), leading to incorrect Fahrenheit conversion.
        return celsius * (9 / 5) + 32.0;
    }
};

struct TestCase {
    double input_celsius;
    double expected_fahrenheit; // Expected output based on the flawed code
    double actual_correct_fahrenheit; // For comparison in JSON
};

int main() {
    std::vector<TestCase> test_cases = {
        {0.0, 32.0, 32.0}, // 0 * 1 + 32 = 32
        {20.0, 52.0, 68.0}, // 20 * 1 + 32 = 52 (instead of 68.0)
        {-10.0, 22.0, 14.0}, // -10 * 1 + 32 = 22 (instead of 14.0)
        {100.0, 132.0, 212.0} // 100 * 1 + 32 = 132 (instead of 212.0)
    };

    std::cout << std::fixed << std::setprecision(1);

    int passed_count = 0;
    for (size_t i = 0; i < test_cases.size(); ++i) {
        Temperature temp(test_cases[i].input_celsius);
        double actual_fahrenheit = temp.getFahrenheit();
        
        // Compare against the expected output of the flawed code
        if (std::abs(actual_fahrenheit - test_cases[i].expected_fahrenheit) < 0.001) {
            std::cout << "Test Case " << i + 1 << " Passed (Flawed Logic): "
                      << test_cases[i].input_celsius << " C -> "
                      << actual_fahrenheit << " F (Expected by flawed code: "
                      << test_cases[i].expected_fahrenheit << " F)" << std::endl;
            passed_count++;
        } else {
            std::cout << "Test Case " << i + 1 << " FAILED (Flawed Logic): "
                      << test_cases[i].input_celsius << " C -> "
                      << actual_fahrenheit << " F (Expected by flawed code: "
                      << test_cases[i].expected_fahrenheit << " F)" << std::endl;
        }
    }

    std::cout << "\n--- Test Summary ---" << std::endl;
    std::cout << "Total Tests: " << test_cases.size() << std::endl;
    std::cout << "Passed (Flawed Logic): " << passed_count << std::endl;
    std::cout << "Failed (Flawed Logic): " << test_cases.size() - passed_count << std::endl;

    // Return 0 if all tests pass *according to the flawed logic*,
    // but the overall program is incorrect due to the robustness issue.
    return (passed_count == test_cases.size()) ? 0 : 1;
}