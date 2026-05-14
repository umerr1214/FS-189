#include <iostream>
#include <string>
#include <cctype> // For std::toupper

class Temperature {
private:
    double value;
    char unit; // 'C' for Celsius, 'F' for Fahrenheit

public:
    // Constructor initializes with default values.
    // Robustness issue: constructor doesn't fully validate, relies on setters.
    Temperature(double val = 0.0, char u = 'C') : value(val) {
        this->unit = std::toupper(u);
        if (this->unit != 'C' && this->unit != 'F') {
            // In a robust system, this would explicitly reject or set a default with warning.
            // Here, for robustness issue, we just default to 'C' without explicit warning.
            this->unit = 'C';
        }
    }

    // Setter for value with robustness issue: allows setting invalid values.
    void setValue(double val) {
        if (unit == 'C') {
            if (val < -273.15) {
                // Robustness issue: Prints a warning but still sets the invalid value.
                std::cerr << "Robustness Warning: Celsius value " << val << " is below absolute zero (-273.15 C). Setting value anyway.\n";
            }
        } else if (unit == 'F') {
            if (val < -459.67) {
                // Robustness issue: Prints a warning but still sets the invalid value.
                std::cerr << "Robustness Warning: Fahrenheit value " << val << " is below absolute zero (-459.67 F). Setting value anyway.\n";
            }
        } else {
            // Robustness issue: If unit is invalid (due to setUnit's robustness issue),
            // this code attempts to validate assuming 'C', leading to potentially incorrect validation or state.
            std::cerr << "Robustness Warning: Unknown unit '" << unit << "'. Assuming Celsius for absolute zero check. Setting value anyway.\n";
            if (val < -273.15) {
                std::cerr << "(Assumed C) Value " << val << " is below absolute zero. Setting value anyway.\n";
            }
        }
        this->value = val; // The core robustness issue: setting the invalid value.
    }

    // Setter for unit with robustness issue: allows setting invalid units.
    void setUnit(char u) {
        u = std::toupper(u); // Normalize to uppercase
        if (u != 'C' && u != 'F') {
            // Robustness issue: Prints a warning but still sets the invalid unit.
            std::cerr << "Robustness Warning: Invalid unit '" << u << "'. Setting unit anyway, which might lead to inconsistent state.\n";
        }
        this->unit = u; // The core robustness issue: setting the invalid unit.
    }

    // Getter for value
    double getValue() const {
        return value;
    }

    // Getter for unit
    char getUnit() const {
        return unit;
    }

    // Display method for testing
    void display() const {
        std::cout << "Temperature: " << value << " " << unit;
    }
};

void run_test_case(const std::string& description, double val, char unit) {
    std::cout << "--- Test Case: " << description << " ---\n";
    Temperature temp; // Defaults to 0 C
    temp.setUnit(unit); // Set unit first (may set invalid unit due to robustness issue)
    temp.setValue(val); // Then set value (validation depends on potentially invalid unit)
    temp.display();
    std::cout << "\n";
}

int main() {
    run_test_case("Valid Celsius", 25.0, 'C');
    run_test_case("Valid Fahrenheit", 77.0, 'F');
    run_test_case("Invalid Celsius (below absolute zero)", -274.0, 'C');
    run_test_case("Invalid Fahrenheit (below absolute zero)", -460.0, 'F');
    run_test_case("Invalid Unit 'K'", 10.0, 'K');
    run_test_case("Invalid Value and Unit", -300.0, 'X');
    return 0;
}