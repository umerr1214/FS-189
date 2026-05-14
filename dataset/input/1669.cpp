#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream> // For std::ostringstream in the main function's output logic

class TemperatureConverter {
private:
    double celsius; // Private member to store temperature in Celsius.
                    // NOT initialized by a constructor, leading to undefined behavior
                    // if getFahrenheit() is called before setCelsius().

public:
    // No explicit constructor provided, so the default constructor will not
    // initialize 'celsius' to a specific value.

    // Public method to set the Celsius temperature
    void setCelsius(double c) {
        celsius = c;
    }

    // Public method to get the Fahrenheit temperature
    double getFahrenheit() {
        // If 'celsius' has not been set via setCelsius(), its value is indeterminate,
        // leading to undefined behavior when used in this calculation.
        return celsius * 1.8 + 32.0;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    // --- Robustness Issue Demonstration ---
    TemperatureConverter tc_robust;
    std::cout << "--- Robustness Issue Test (getFahrenheit before setCelsius) ---" << std::endl;
    // Calling getFahrenheit here without prior setCelsius() will use an uninitialized 'celsius'
    // leading to undefined behavior. The output might be garbage, a crash, or seemingly valid but wrong.
    std::cout << "Initial Fahrenheit (before setCelsius): " << tc_robust.getFahrenheit() << std::endl;
    std::cout << "Expected: Undefined behavior: Accessing uninitialized 'celsius' member. Output value is unpredictable." << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl << std::endl;


    // --- Standard Test Cases (where setCelsius is called, so behavior is defined) ---
    std::vector<double> testCelsius = {25.0, 0.0, 100.0, -40.0};
    TemperatureConverter converter; // This object will be used correctly.

    std::cout << "--- Standard Test Cases (setCelsius is called) ---" << std::endl;
    for (double c : testCelsius) {
        converter.setCelsius(c);
        std::cout << "Celsius: " << c << " -> Fahrenheit: " << converter.getFahrenheit() << std::endl;
    }

    return 0;
}