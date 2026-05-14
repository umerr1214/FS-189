#include <iostream>
#include <limits>   // Required for std::numeric_limits
#include <iomanip>  // Required for std::fixed and std::setprecision

// Helper function to clear input buffer in case of invalid input
void clearInputBuffer() {
    std::cin.clear(); // Clear error flags
    // Ignore all characters in the buffer up to the newline
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main() {
    int choice;
    double temperature;
    bool validInput = false; // Flag to control input loops

    std::cout << "=== Temperature Conversion Program ===\n";

    // Loop until a valid choice (1 or 2) is entered
    while (!validInput) {
        std::cout << "\nChoose conversion type:\n";
        std::cout << "1. Celsius to Fahrenheit\n";
        std::cout << "2. Fahrenheit to Celsius\n";
        std::cout << "Enter your choice (1 or 2): ";
        
        std::cin >> choice; // Attempt to read choice

        if (std::cin.fail()) { // Check if input operation failed (e.g., non-numeric input)
            std::cout << "Invalid input type. Please enter a number (1 or 2).\n";
            clearInputBuffer(); // Clear error and buffer
        } else if (choice < 1 || choice > 2) { // Check if choice value is out of range
            std::cout << "Invalid choice. Please enter 1 or 2.\n";
            clearInputBuffer(); // Clear any potential extra characters on the line
        } else {
            validInput = true; // Valid choice received, exit loop
            clearInputBuffer(); // Clear any remaining characters on the line
        }
    }

    validInput = false; // Reset flag for temperature input

    // Loop until a valid numeric temperature is entered
    while (!validInput) {
        if (choice == 1) {
            std::cout << "Enter temperature in Celsius: ";
        } else { // choice == 2
            std::cout << "Enter temperature in Fahrenheit: ";
        }
        
        std::cin >> temperature; // Attempt to read temperature

        if (std::cin.fail()) { // Check for non-numeric input
            std::cout << "Invalid input type. Please enter a numeric value for temperature.\n";
            clearInputBuffer(); // Clear error and buffer
        } else {
            validInput = true; // Valid temperature received, exit loop
            clearInputBuffer(); // Clear any remaining characters on the line
        }
    }

    // Set output precision for temperature values
    std::cout << std::fixed << std::setprecision(2);

    // Perform the selected conversion and display the result
    if (choice == 1) {
        double fahrenheit = temperature * 9.0 / 5.0 + 32.0;
        std::cout << temperature << " Celsius is " << fahrenheit << " Fahrenheit.\n";
    } else { // choice == 2
        double celsius = (temperature - 32.0) * 5.0 / 9.0;
        std::cout << temperature << " Fahrenheit is " << celsius << " Celsius.\n";
    }

    std::cout << "======================================\n";

    return 0;
}