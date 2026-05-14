#include <iostream>
#include <iomanip> // Needed for std::fixed and std::setprecision

int main() {
    float celsius;
    float fahrenheit;

    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    // Semantic Error: The program calculates fahrenheit correctly, but prints 'celsius' instead of 'fahrenheit'.
    std::cout << "Temperature in Fahrenheit: " << std::fixed << std::setprecision(1) << celsius << std::endl;

    return 0;
}