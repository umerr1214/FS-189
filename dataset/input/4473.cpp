#include <iostream>
#include <limits> // Required for std::numeric_limits
#include <iomanip> // Required for std::fixed and std::setprecision

int main() {
    // Define a constant for Pi with high precision
    const double PI = 3.14159265358979323846;
    double radius;

    // Loop until valid positive radius is entered
    while (true) {
        std::cout << "Please enter the radius of the circle: ";
        std::cin >> radius;

        // Check if input failed (e.g., non-numeric input)
        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a numeric value for the radius." << std::endl;
            std::cin.clear(); // Clear the error flag
            // Discard invalid input from the buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Check if radius is non-positive
        else if (radius <= 0) {
            std::cout << "Radius must be a positive number. Please try again." << std::endl;
        }
        // Valid input received, break the loop
        else {
            break;
        }
    }

    // Calculate the area
    double area = PI * radius * radius;

    // Print the area with clear formatting
    std::cout << std::fixed << std::setprecision(5); // Set precision for output
    std::cout << "The area of the circle with radius " << radius << " is: " << area << std::endl;

    return 0;
}