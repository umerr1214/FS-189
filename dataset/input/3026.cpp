#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class TemperatureMeasurementUnitHandler {
private:
    double m_internalCelsiusValue; // Stores temperature in Celsius

public:
    // Default constructor
    TemperatureMeasurementUnitHandler(double initial_celsius_val = 0.0) : m_internalCelsiusValue(initial_celsius_val) {}

    // setCelsius(double c)
    void setCelsius(double input_celsius_temperature) {
        this->m_internalCelsiusValue = input_celsius_temperature;
    }

    // getCelsius()
    double retrieveCelsiusValue() const {
        return this->m_internalCelsiusValue;
    }

    // setFahrenheit(double f)
    // Readability/Efficiency Issue: Repetitive calculations, no constants, unnecessary temporary variable
    void setFahrenheit(double inputFahrenheitTemperature) {
        double tempCelsiusConversionResult = (inputFahrenheitTemperature - 32.0) * (5.0 / 9.0); // Calculation of 5.0/9.0 repeated
        this->m_internalCelsiusValue = tempCelsiusConversionResult;
    }

    // getFahrenheit()
    // Readability/Efficiency Issue: Repetitive calculations, no constants
    double obtainFahrenheitValue() const {
        double currentCelsius = this->m_internalCelsiusValue;
        return currentCelsius * (9.0 / 5.0) + 32.0; // Calculation of 9.0/5.0 repeated
    }
};

// Helper function to run a test case and print results
void run_test(const std::string& description, double initial_c, double expected_c_after_set_c, double expected_f_after_set_c, double initial_f, double expected_c_after_set_f, double expected_f_after_set_f) {
    std::cout << "--- Test: " << description << " ---\n";
    TemperatureMeasurementUnitHandler temp;

    std::cout << "Setting Celsius to " << std::fixed << std::setprecision(2) << initial_c << std::endl;
    temp.setCelsius(initial_c);
    std::cout << "getCelsius(): " << std::fixed << std::setprecision(2) << temp.retrieveCelsiusValue() << " C (Expected: " << expected_c_after_set_c << " C)\n";
    std::cout << "getFahrenheit(): " << std::fixed << std::setprecision(2) << temp.obtainFahrenheitValue() << " F (Expected: " << expected_f_after_set_c << " F)\n";

    std::cout << "Setting Fahrenheit to " << std::fixed << std::setprecision(2) << initial_f << std::endl;
    temp.setFahrenheit(initial_f);
    std::cout << "getCelsius(): " << std::fixed << std::setprecision(2) << temp.retrieveCelsiusValue() << " C (Expected: " << expected_c_after_set_f << " C)\n";
    std::cout << "getFahrenheit(): " << std::fixed << std::setprecision(2) << temp.obtainFahrenheitValue() << " F (Expected: " << expected_f_after_set_f << " F)\n";
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