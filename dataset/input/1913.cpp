#include <iostream>

class Temperature {
private:
    double value;
    char unit;

public:
    Temperature() : value(0.0), unit('C') {}

    void setValue(double val) {
        if (unit == 'C') {
            if (val >= -273.15) {
                value = val;
                std::cout << "Set value to " << val << " " << unit << std::endl;
            } else {
                std::cout << "Error: Temperature " << val << " " << unit << " is below absolute zero!" << std::endl;
            }
        } else if (unit == 'F') {
            // LOGICAL ERROR: Using Celsius absolute zero for Fahrenheit
            if (val >= -273.15) { // Should be -459.67 for Fahrenheit
                value = val;
                std::cout << "Set value to " << val << " " << unit << std::endl;
            } else {
                std::cout << "Error: Temperature " << val << " " << unit << " is below absolute zero!" << std::endl;
            }
        } else {
            std::cout << "Error: Cannot set value, unit is invalid or uninitialized (" << unit << ")." << std::endl;
        }
    }

    void setUnit(char u) {
        if (u == 'C' || u == 'F') {
            unit = u;
            std::cout << "Set unit to " << u << std::endl;
        } else {
            std::cout << "Error: Invalid unit '" << u << "'. Must be 'C' or 'F'." << std::endl;
        }
    }

    double getValue() const { return value; }
    char getUnit() const { return unit; }

    void printTemperature() const {
        std::cout << "Current Temperature: " << value << " " << unit << std::endl;
    }
};

int main() {
    Temperature temp;

    std::cout << "--- Testing Temperature Class (Logical Error) ---" << std::endl;

    // Test Case 1: Valid Celsius
    temp.setUnit('C');
    temp.setValue(25.0);
    temp.printTemperature();

    // Test Case 2: Invalid Celsius (below absolute zero)
    temp.setValue(-300.0);
    temp.printTemperature();

    // Test Case 3: Valid Fahrenheit
    temp.setUnit('F');
    temp.setValue(77.0);
    temp.printTemperature();

    // Test Case 4: Invalid Fahrenheit (e.g., -400 F) - this should be rejected but will pass due to the error
    temp.setValue(-400.0); // -400 F is below absolute zero (-459.67 F), but above -273.15 F
    temp.printTemperature();

    // Test Case 5: Fahrenheit below -273.15 (will correctly be rejected even with the error)
    temp.setValue(-500.0);
    temp.printTemperature();

    // Test Case 6: Invalid unit
    temp.setUnit('K');
    temp.printTemperature();

    return 0;
}