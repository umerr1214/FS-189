#include <iostream>
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision

// Define M_PI if it's not present (some compilers might require _USE_MATH_DEFINES)
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Correct and efficient function to calculate circle properties.
// Uses M_PI constant and direct multiplication for squaring.
// Assumes a non-negative radius for meaningful results as per typical geometry context.
void calculate_circle_properties(double radius, double& area, double& circumference) {
    // For a truly robust solution, one might add input validation here,
    // e.g., if (radius < 0) { area = 0; circumference = 0; return; }
    // However, the question focuses on calculation, and for valid geometric circles, radius >= 0.
    
    area = M_PI * radius * radius;
    circumference = 2 * M_PI * radius;
}

int main() {
    std::cout << std::fixed << std::setprecision(6);

    // Example 1: Standard positive radius
    double r1 = 5.0;
    double a1 = 0.0, c1 = 0.0;
    calculate_circle_properties(r1, a1, c1);
    std::cout << "Radius: " << r1 << ", Area: " << a1 << ", Circumference: " << c1 << std::endl;

    // Example 2: Zero radius (edge case)
    double r2 = 0.0;
    double a2 = 0.0, c2 = 0.0;
    calculate_circle_properties(r2, a2, c2);
    std::cout << "Radius: " << r2 << ", Area: " << a2 << ", Circumference: " << c2 << std::endl;

    // Example 3: Another positive radius
    double r3 = 10.0;
    double a3 = 0.0, c3 = 0.0;
    calculate_circle_properties(r3, a3, c3);
    std::cout << "Radius: " << r3 << ", Area: " << a3 << ", Circumference: " << c3 << std::endl;
    
    return 0;
}