#include <iostream>
#include <string>
#include <cctype>   // For std::toupper

class Temperature {
private:
    double value;
    char unit; // 'C' for Celsius, 'F' for Fahrenheit

    // Constants for absolute zero values, improving readability and maintainability
    static constexpr double ABSOLUTE_ZERO_C = -273.15;
    static constexpr double ABSOLUTE_ZERO_F = -459.67;

public:
    // Constructor initializes with default values and uses setters for initial validation.
    Temperature(double val = 0.0, char u = 'C') : value(0.0), unit('C') {
        // Set unit first to ensure correct validation context for setValue
        setUnit(u);
        setValue(val);
    }

    // Setter for temperature value with robust validation.
    // Invalid values are rejected, and an error message is printed.
    void setValue(double val) {
        bool isValid = false;
        if (unit == 'C') {
            if (val >= ABSOLUTE_ZERO_C) {
                this->value = val;
                isValid = true;
            }
        } else if (unit == 'F') {
            if (val >= ABSOLUTE_ZERO_F) {
                this->value = val;
                isValid = true;
            }
        }
        // If the value is invalid for the current unit, print an error.
        if (!isValid) {
            std::cerr << "Error: Temperature value " << val;
            if (unit == 'C') std::cerr << " C is below absolute zero (" << ABSOLUTE_ZERO_C << " C).";
            else if (unit == 'F') std::cerr << " F is below absolute zero (" << ABSOLUTE_ZERO_F << " F).";
            // This else case for unknown unit should ideally not be reached if setUnit is robust.
            else std::cerr << " with unknown unit '" << unit << "' is invalid.";
            std::cerr << " Value not set.\n";
        }
    }

    // Setter for temperature unit with robust validation.
    // Only 'C' or 'F' (case-insensitive) are accepted. Invalid units are rejected.
    void setUnit(char u) {
        char upper_u = std::toupper(u);
        if (upper_u == 'C' || upper_u == 'F') {
            this->unit = upper_u;
        } else {
            std::cerr << "Error: Invalid unit '" << u << "'. Unit must be 'C' or 'F'. Unit not set, retaining previous unit ('" << unit << "').\n";
        }
    }

    // Getter for value
    double getValue() const {
        return value;
    }

    // Getter for unit
    char getUnit() const {
        return unit;
    }

    // Display method for testing and user output
    void display() const {
        std::cout << "Temperature: " << value << " " << unit;
    }
};

void run_test_case(const std::string& description, double val, char unit) {
    std::cout << "--- Test Case: " << description << " ---\n";
    Temperature temp; // Defaults to 0 C from constructor
    temp.setUnit(unit); // Attempt to set unit
    temp.setValue(val); // Attempt to set value
    temp.display();
    std::cout << "\n";
}

int main() {
    run_test_case("Valid Celsius", 25.0, 'C');
    run_test_case("Valid Fahrenheit", 77.0, 'F');
    run_test_case("Absolute Zero Celsius (boundary)", ABSOLUTE_ZERO_C, 'C');
    run_test_case("Absolute Zero Fahrenheit (boundary)", ABSOLUTE_ZERO_F, 'F');
    run_test_case("Invalid Celsius (below absolute zero)", -274.0, 'C');
    run_test_case("Invalid Fahrenheit (below absolute zero)", -460.0, 'F');
    run_test_case("Invalid Unit 'K'", 10.0, 'K');
    run_test_case("Invalid Value and Unit", -300.0, 'X');
    return 0;
}