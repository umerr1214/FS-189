#include <iostream>
#include <cmath> // For sqrt
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double a, b, c;

    std::cout << "Enter coefficient a: ";
    std::cin >> a;

    std::cout << "Enter coefficient b: ";
    std::cin >> b;

    std::cout << "Enter coefficient c: " // SYNTAX ERROR: Missing semicolon
    std::cin >> c;

    double discriminant = b * b - 4 * a * c;

    std::cout << std::fixed << std::setprecision(6); // For consistent output precision

    if (discriminant >= 0) {
        if (a == 0) { // Special case for linear equation or not a quadratic
            if (b == 0) {
                if (c == 0) {
                    std::cout << "Infinite solutions (0=0)." << std::endl;
                } else {
                    std::cout << "No solution." << std::endl;
                }
            } else {
                double x = -c / b;
                std::cout << "Linear equation. Root: x = " << x << std::endl;
            }
        } else {
            double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
            double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
            if (discriminant == 0) {
                std::cout << "Real and equal roots: x1 = x2 = " << root1 << std::endl;
            } else {
                std::cout << "Real and distinct roots: x1 = " << root1 << ", x2 = " << root2 << std::endl;
            }
        }
    } else {
        // Complex roots
        // This path is only taken if a != 0 in a properly functioning program,
        // as discriminant calculation for a=0, b=0, c!=0 would be 0, not negative.
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Complex roots: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }

    return 0;
}