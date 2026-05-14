#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits

int main() {
    // Define PI as a constant for accuracy and clarity
    const double PI = 3.14159;
    double radius;
    double volume;

    // Prompt user for input
    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    // Input validation: Check if input was successful (numeric)
    if (std::cin.fail()) {
        std::cerr << "Invalid input. Please enter a numeric value for the radius." << std::endl;
        // Clear error flags and ignore remaining input in the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1; // Indicate an error
    }

    // Input validation: Check for non-negative radius
    if (radius < 0) {
        std::cerr << "Invalid radius. The radius cannot be negative." << std::endl;
        return 1; // Indicate an error
    }

    // Calculate volume using the formula V = (4/3) * PI * r^3
    // Use 4.0/3.0 to ensure floating-point division
    volume = (4.0 / 3.0) * PI * radius * radius * radius;

    // Display the result, formatted to two decimal places
    std::cout << "The volume of the sphere is: " << std::fixed << std::setprecision(2) << volume << std::endl;

    return 0;
}