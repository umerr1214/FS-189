#include <iostream>
#include <iomanip>
#include <vector>

class TemperatureConverter {
private:
    double celsius; // Private member to store temperature in Celsius

public:
    // Constructor initializes celsius to a default safe value
    TemperatureConverter() : celsius(0.0) {}

    // Public method to set the Celsius temperature
    void setCelsius(double c) {
        celsius = c;
    }

    // Public method to get the Fahrenheit temperature
    // Uses the pre-calculated constant 1.8 for efficiency and readability
    double getFahrenheit() {
        // Formula: F = C * 1.8 + 32
        return celsius * 1.8 + 32.0;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    std::vector<double> testCelsius = {25.0, 0.0, 100.0, -40.0, 37.0, -17.78};
    TemperatureConverter converter;

    for (double c : testCelsius) {
        converter.setCelsius(c);
        std::cout << converter.getFahrenheit() << std::endl;
    }

    return 0;
}