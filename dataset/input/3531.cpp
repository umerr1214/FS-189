#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

int main() {
    float celsiusTemperature; // Descriptive variable name

    std::cout << "Please enter the temperature in Celsius: "; // Clear prompt
    std::cin >> celsiusTemperature;

    // Robust input validation
    if (std::cin.fail()) {
        std::cerr << "Error: Invalid input. Please enter a numeric value." << std::endl;
        // Clear the error flags and ignore the rest of the line to allow further input attempts if this were a loop
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate error
    }

    // Correct formula with floating-point literals for precision
    float fahrenheitTemperature = celsiusTemperature * 9.0F / 5.0F + 32.0F;

    // Print result with clear message and formatted to two decimal places
    std::cout << std::fixed << std::setprecision(2)
              << "The temperature " << celsiusTemperature << " Celsius is equivalent to "
              << fahrenheitTemperature << " Fahrenheit." << std::endl;

    return 0;
}