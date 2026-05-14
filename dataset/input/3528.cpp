#include <iostream>
#include <iomanip>

int main() {
    float celsius;
    std::cout << "Enter temperature in Celsius: ";
    std::cin >> celsius;

    // Semantic error: The result of the floating-point calculation is stored in an 'int' variable,
    // causing truncation and loss of precision, which is a misinterpretation of "print the result"
    // for a temperature conversion that typically expects floating-point output.
    int fahrenheit_int; 
    fahrenheit_int = celsius * 9.0/5 + 32; // Calculation is correct, but assignment to int truncates

    std::cout << std::fixed << std::setprecision(1); // These manipulators will have no effect on int output
    std::cout << "The temperature in Fahrenheit is: " << fahrenheit_int << std::endl;

    return 0;
}