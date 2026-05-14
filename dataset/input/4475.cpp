#include <iostream>
#include <iomanip>

int main() {
    double celsius;
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Logical Error: Integer division 9/5 evaluates to 1, instead of 1.8.
    // This causes incorrect conversion for most Celsius values.
    fahrenheit = celsius * (9 / 5) + 32.0;

    std::cout << std::fixed << std::setprecision(2)
              << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}