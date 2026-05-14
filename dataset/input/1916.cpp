#include <iostream>
#include <string>
#include <cctype> // For std::toupper

class Temperature {
private:
    double v; // Cryptic variable name for value
    char u;   // Cryptic variable name for unit

public:
    // Constructor - poorly formatted and uses verbose checks
    Temperature(double val = 0.0, char unit_char = 'C') {
        v = val;
        // Verbose and slightly inefficient unit check
        if (unit_char == 'c' || unit_char == 'C' ) {
            u = 'C';
        } else if (unit_char == 'f' || unit_char == 'F' ) {
            u = 'F';
        } else {
            // Default to 'C' if invalid, but without clear feedback
            u = 'C';
        }
    }

    // Setter for value - uses magic numbers and verbose conditional logic
    void setValue(double val) {
        if (u == 'C') {
            if (val >= -273.15) { // Magic number for Celsius absolute zero
                v = val;
            } else {
                std::cerr << "Error: Celsius value " << val << " is below absolute zero (-273.15 C). Value not set.\n";
            }
        } else if (u == 'F') {
            if (val >= -459.67) { // Magic number for Fahrenheit absolute zero
                v = val;
            } else {
                std::cerr << "Error: Fahrenheit value " << val << " is below absolute zero (-459.67 F). Value not set.\n";
            }
        } else {
            // Redundant check/fallback if setUnit correctly prevents invalid units.
            // Contributes to inefficiency and reduced readability.
            std::cerr << "Error: Unknown unit. Assuming Celsius for validation. Value " << val << " is below absolute zero (-273.15 C). Value not set.\n";
        }
    }

    // Setter for unit - overly complex and nested if-else if structure
    void setUnit(char unit_char) {
        char processed_unit = std::toupper(unit_char);
        if (processed_unit == 'C') {
            u = 'C';
        } else { // Unnecessary nesting
            if (processed_unit == 'F') {
                u = 'F';
            } else {
                std::cerr << "Error: Invalid unit '" << unit_char << "'. Unit not set, retaining previous unit (" << u << ").\n";
            }
        }
    }

    // Getter for value
    double getValue() const {
        return v;
    }

    // Getter for unit
    char getUnit() const {
        return u;
    }

    // Display method
    void display() const {
        std::cout << "Current Temp: " << v << " " << u;
    }
};

void run_test_case(const std::string& description, double val, char unit) {
    std::cout << "--- Test Case: " << description << " ---\n";
    Temperature temp; // Defaults to 0 C
    temp.setUnit(unit); // Set unit first
    temp.setValue(val); // Then set value
    temp.display();
    std::cout << "\n";
}

int main() {
    run_test_case("Valid Celsius", 25.0, 'C');
    run_test_case("Valid Fahrenheit", 77.0, 'F');
    run_test_case("Absolute Zero Celsius (boundary)", -273.15, 'C');
    run_test_case("Invalid Celsius (below absolute zero)", -274.0, 'C');
    run_test_case("Invalid Fahrenheit (below absolute zero)", -460.0, 'F');
    run_test_case("Invalid Unit 'K'", 10.0, 'K');
    run_test_case("Invalid Value and Unit", -300.0, 'X');
    return 0;
}