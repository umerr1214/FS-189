#include <iostream>   // Required for input/output operations (std::cout, std::cin, std::endl)
#include <iomanip>    // Required for output formatting (std::fixed, std::setprecision)
#include <limits>     // Required for std::numeric_limits to clear input buffer

int main() {
    double celsius; // Declare a variable to store the temperature in Celsius

    // Loop to continuously prompt for input until a valid numeric value is entered
    while (true) {
        std::cout << "Enter temperature in Celsius: "; // Prompt the user for input
        std::cin >> celsius; // Attempt to read the input into the 'celsius' variable

        // Check if the input operation failed (e.g., user entered non-numeric data)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
            std::cin.clear(); // Clear the error flags on std::cin
            // Discard the invalid input from the buffer up to the newline character
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // If input was successful, break out of the loop
            break;
        }
    }

    // Calculate the temperature in Fahrenheit using the provided formula: F = C * 9/5 + 32
    // Use 9.0/5.0 to ensure floating-point division, otherwise 9/5 would result in integer 1.
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;

    // Set output precision to two decimal places for Fahrenheit temperature
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Temperature in Fahrenheit: " << fahrenheit << std::endl; // Print the result

    return 0; // Indicate successful program execution
}