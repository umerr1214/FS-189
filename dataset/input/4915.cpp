#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision
#include <limits>  // For std::numeric_limits

int main() {
    const double PI = 3.14159;
    double radius = 0.0; // Initialize radius for predictable behavior on invalid input
    double volume;

    std::cout << "Enter the radius of the sphere: ";
    std::cin >> radius;

    // Robustness issue: No check for invalid input (e.g., non-numeric).
    // If input fails, radius remains 0.0, and the stream is in a fail state.
    // No explicit handling for negative radius values, which result in a negative volume.

    volume = (4.0 / 3.0) * PI * radius * radius * radius;

    std::cout << "The volume of the sphere is: " << std::fixed << std::setprecision(2) << volume << std::endl;

    return 0;
}