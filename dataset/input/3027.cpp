#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Temperature {
private:
    double celsius; // Stores temperature in Celsius

    // Define conversion constants for clarity and efficiency
    static constexpr double FAHRENHEIT_OFFSET = 32.0;
    static constexpr double CELSIUS_TO_FAHRENHEIT_FACTOR = 9.0 / 5.0; // 1.8
    static constexpr double FAHRENHEIT_TO_CELSIUS_FACTOR = 5.0 / 9.0; // ~0.55555...

public:
    // Default constructor
    Temperature(double c = 0.0) : celsius(c) {}

    // setCelsius(double c) - Sets the temperature in Celsius
    void setCelsius(double c) {
        this->celsius = c;
    }

    // getCelsius() - Returns the temperature in Celsius
    double getCelsius() const { // Use const for getter methods
        return this->celsius;
    }

    // setFahrenheit(double f) - Sets the temperature in Fahrenheit, converts to Celsius for storage
    void setFahrenheit(double f) {
        this->celsius = (f - FAHRENHEIT_OFFSET) * FAHRENHEIT_TO_CELSIUS_FACTOR;
    }

    // getFahrenheit() - Returns the temperature in Fahrenheit, converting from stored Celsius
    double getFahrenheit() const { // Use const for getter methods
        return this->celsius * CELSIUS_TO_FAHRENHEIT_FACTOR + FAHRENHEIT_OFFSET;
    }
};

// Helper function to run a test case and print results
void run_test(const std::string& description, double initial_c, double expected_c_after_set_c, double expected_f_after_set_c, double initial_f, double expected_c_after_set_f, double expected_f_after_set_f) {
    std::cout << "--- Test: " << description << " ---\n";
    Temperature temp;

    std::cout << "Setting Celsius to " << std::fixed << std::setprecision(2) << initial_c << std::endl;
    temp.setCelsius(initial_c);
    std::cout << "getCelsius(): " << std::fixed << std::setprecision(2) << temp.getCelsius() << " C (Expected: " << expected_c_after_set_c << " C)\n";
    std::cout << "getFahrenheit(): " << std::fixed << std::setprecision(2) << temp.getFahrenheit() << " F (Expected: " << expected_f_after_set_c << " F)\n";

    std::cout << "Setting Fahrenheit to " << std::fixed << std::setprecision(2) << initial_f << std::endl;
    temp.setFahrenheit(initial_f);
    std::cout << "getCelsius(): " << std::fixed << std::setprecision(2) << temp.getCelsius() << " C (Expected: " << expected_c_after_set_f << " C)\n";
    std::cout << "getFahrenheit(): " << std::fixed << std::setprecision(2) << temp.getFahrenheit() << " F (Expected: " << expected_f_after_set_f << " F)\n";
    std::cout << std::endl;
}

int main() {
    // Test Case 1: Freezing point
    run_test("Freezing Point", 0.0, 0.00, 32.00, 32.0, 0.00, 32.00);

    // Test Case 2: Boiling point
    run_test("Boiling Point", 100.0, 100.00, 212.00, 212.0, 100.00, 212.00);

    // Test Case 3: Room temperature
    run_test("Room Temperature", 25.0, 25.00, 77.00, 77.0, 25.00, 77.00);

    // Test Case 4: Negative temperature (equal C and F)
    run_test("Negative Temperature (-40)", -40.0, -40.00, -40.00, -40.0, -40.00, -40.00);

    // Test Case 5: Absolute Zero
    run_test("Absolute Zero", -273.15, -273.15, -459.67, -459.67, -273.15, -459.67);

    return 0;
}