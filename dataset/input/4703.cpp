#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    double celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;
    // Logical error: 9/5 performs integer division, resulting in 1, not 1.8
    double fahrenheit = celsius * (9 / 5) + 32;
    std::cout << "Temperature in Fahrenheit: " << std::fixed << std::setprecision(1) << fahrenheit << std::endl;
    return 0;
}