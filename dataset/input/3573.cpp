#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision
#include <limits>  // Required for std::numeric_limits

int main() {
    // Use a more precise value for PI.
    const double PI = 3.141592653589793;
    double radius;

    std::cout << "Please enter the radius of the circle: ";
    
    // Robust input validation: ensure input is a number and positive.
    while (!(std::cin >> radius) || radius <= 0) {
        std::cout << "Radius must be a positive number.\n";
        std::cout << "Please enter a valid radius: ";
        std::cin.clear(); // Clear error flags
        // Discard invalid input from the buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Clear variable names for readability.
    double area = PI * radius * radius; // Efficient calculation for squaring.
    double perimeter = 2 * PI * radius;

    // Use std::fixed and std::setprecision for consistent and readable output.
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Calculated Area: " << area << "\n";
    std::cout << "Calculated Perimeter: " << perimeter << "\n";

    return 0;
}