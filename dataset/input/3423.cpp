#define _USE_MATH_DEFINES // Required for M_PI on some compilers (e.g., MSVC)
#include <iostream>
#include <cmath> // For M_PI
#include <iomanip> // For std::fixed, std::setprecision
#include <limits> // For std::numeric_limits

// Define M_PI as a fallback if _USE_MATH_DEFINES and cmath don't provide it,
// strictly adhering to the specified fallback value.
#ifndef M_PI
#define M_PI 3.14159
#endif

// Core logic wrapped in a function to allow for a simple driver in JSON
void solve() {
    double radius; // Use meaningful variable name
    std::cout << "Enter the radius of the circle (e.g., 5.0): ";

    // Robust input validation loop: checks for valid numeric input and non-negative radius
    while (!(std::cin >> radius) || radius < 0) {
        std::cout << "Invalid input. Please enter a non-negative numeric value for the radius: ";
        std::cin.clear(); // Clear error flags
        // Discard invalid input from the buffer up to the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Calculations
    double area = M_PI * radius * radius;
    double circumference = 2 * M_PI * radius;

    // Output results with consistent formatting and clear labels
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Calculated Area: " << area << std::endl;
    std::cout << "Calculated Circumference: " << circumference << std::endl;
}

int main() {
    solve();
    return 0;
}