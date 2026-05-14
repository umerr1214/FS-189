#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits, though not directly used for handling here

int main() {
    double celsius;

    // Prompt user for input
    std::cout << "Enter temperature in Celsius: ";

    // Read input without validation.
    // If a non-numeric value is entered, std::cin will go into a fail state,
    // and 'celsius' will not be updated from its potentially uninitialized value.
    // The program will proceed with whatever value 'celsius' holds, leading to incorrect results.
    std::cin >> celsius; 

    // Perform the conversion calculation using the correct formula.
    // The issue here is purely input robustness, not the formula itself.
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0; 

    // Display the result, formatted to one decimal place.
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}