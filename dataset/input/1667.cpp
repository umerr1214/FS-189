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
        // Logical Error: Integer division 9/5 results in 1, not 1.8
        return celsius * 9 / 5 + 32;
    }
};

int main() {
    TemperatureConverter tc;

    // Test Case 1: C=0 -> F=32.0 (correct by chance due to 0 * 1 + 32)
    tc.setCelsius(0.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // Test Case 2: C=100 -> Expected F=212.0, Actual F=100*1+32 = 132.0
    tc.setCelsius(100.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    // Test Case 3: C=25 -> Expected F=77.0, Actual F=25*1+32 = 57.0
    tc.setCelsius(25.0);
    std::cout << std::fixed << std::setprecision(1) << tc.getFahrenheit() << std::endl;

    return 0;
}