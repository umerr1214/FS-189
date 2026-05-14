#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

class Temperature {
private:
    double celsiusValue;

public:
    // Constructor initializes celsiusValue
    Temperature(double c = 0.0) : celsiusValue(c) {}

    // Public method to set the Celsius value
    void setCelsius(double c) {
        celsiusValue = c;
    }

    // Public method to get the Fahrenheit value, converting Celsius to Fahrenheit
    double getFahrenheit() {
        // Formula: F = C * 9/5 + 32, or F = C * 1.8 + 32
        return celsiusValue * 1.8 + 32.0;
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