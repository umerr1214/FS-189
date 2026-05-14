#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <string>  // For std::string

class Temperature {
private:
    double celsius;
    // Define constants for absolute zero and conversion factors using static constexpr for good practice
    static constexpr double ABSOLUTE_ZERO_CELSIUS = -273.15;
    static constexpr double CELSIUS_TO_KELVIN_OFFSET = 273.15;
    static constexpr double FAHRENHEIT_MULTIPLIER = 9.0 / 5.0;
    static constexpr double FAHRENHEIT_OFFSET = 32.0;

public:
    // Constructor: Initializes temperature with validation.
    // Ensures the object is always in a valid state upon creation.
    Temperature(double initialCelsius = 0.0) : celsius(0.0) { // Initialize to a safe default (0.0 C)
        if (!setCelsius(initialCelsius)) {
            // If initial setting fails, log a warning, but the object remains in its safe default state.
            std::cerr << "Warning: Initial temperature " << initialCelsius << " C is invalid. Temperature set to default " << celsius << " C.\n";
        }
    }

    // Public method to set Celsius temperature with robust validation.
    // Returns true on success, false on failure. On failure, it does NOT change the internal state.
    bool setCelsius(double newCelsius) {
        if (newCelsius < ABSOLUTE_ZERO_CELSIUS) {
            std::cerr << "Error: Temperature " << newCelsius << " C is below absolute zero ("
                      << ABSOLUTE_ZERO_CELSIUS << " C). Value not set; current temperature remains unchanged.\n";
            return false;
        }
        this->celsius = newCelsius;
        return true;
    }

    // Public method to get Celsius temperature (const-correct)
    double getCelsius() const {
        return celsius;
    }

    // Public method to get Fahrenheit temperature (const-correct)
    double getFahrenheit() const {
        return celsius * FAHRENHEIT_MULTIPLIER + FAHRENHEIT_OFFSET;
    }

    // Public method to get Kelvin temperature (const-correct)
    double getKelvin() const {
        return celsius + CELSIUS_TO_KELVIN_OFFSET;
    }
};

// Driver function to run test cases and display results
void run_test_correct(Temperature& temp, double celsius_input, const std::string& description) {
    std::cout << "--- " << description << " ---\n";
    std::cout << "Attempting to set Celsius to: " << celsius_input << " C\n";
    if (temp.setCelsius(celsius_input)) {
        std::cout << "Temperature set successfully.\n";
    } else {
        std::cout << "Failed to set temperature (input invalid). Internal state remains unchanged.\n";
    }
    std::cout << "Current Temperature:\n";
    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    std::cout << "  Celsius:    " << temp.getCelsius() << " C\n";
    std::cout << "  Fahrenheit: " << temp.getFahrenheit() << " F\n";
    std::cout << "  Kelvin:     " << temp.getKelvin() << " K\n";
    std::cout << "\n";
}

int main() {
    // Initialize Temperature object with a valid value
    Temperature t(20.0); // Starts at 20.0 C

    // Test Case 1: Valid temperature (room temperature)
    run_test_correct(t, 25.0, "Valid Temperature (Room Temp)");

    // Test Case 2: Absolute Zero
    run_test_correct(t, -273.15, "Absolute Zero");

    // Test Case 3: Temperature below absolute zero (invalid input)
    // Should fail and keep the previous valid temperature (-273.15 C)
    run_test_correct(t, -300.0, "Below Absolute Zero (Invalid Input)");

    // Test Case 4: Another valid temperature (boiling point)
    run_test_correct(t, 100.0, "Valid Temperature (Boiling Point)");

    // Test Case 5: Slightly below absolute zero (invalid input)
    // Should fail and keep the previous valid temperature (100.0 C)
    run_test_correct(t, -273.16, "Slightly Below Absolute Zero (Invalid Input)");

    // Test Constructor with an invalid initial value
    std::cout << "--- Testing constructor with an invalid initial value ---\n";
    Temperature invalid_init_temp(-400.0); // Should trigger warning and default to 0.0 C
    std::cout << "After invalid constructor init, current temp:\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "  Celsius:    " << invalid_init_temp.getCelsius() << " C\n";
    std::cout << "  Fahrenheit: " << invalid_init_temp.getFahrenheit() << " F\n";
    std::cout << "  Kelvin:     " << invalid_init_temp.getKelvin() << " K\n";
    std::cout << "\n";

    return 0;
}