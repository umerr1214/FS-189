#include <iostream>
#include <cmath> // For sqrt
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double a, b, c;

    std::cout << "Enter coefficient a: ";
    std::cin >> a;

    std::cout << "Enter coefficient b: ";
    std::cin >> b;

    std::cout << "Enter coefficient c: ";
    std::cin >> c;

    // Logical error: Incorrect discriminant calculation (should be 4*a*c)
    double discriminant = b * b - 2 * a * c; // This should be b*b - 4*a*c

    std::cout << std::fixed << std::setprecision(6); // For consistent output precision

    if (discriminant >= 0) {
        // This code path will correctly handle a=0 as a linear equation *if* discriminant is 0,
        // but the discriminant itself is calculated incorrectly.
        // Also, if a=0, this would lead to division by zero, but the primary error is the discriminant.
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        if (discriminant == 0) {
            std::cout << "Real and equal roots: x1 = x2 = " << root1 << std::endl;
        } else {
            std::cout << "Real and distinct roots: x1 = " << root1 << ", x2 = " << root2 << std::endl;
        }
    } else {
        // Complex roots
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Complex roots: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }

    return 0;
}