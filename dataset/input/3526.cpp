#include <iostream>
#include <iomanip> // For setprecision

int main() {
    float celsius;
    std::cout << "Enter temperature in Celsius: " // Syntax error: Missing semicolon
    std::cin >> celsius;

    float fahrenheit = celsius * 9.0/5 + 32;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The temperature in Fahrenheit is: " << fahrenheit << std::endl;

    return 0;
}