#include <iostream>
#include <iomanip>

const double ABSOLUTE_ZERO_CELSIUS = -273.15;

class Temperature {
private:
    double celsius;

public:
    Temperature() : celsius(ABSOLUTE_ZERO_CELSIUS) {}
    Temperature(double c) {
        setCelsius(c);
    }

    void setCelsius(double c) {
        // LOGICAL ERROR: The validation logic is inverted.
        // If input 'c' is valid (>= absolute zero), it incorrectly sets 'celsius' to absolute zero.
        // If input 'c' is invalid (< absolute zero), it incorrectly sets 'celsius' to 'c'.
        if (c >= ABSOLUTE_ZERO_CELSIUS) {
            celsius = ABSOLUTE_ZERO_CELSIUS; // Should be 'celsius = c;'
        } else {
            celsius = c; // Should be 'celsius = ABSOLUTE_ZERO_CELSIUS;'
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

    Temperature t1; // Defaults to -273.15
    std::cout << "Default (Absolute Zero):\n";
    std::cout << "  Fahrenheit: " << t1.getFahrenheit() << "F\n";
    std::cout << "  Kelvin: " << t1.getKelvin() << "K\n";

    Temperature t2(25.0); // 25.0C is valid, but due to error, it will be set to ABSOLUTE_ZERO_CELSIUS
    std::cout << "\nSetting 25.0C (valid input, but logic error):\n";
    std::cout << "  Fahrenheit: " << t2.getFahrenheit() << "F\n";
    std::cout << "  Kelvin: " << t2.getKelvin() << "K\n";

    Temperature t3(-300.0); // -300.0C is invalid, but due to error, it will be set to -300.0
    std::cout << "\nSetting -300.0C (invalid input, but logic error):\n";
    std::cout << "  Fahrenheit: " << t3.getFahrenheit() << "F\n";
    std::cout << "  Kelvin: " << t3.getKelvin() << "K\n";

    return 0;
}