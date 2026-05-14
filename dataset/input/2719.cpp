#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <string>  // For std::string

class Temperature {
private:
    double celsius;
    // Define absolute zero as a constant
    static constexpr double ABSOLUTE_ZERO_CELSIUS = -273.15;

public:
    // Constructor: Initializes temperature with an initial value.
    // Calls setCelsius, which has the robustness flaw.
    Temperature(double initialCelsius = 0.0) {
        setCelsius(initialCelsius); // This call also has the robustness issue
    }

    // Public method to set Celsius temperature with validation.
    // Robustness Issue: If input is invalid, it prints an error but still updates
    // the internal 'celsius' member, corrupting the object's state.
    bool setCelsius(double newCelsius) {
        if (newCelsius < ABSOLUTE_ZERO_CELSIUS) {
            std::cerr << "Warning: Input temperature " << newCelsius << " C is below absolute zero ("
                      << ABSOLUTE_ZERO_CELSIUS << " C). Setting value anyway, but this may lead to invalid conversions.\n";
            this->celsius = newCelsius; // The robustness flaw: updates with invalid data
            return false; // Indicates failure, but state is corrupted
        }
        this->celsius = newCelsius;
        return true;
    }

    // Public method to get Celsius temperature (useful for testing)
    double getCelsius() const {
        return celsius;
    }

    // Public method to get Fahrenheit temperature
    double getFahrenheit() const {
        return celsius * (9.0 / 5.0) + 32.0;
    }

    // Public method to get Kelvin temperature
    double getKelvin() const {
        return celsius + 273.15;
    }
};

// Driver function to run test cases and display results
void run_test(Temperature& temp, double celsius_input, const std::string& description) {
    std::cout << "--- " << description << " ---\n";
    std::cout << "Attempting to set Celsius to: " << celsius_input << " C\n";
    if (temp.setCelsius(celsius_input)) {
        std::cout << "Temperature set successfully.\n";
    } else {
        std::cout << "Failed to set temperature (input invalid or warning issued). Note: internal state might be invalid.\n";
    }
    std::cout << "Current Temperature:\n";
    std::cout << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    std::cout << "  Celsius:    " << temp.getCelsius() << " C\n";
    std::cout << "  Fahrenheit: " << temp.getFahrenheit() << " F\n";
    std::cout << "  Kelvin:     " << temp.getKelvin() << " K\n";
    std::cout << "\n";
}

int main() {
    // Initialize Temperature object. Constructor calls setCelsius.
    Temperature t(0.0); // Starts at 0.0 C

    // Test Case 1: Valid temperature (room temperature)
    run_test(t, 25.0, "Valid Temperature (Room Temp)");

    // Test Case 2: Absolute Zero
    run_test(t, -273.15, "Absolute Zero");

    // Test Case 3: Temperature below absolute zero (invalid input, shows robustness issue)
    run_test(t, -300.0, "Below Absolute Zero (Invalid Input - Robustness Issue)");

    // Test Case 4: Another valid temperature (boiling point)
    run_test(t, 100.0, "Valid Temperature (Boiling Point)");

    // Test Case 5: Slightly below absolute zero (invalid input, shows robustness issue)
    run_test(t, -273.16, "Slightly Below Absolute Zero (Invalid Input - Robustness Issue)");

    return 0;
}