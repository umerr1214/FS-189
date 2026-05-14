#include <iostream> // Required for input/output operations (std::cout, std::cin, std::cerr)
#include <iomanip>  // Required for output formatting (std::fixed, std::setprecision)
#include <limits>   // Required for std::numeric_limits (used for robust input handling)

int main() {
    double celsiusTemperature; // Declare a variable to store the temperature in Celsius

    // Prompt the user to enter the temperature in Celsius
    std::cout << "Please enter the temperature in Celsius: ";

    // Read the input from the user with robust validation
    if (!(std::cin >> celsiusTemperature)) {
        // If input fails (e.g., non-numeric input), an error message is displayed
        std::cerr << "Invalid input. Please enter a numeric value for temperature." << std::endl;
        
        // Clear the error flags on std::cin and ignore remaining invalid input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        return 1; // Indicate that the program terminated with an error
    }

    // Define constants for the conversion formula for clarity and maintainability
    const double FAHRENHEIT_SCALE_FACTOR = 9.0 / 5.0; // The scaling factor (1.8)
    const double FAHRENHEIT_OFFSET = 32.0;          // The offset for Fahrenheit

    // Perform the conversion calculation using the defined constants
    double fahrenheitTemperature = celsiusTemperature * FAHRENHEIT_SCALE_FACTOR + FAHRENHEIT_OFFSET;

    // Display the result, formatted to one decimal place for readability
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "The temperature " << celsiusTemperature << " Celsius is equivalent to " 
              << fahrenheitTemperature << " Fahrenheit." << std::endl;

    return 0; // Indicate successful program execution
}