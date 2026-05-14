#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

class Temperature {
private:
    double currentCelsiusValue; // Less descriptive name

public:
    // Constructor
    Temperature(double val = 0.0) : currentCelsiusValue(val) {} // Less descriptive parameter name

    // Method to set Celsius value.
    void setCelsius(double c_val) { // Slightly less descriptive parameter name
        currentCelsiusValue = c_val;
    }

    // Method to get Fahrenheit value with readability/efficiency issues.
    double getFahrenheit() {
        // This calculation is overly verbose and uses unnecessary temporary variables,
        // making it less readable and potentially less efficient than a direct calculation.
        const double five_units = 5.0;
        const double nine_units = 9.0;
        const double base_offset = 32.0;

        double conversion_factor_numerator = nine_units;
        double conversion_factor_denominator = five_units;

        double calculated_ratio = conversion_factor_numerator / conversion_factor_denominator;

        double intermediate_product = currentCelsiusValue * calculated_ratio;

        double final_temperature_in_fahrenheit = intermediate_product + base_offset;

        return final_temperature_in_fahrenheit;
    }
};

int main() {
    std::ostringstream oss;
    Temperature temp;

    // Test cases
    std::vector<double> testCelsius = {0.0, 100.0, 25.0, -40.0, -273.15};

    for (double c : testCelsius) {
        temp.setCelsius(c);
        oss << std::fixed << std::setprecision(2) << temp.getFahrenheit() << "\n";
    }

    std::cout << oss.str();

    return 0;
}