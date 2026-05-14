#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Temperature {
private:
    double celsius;

public:
    void setCelsius(double c) {
        celsius = c;
    }

    double getCelsius() {
        return celsius;
    }

    void setFahrenheit(double f) {
        // Logical error: 5/9 performs integer division, resulting in 0.
        // It should be 5.0/9.0 or (double)5/9 to perform floating-point division.
        celsius = (f - 32.0) * (5/9);
    }

    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    Temperature temp;

    // Set precision for output
    std::cout << std::fixed << std::setprecision(1);

    // Test Celsius setter and Fahrenheit getter (should be correct)
    std::cout << "--- Testing C to F (correct) ---\n";
    temp.setCelsius(25.0);
    std::cout << "25.0 C is " << temp.getFahrenheit() << " F\n"; // Expected: 77.0
    temp.setCelsius(0.0);
    std::cout << "0.0 C is " << temp.getFahrenheit() << " F\n"; // Expected: 32.0
    temp.setCelsius(-10.0);
    std::cout << "-10.0 C is " << temp.getFahrenheit() << " F\n"; // Expected: 14.0

    // Test Fahrenheit setter and Celsius getter (will be incorrect due to logical error)
    std::cout << "\n--- Testing F to C (incorrect) ---\n";
    temp.setFahrenheit(68.0);
    std::cout << "68.0 F is " << temp.getCelsius() << " C\n"; // Expected: 20.0, Actual: 0.0
    temp.setFahrenheit(212.0);
    std::cout << "212.0 F is " << temp.getCelsius() << " C\n"; // Expected: 100.0, Actual: 0.0

    return 0;
}