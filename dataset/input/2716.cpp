#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

const double ABSOLUTE_ZERO_CELSIUS = -273.15;

class Temperature {
private:
    double celsius;

public:
    // Constructor
    Temperature() : celsius(ABSOLUTE_ZERO_CELSIUS) {}
    Temperature(double c) {
        setCelsius(c);
    }

    // Set method with validation
    void setCelsius(double c) {
        if (c >= ABSOLUTE_ZERO_CELSIUS) {
            celsius = c;
        } else {
            // If input is less than absolute zero, clamp it to absolute zero
            celsius = ABSOLUTE_ZERO_CELSIUS;
        }
    }

    // Get Fahrenheit
    double getFahrenheit() const {
        return (celsius * 9.0 / 5.0) + 32.0;
    }

    // Get Kelvin
    double getKelvin() const {
        return celsius + 273.15;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::cout << std::fixed << std::setprecision(2);

    Temperature t1;
    t1.setCelsius(25.0);
    std::cout << "25C is " << t1.getFahrenheit() << "F and " << t1.getKelvin() << "K\n";

    Temperature t2(-300.0); // Invalid input, should be clamped to absolute zero
    std::cout << "-300C (invalid) is " << t2.getFahrenheit() << "F and " << t2.getKelvin() << "K\n";

    Temperature t3(0.0);
    std::cout << "0C is " << t3.getFahrenheit() << "F and " << t3.getKelvin() << "K\n";

    return 0;
}