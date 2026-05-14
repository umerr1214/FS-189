#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Temperature {
private:
    double celsius; // Stores temperature in Celsius

public:
    // Default constructor
    Temperature(double c = 0.0) : celsius(c) {}

    // setCelsius(double c)
    void setCelsius(double c) {
        this->celsius = c;
    }

    // getCelsius()
    double getCelsius() const {
        return this->celsius;
    }

    // setFahrenheit(double f)
    // Robustness Issue: Using a truncated constant 0.5555 for 5.0/9.0
    // This will lead to slight inaccuracies when setting Fahrenheit values.
    void setFahrenheit(double f) {
        this->celsius = (f - 32.0) * 0.5555; // Subtle precision error here
    }

    // getFahrenheit()
    double getFahrenheit() const {
        return this->celsius * (9.0 / 5.0) + 32.0; // This uses the correct factor, amplifying the previous error
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
    run_test("Boiling Point", 100.0, 100.00, 212.00, 212.0, 99.99, 211.98);

    // Test Case 3: Room temperature
    run_test("Room Temperature", 25.0, 25.00, 77.00, 77.0, 25.00, 76.99);

    // Test Case 4: Negative temperature (equal C and F)
    run_test("Negative Temperature (-40)", -40.0, -40.00, -40.00, -40.0, -40.00, -39.99);

    // Test Case 5: Absolute Zero
    run_test("Absolute Zero", -273.15, -273.15, -459.67, -459.67, -273.12, -459.62);

    return 0;
}