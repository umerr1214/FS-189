#include <iostream>
#include <iomanip> // Needed for std::fixed and std::setprecision

int main() {
    float celsius;
    float fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    // Syntax Error: Missing semicolon at the end of this line
    std::cout << "Temperature in Fahrenheit: " << std::fixed << std::setprecision(1) << fahrenheit << std::endl
    return 0;
}