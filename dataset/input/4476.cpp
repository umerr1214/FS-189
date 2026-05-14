#include <iostream>
#include <iomanip>

int main() {
    double celsius;
    // Semantic Error: The Fahrenheit temperature, after being calculated as a double,
    // is explicitly cast to an integer, causing a loss of precision.
    // The program will only display whole numbers for Fahrenheit.
    int fahrenheit_display;
    double fahrenheit_calculated;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    fahrenheit_calculated = celsius * 9.0 / 5.0 + 32.0;
    fahrenheit_display = static_cast<int>(fahrenheit_calculated); // Loss of precision here

    std::cout << "Temperature in Fahrenheit: " << fahrenheit_display << std::endl;

    return 0;
}