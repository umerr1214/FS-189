#include <iostream>
#include <iomanip>

const double ABSOLUTE_ZERO_CELSIUS = -273.15;

class Temperature {
private:
    double celsius;

public:
    // SEMANTIC ERROR: Default constructor does not initialize 'celsius'.
    // 'celsius' will contain a garbage value when Temperature() is used,
    // leading to undefined behavior when its value is accessed.
    Temperature() {
        // 'celsius' is uninitialized here.
        // It should be: celsius = ABSOLUTE_ZERO_CELSIUS; or use an initializer list:
        // Temperature() : celsius(ABSOLUTE_ZERO_CELSIUS) {}
    }
    
    Temperature(double c) {
        setCelsius(c);
    }

    void setCelsius(double c) {
        if (c >= ABSOLUTE_ZERO_CELSIUS) {
            celsius = c;
        } else {
            celsius = ABSOLUTE_ZERO_CELSIUS;
        }
    }

    double getFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    double getKelvin() const {
        return celsius + 273.15;
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Temperature t1; // Calls default constructor, 'celsius' is uninitialized
    std::cout << "Default Temperature (uninitialized celsius):\n";
    std::cout << "  Fahrenheit: " << t1.getFahrenheit() << "F\n"; // Will output garbage
    std::cout << "  Kelvin: " << t1.getKelvin() << "K\n";       // Will output garbage

    Temperature t2(25.0); // This constructor initializes via setCelsius, so it should work correctly
    std::cout << "\nTemperature set to 25.0C:\n";
    std::cout << "  Fahrenheit: " << t2.getFahrenheit() << "F (Expected: 77.00F)\n";
    std::cout << "  Kelvin: " << t2.getKelvin() << "K (Expected: 298.15K)\n";

    Temperature t3(-300.0); // Invalid input, should be set to absolute zero
    std::cout << "\nTemperature set to -300.0C (invalid input):\n";
    std::cout << "  Fahrenheit: " << t3.getFahrenheit() << "F (Expected: -459.67F)\n";
    std::cout << "  Kelvin: " << t3.getKelvin() << "K (Expected: 0.00K)\n";

    return 0;
}