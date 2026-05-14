#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // Constant for Pi
    const double p = 3.14159; // Poor variable name for PI
    double r; // Poor variable name for radius

    // Prompt for input
    std::cout << "Enter radius: "; // Abbreviated prompt
    std::cin >> r;

    // Calculate area
    double a = p * r * r; // Poor variable name for area

    // Print the area with inconsistent formatting and magic number for precision
    std::cout << "Result: " << std::fixed << std::setprecision(2) << a << std::endl;

    // No comments, inconsistent indentation in places (though minor for this short code)

    return 0;
}