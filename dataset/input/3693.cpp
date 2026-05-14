#include <iostream> // Required for input/output operations (std::cin, std::cout, std::cerr)
#include <cmath>    // Required for mathematical functions (std::sqrt)
#include <iomanip>  // Required for output formatting (std::fixed, std::setprecision)
#include <limits>   // Required for std::numeric_limits

// Define a struct Point with x and y (double) coordinates
struct Point {
    double x; // Clear, descriptive variable name for x-coordinate
    double y; // Clear, descriptive variable name for y-coordinate
};

int main() {
    Point point1, point2; // Clear, descriptive variable names for Point objects

    std::cout << "Enter coordinates for Point 1 (x y): ";
    // Robust input handling: Check if input operation was successful
    if (!(std::cin >> point1.x >> point1.y)) {
        std::cerr << "Error: Invalid input for Point 1. Please enter numeric values.\n";
        return 1; // Indicate an error by returning a non-zero status
    }

    std::cout << "Enter coordinates for Point 2 (x y): ";
    // Robust input handling: Check if input operation was successful
    if (!(std::cin >> point2.x >> point2.y)) {
        std::cerr << "Error: Invalid input for Point 2. Please enter numeric values.\n";
        return 1; // Indicate an error by returning a non-zero status
    }

    // Calculate differences in coordinates
    double dx = point2.x - point1.x;
    double dy = point2.y - point1.y;

    // Calculate Euclidean distance using direct multiplication for squaring (efficient)
    // and std::sqrt for the square root.
    double distance = std::sqrt(dx * dx + dy * dy);

    // Format output to a fixed number of decimal places for consistency and readability
    std::cout << std::fixed << std::setprecision(5);
    std::cout << "The Euclidean distance between the two points is: " << distance << std::endl;

    return 0; // Indicate successful execution
}