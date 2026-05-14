#include <iostream>
#include <cmath>    // For M_PI
#include <iomanip>  // For std::fixed, std::setprecision

// Function to calculate circle properties.
// This version does not validate input for radius.
// If radius is negative, area will be positive (radius*radius),
// but circumference will be negative, which is mathematically nonsensical for a physical circle.
void calculate_circle_properties(double radius, double& area, double& circumference) {
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

    // Example 2: Negative radius, demonstrating the robustness issue
    double r2 = -2.5;
    double a2 = 0.0, c2 = 0.0;
    calculate_circle_properties(r2, a2, c2);
    std::cout << "Radius: " << r2 << ", Area: " << a2 << ", Circumference: " << c2 << std::endl;
    
    // Example 3: Zero radius
    double r3 = 0.0;
    double a3 = 0.0, c3 = 0.0;
    calculate_circle_properties(r3, a3, c3);
    std::cout << "Radius: " << r3 << ", Area: " << a3 << ", Circumference: " << c3 << std::endl;

    return 0;
}