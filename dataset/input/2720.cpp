#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <string>  // For std::string

// Readability/Efficiency Issue:
// - No constructor, relies on default initialization.
// - Verbose and inconsistent naming conventions.
// - Use of magic numbers instead of named constants.
// - Lack of const correctness on getter methods.
// - Redundant code/logic.

class TempClass { // Unclear and generic class name
private:
    double my_internal_celsius_value; // Verbose member name

public:
    // No constructor provided. `my_internal_celsius_value` will be default-initialized to 0.0
    // for objects of this class, which is a valid temperature, but it's not explicitly set.

    // Public method to set Celsius temperature with validation
    // Verbose name, uses magic number, redundant else
    bool set_the_celsius_temperature_value(double the_new_celsius_input) {
        double absolute_zero_c_local = -273.15; // Magic number, re-declared on every call
        if (the_new_celsius_input < absolute_zero_c_local) {
            std::cout << "ERROR: Input value " << the_new_celsius_input << " C is too cold! Must be >= " << absolute_zero_c_local << " C.\n"; // Using cout for error output
            return false;
        } else { // Redundant else block
            my_internal_celsius_value = the_new_celsius_input;
            return true;
        }
    }

    // Public method to get Celsius temperature (no const correctness)
    double get_current_celsius_value() {
        return my_internal_celsius_value;
    }

    // Public method to get Fahrenheit temperature (no const correctness, uses magic numbers)
    double get_fahrenheit_temperature() {
        double fahrenheit_multiplier_val = 9.0;
        double fahrenheit_divisor_val = 5.0;
        double fahrenheit_offset_val = 32.0; // Magic numbers
        return (my_internal_celsius_value * (fahrenheit_multiplier_val / fahrenheit_divisor_val)) + fahrenheit_offset_val;
    }

    // Public method to get Kelvin temperature (no const correctness, uses magic number)
    double get_kelvin_temperature() {
        double kelvin_conversion_offset = 273.15; // Magic number
        return my_internal_celsius_value + kelvin_conversion_offset;
    }
};

// Driver function to run test cases and display results for the Readability/Efficiency version
void run_test_readability(TempClass& temp_obj, double input_c, const std::string& test_desc) {
    std::cout << "--- " << test_desc << " ---\n";
    std::cout << "Trying to set Celsius to: " << input_c << " C\n";
    if (temp_obj.set_the_celsius_temperature_value(input_c)) {
        std::cout << "Temperature set OK.\n";
    } else {
        std::cout << "Setting temperature failed. Internal state remains unchanged.\n";
    }
    std::cout << "Current state of TempClass:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Celsius:    " << temp_obj.get_current_celsius_value() << " C\n";
    std::cout << "  Fahrenheit: " << temp_obj.get_fahrenheit_temperature() << " F\n";
    std::cout << "  Kelvin:     " << temp_obj.get_kelvin_temperature() << " K\n";
    std::cout << "\n";
}

int main() {
    TempClass my_temperature_instance; // Default initializes my_internal_celsius_value to 0.0

    // Explicitly setting an initial valid temperature as there's no constructor
    my_temperature_instance.set_the_celsius_temperature_value(0.0); // Ensures a known starting point

    // Test Case 1: Valid temperature
    run_test_readability(my_temperature_instance, 25.0, "Valid temp test (Room Temp)");

    // Test Case 2: Absolute Zero
    run_test_readability(my_temperature_instance, -273.15, "Absolute Zero test");

    // Test Case 3: Invalid low temperature (should fail and keep previous value)
    run_test_readability(my_temperature_instance, -300.0, "Invalid low temp test");

    // Test Case 4: Another valid temperature
    run_test_readability(my_temperature_instance, 100.0, "Another valid temp test (Boiling Point)");

    // Test Case 5: Slightly too low (should fail and keep previous value)
    run_test_readability(my_temperature_instance, -273.16, "Slightly too low test");

    return 0;
}