#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>
#include <limits> // For std::numeric_limits

class Temperature {
private:
    double celsiusValue;

public:
    // Constructor
    Temperature(double c = 0.0) : celsiusValue(c) {}

    // Method to set Celsius value.
    // This version does not validate input against physical constraints (e.g., absolute zero).
    void setCelsius(double c) {
        // A robust implementation might check for values below absolute zero (-273.15 C)
        // or handle NaN/infinity inputs more explicitly if required by application logic.
        // This version simply assigns, which is a robustness issue if physical validity is critical.
        celsiusValue = c;
    }

    // Method to get Fahrenheit value.
    double getFahrenheit() {
        return celsiusValue * 1.8 + 32.0;
    }
};

int main() {
    std::ostringstream oss;
    Temperature temp;

    // Test cases
    std::vector<double> testCelsius = {0.0, 100.0, 25.0, -40.0, -273.15}; // -273.15 is absolute zero

    for (double c : testCelsius) {
        temp.setCelsius(c);
        oss << std::fixed << std::setprecision(2) << temp.getFahrenheit() << "\n";
    }

    std::cout << oss.str();

    return 0;
}