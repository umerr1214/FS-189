#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class TemperatureConverter {
private:
    double celsius // Syntax Error: Missing semicolon here
public:
    void setCelsius(double c) {
        celsius = c;
    }

    double getFahrenheit() {
        return celsius * 1.8 + 32;
    }
};

int main() {
    TemperatureConverter tc;

    // Test Case 1
    tc.setCelsius(0.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // Test Case 2
    tc.setCelsius(100.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // Test Case 3
    tc.setCelsius(25.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    return 0;
}