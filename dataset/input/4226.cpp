#include <iostream>
#include <cmath>    // For std::atan, std::pow
#include <iomanip>  // For std::fixed, std::setprecision

// Function to calculate circle properties with readability/efficiency issues.
// - PI is calculated every time the function is called using std::atan(1.0) * 4.0, which is inefficient.
// - Uses std::pow(r, 2) which is slightly less efficient than r * r for squaring a double.
// - Uses less descriptive variable names (r, ar, circ).
void calculate_circle_properties(double r, double& ar, double& circ) {
    // Inefficient: PI is calculated repeatedly.
    const double PI_VAL = std::atan(1.0) * 4.0; 
    
    // Slightly less efficient than 'r * r' for squaring.
    ar = PI_VAL * std::pow(r, 2);
    circ = 2 * PI_VAL * r;
}

int main() {
    std::cout << std::fixed << std::setprecision(6);

    // Example 1: Standard positive radius
    double r1 = 5.0;
    double a1 = 0.0, c1 = 0.0;
    calculate_circle_properties(r1, a1, c1);
    std::cout << "Radius: " << r1 << ", Area: " << a1 << ", Circumference: " << c1 << std::endl;

    // Example 2: Another positive radius
    double r2 = 10.0;
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