#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class TemperatureConverter {
private:
    double celsius;
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

    // Semantic Error: Attempting to access a private member 'celsius' directly from outside the class.
    // This will cause a compilation error.
    tc.celsius = 0.0; // This line violates access control

    // The following lines would demonstrate the intended functionality if the above error was fixed.
    // tc.setCelsius(0.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // tc.setCelsius(100.0);
    // std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // tc.setCelsius(25.0);
    // std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    return 0;
}