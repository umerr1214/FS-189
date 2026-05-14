#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Temperature {
private:
    double celsius;

public:
    void setCelsius(double c) {
        celsius = c;
    }

    double getCelsius() {
        return celsius;
    }

    void setFahrenheit(double f) {
        celsius = (f - 32.0) * 5.0 / 9.0;
    }

    double getFahrenheit() {
        return celsius * 9.0 / 5.0 + 32.0;
    }
};

int main() {
    Temperature temp;

    // Set precision for output
    std::cout << std::fixed << std::setprecision(1);

    // Test Celsius setter and Fahrenheit getter
    temp.setCelsius(25.0);
    std::cout << "25.0 C is " << temp.getFahrenheit() << " F\n"; // Expected: 77.0

    // Semantic error: Attempting to access private member 'celsius' directly from main.
    // This violates encapsulation rules and will result in a compiler error.
    temp.celsius = 10.0; 

    // Test Fahrenheit setter and Celsius getter (these lines will not be reached if the semantic error causes compilation failure)
    // temp.setFahrenheit(68.0);
    // std::cout << "68.0 F is " << temp.getCelsius() << " C\n";

    return 0;
}