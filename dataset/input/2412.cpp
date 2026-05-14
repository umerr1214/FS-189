#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class Temperature {
public: // Semantic Error: celsiusValue should be private as per the question
    double celsiusValue;

public:
    void setCelsius(double c) {
        celsiusValue = c;
    }

    double getFahrenheit() {
        return celsiusValue * 1.8 + 32.0;
    }
};

int main() {
    Temperature temp;

    // Test Case 1
    temp.setCelsius(0.0);
    std::cout << std::fixed << std::setprecision(2) << temp.getFahrenheit() << std::endl;

    // Test Case 2
    temp.setCelsius(25.0);
    std::cout << std::fixed << std::setprecision(2) << temp.getFahrenheit() << std::endl;

    // Test Case 3
    temp.setCelsius(100.0);
    std::cout << std::fixed << std::setprecision(2) << temp.getFahrenheit() << std::endl;

    // Test Case 4
    temp.setCelsius(-10.0);
    std::cout << std::fixed << std::setprecision(2) << temp.getFahrenheit() << std::endl;

    return 0;
}