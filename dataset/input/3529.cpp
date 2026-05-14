#include <iostream>
#include <iomanip> // For std::fixed, std::setprecision

int main() {
    float celsius = 0.0F; // Initialized to 0.0F. If input fails, this value is used.
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius; // No check for input failure, robustness issue

    float fahrenheit = celsius * 9.0F / 5.0F + 32.0F;

    std::cout << std::fixed << std::setprecision(2) << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}