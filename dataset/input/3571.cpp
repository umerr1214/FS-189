#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    const double PI = 3.14159;
    double radius;

    std::cout << "Enter radius: ";
    std::cin >> radius;

    // Robustness Issue: No validation for negative or zero radius.
    // Calculations will proceed, leading to physically meaningless results
    // (e.g., negative perimeter) for negative input, or zero for zero input.
    // The program doesn't handle this edge case gracefully.

    double area = PI * radius * radius;
    double perimeter = 2 * PI * radius;

    std::cout << "Area: " << std::fixed << std::setprecision(5) << area << "\n";
    std::cout << "Perimeter: " << std::fixed << std::setprecision(5) << perimeter << "\n";

    return 0;
}