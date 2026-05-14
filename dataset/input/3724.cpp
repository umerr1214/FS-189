#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // The formula is F = C * 9/5 + 32
    // Missing semicolon here intentionally for Syntax Error
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}