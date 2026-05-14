#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits

// Function containing the main logic for the correct version
int _user_main_function_3879() {
    double celsius;
    double fahrenheit;

    std::cout << "Enter temperature in Celsius: ";

    // Robust input validation loop
    while (!(std::cin >> celsius)) {
        std::cout << "Invalid input. Please enter a numeric value for Celsius: ";
        std::cin.clear(); // Clear the error flags
        // Discard invalid input up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Formula: F = C * 9/5 + 32
    // Use 9.0/5.0 to ensure floating-point division for accurate results
    fahrenheit = celsius * (9.0 / 5.0) + 32.0;

    std::cout << std::fixed << std::setprecision(2)
              << "Temperature in Fahrenheit: " << fahrenheit << std::endl;

    return 0;
}

int main() {
    return _user_main_function_3879();
}