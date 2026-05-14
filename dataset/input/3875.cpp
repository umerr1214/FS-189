#include <iostream>
#include <iomanip> // Needed for std::fixed and std::setprecision

int main() {
    float celsius;
    float fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Logical Error: Integer division 9/5 evaluates to 1, not 1.8
    fahrenheit = celsius * (9/5) + 32;

    std::cout << "Temperature in Fahrenheit: " << std::fixed << std::setprecision(1) << fahrenheit << std::endl;

    return 0;
}