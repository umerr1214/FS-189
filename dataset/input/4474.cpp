#include <iostream>
#include <iomanip>

int main() {
    double celsius;
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: " // Syntax Error: Missing semicolon
    std::cin >> celsius;

    fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    std::cout << std::fixed << std::setprecision(2)
              << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}