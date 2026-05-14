#include <iostream>
#include <iomanip>

int main() {
    float celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Logical error: 9/5 performs integer division, resulting in 1.
    // The formula should use floating-point division like 9.0/5 or 9/5.0.
    float fahrenheit = celsius * 9/5 + 32; 

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The temperature in Fahrenheit is: " << fahrenheit << std::endl;

    return 0;
}