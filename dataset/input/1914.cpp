#include <iostream>

class Temperature {
private:
    double value;
    char unit; // This member is left uninitialized by the default constructor below

public:
    // SEMANTIC ERROR: Constructor does not initialize 'unit'
    Temperature() : value(0.0) {} // 'unit' is not initialized, will have a garbage value

    void setValue(double val) {
        // Accessing uninitialized 'unit' here leads to undefined behavior
        if (unit == 'C') {
            if (val >= -273.15) {
                value = val;
                std::cout << "Set value to " << val << " " << unit << std::endl;
            } else {
                std::cout << "Error: Temperature " << val << " " << unit << " is below absolute zero!" << std::endl;
            }
        } else if (unit == 'F') {
            if (val >= -459.67) {
                value = val;
                std::cout << "Set value to " << val << " " << unit << std::endl;
            } else {
                std::cout << "Error: Temperature " << val << " " << unit << " is below absolute zero!" << std::endl;
            }
        } else {
            // This path might be taken if 'unit' is neither 'C' nor 'F' (e.g., garbage)
            std::cout << "Error: Cannot set value, unit is invalid or uninitialized (char code: " << static_cast<int>(unit) << ")." << std::endl;
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
    Temperature temp; // 'unit' is uninitialized here

    std::cout << "--- Testing Temperature Class (Semantic Error) ---" << std::endl;

    // Test Case 1: Call setValue before setUnit. This accesses uninitialized 'unit'.
    // The output for 'unit' will be garbage or fall into the 'else' branch of setValue.
    temp.setValue(10.0);
    temp.printTemperature();

    std::cout << "--- Normal operation after initializing unit ---" << std::endl;
    // Test Case 2: Set unit and value correctly
    temp.setUnit('C');
    temp.setValue(25.0);
    temp.printTemperature();

    // Test Case 3: Invalid Celsius (below absolute zero)
    temp.setValue(-300.0);
    temp.printTemperature();

    // Test Case 4: Valid Fahrenheit
    temp.setUnit('F');
    temp.setValue(77.0);
    temp.printTemperature();

    return 0;
}