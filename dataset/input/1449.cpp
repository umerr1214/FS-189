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
    // Marked as const as it does not modify the object's state
    double getFahrenheit() const {
        // Correct and concise conversion using floating-point literals
        return celsius * (9.0 / 5.0) + 32.0;
    }
};

struct TestCase {
    double input_celsius;
    double expected_fahrenheit;
};

int main() {
    std::vector<TestCase> test_cases = {
        {0.0, 32.0},
        {20.0, 68.0},
        {-10.0, 14.0},
        {100.0, 212.0},
        {37.0, 98.6}, // Body temperature
        {-40.0, -40.0} // Point where Celsius and Fahrenheit are equal
    };

    std::cout << std::fixed << std::setprecision(1);

    int passed_count = 0;
    for (size_t i = 0; i < test_cases.size(); ++i) {
        Temperature temp(test_cases[i].input_celsius);
        double actual_fahrenheit = temp.getFahrenheit();
        
        // Using a small epsilon for floating-point comparison
        if (std::abs(actual_fahrenheit - test_cases[i].expected_fahrenheit) < 0.001) {
            std::cout << "Test Case " << i + 1 << " Passed: "
                      << test_cases[i].input_celsius << " C -> "
                      << actual_fahrenheit << " F (Expected: "
                      << test_cases[i].expected_fahrenheit << " F)" << '\n'; // Using '\n' for efficiency
            passed_count++;
        } else {
            std::cout << "Test Case " << i + 1 << " FAILED: "
                      << test_cases[i].input_celsius << " C -> "
                      << actual_fahrenheit << " F (Expected: "
                      << test_cases[i].expected_fahrenheit << " F)" << '\n';
        }
    }

    std::cout << "\n--- Test Summary ---" << '\n';
    std::cout << "Total Tests: " << test_cases.size() << '\n';
    std::cout << "Passed: " << passed_count << '\n';
    std::cout << "Failed: " << test_cases.size() - passed_count << '\n';

    return (passed_count == test_cases.size()) ? 0 : 1;
}