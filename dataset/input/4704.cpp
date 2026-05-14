#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;
    double fahrenheit_calculated = celsius * 9.0 / 5.0 + 32.0;
    // Semantic error: The correctly calculated double result is explicitly truncated
    // to an integer before printing, losing any fractional precision.
    int fahrenheit_display = static_cast<int>(fahrenheit_calculated);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit_display << std::endl;
    return 0;
}