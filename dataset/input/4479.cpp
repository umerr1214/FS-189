#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // Required for std::fixed, std::setprecision

// Function to convert Celsius to Fahrenheit
// Parameters:
//   celsius_temp: The temperature in Celsius to be converted.
// Returns:
//   The equivalent temperature in Fahrenheit.
double convertCelsiusToFahrenheit(double celsius_temp) {
    // Formula: F = C * 9/5 + 32
    // Use 9.0 / 5.0 to ensure floating-point division for accurate results.
    return celsius_temp * (9.0 / 5.0) + 32.0;
}

int user_main() {
    double celsius_temperature; // Clear and descriptive variable name
    
    // Prompt the user for input clearly
    std::cout << "Please enter the temperature in Celsius: ";
    
    // Robust input validation loop:
    // Ensures that the user enters a valid numeric value.
    // Clears error flags and discards invalid input from the buffer if input fails.
    while (!(std::cin >> celsius_temperature)) {
        std::cout << "Invalid input. Please enter a numeric value for Celsius: ";
        std::cin.clear(); // Clear the error flags on std::cin
        // Discard all remaining characters in the input buffer up to the newline
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Perform the conversion using the dedicated function
    double fahrenheit_temperature = convertCelsiusToFahrenheit(celsius_temperature);

    // Display the result clearly, with appropriate precision and context.
    // std::fixed and std::setprecision(1) ensure one decimal place for Fahrenheit.
    std::cout << std::fixed << std::setprecision(1); 
    std::cout << celsius_temperature << " Celsius is equivalent to " 
              << fahrenheit_temperature << " Fahrenheit." << std::endl;

    return 0;
}