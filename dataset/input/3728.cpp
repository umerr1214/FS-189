#include <iostream>
#include <iomanip>

int main() {
    double c; // Variable for Celsius temperature. Poorly named.
    std::cout << "Enter temperature in Celsius: "; // Prompt for user input.
    std::cin >> c; // Read input from the user.

    // Calculate Fahrenheit temperature using the conversion formula.
    // No comments explain the formula or its components.
    double f = c * 9.0 / 5.0 + 32.0; 

    // Display the result. Uses excessive precision, making the output less readable.
    std::cout << "Temperature in Fahrenheit: " << std::fixed << std::setprecision(10) << f << std::endl;
    return 0; // Indicate successful program execution.
}