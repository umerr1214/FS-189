#include <iostream>
#include <iomanip>
#include <vector>

class TemperatureConverter {
private:
    double m_celsiusValue; // Slightly verbose member name, impacting readability

public:
    // Default constructor initializes celsius to a safe value
    TemperatureConverter() : m_celsiusValue(0.0) {}

    // Public method to set the Celsius temperature
    // Returns *this unnecessarily; the problem statement only requires setting the value.
    TemperatureConverter& setCelsius(double c) {
        m_celsiusValue = c;
        return *this; // Unnecessary return for the given problem scope
    }

    // Public method to get the Fahrenheit temperature
    // Explicitly uses 9.0 / 5.0, which, while correct, is less efficient/readable than using 1.8 directly.
    // Compilers might optimize constant division, but it's less explicit.
    double getFahrenheit() {
        return (m_celsiusValue * 9.0 / 5.0) + 32.0; // Recalculates 9.0/5.0 potentially on every call
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::vector<double> testCelsius = {25.0, 0.0, 100.0, -40.0, 37.0, -17.78};
    TemperatureConverter converter;

    for (double c : testCelsius) {
        // Call setCelsius, ignoring its return value as per problem requirements
        converter.setCelsius(c);
        std::cout << converter.getFahrenheit() << std::endl;
    }
    
    return 0;
}