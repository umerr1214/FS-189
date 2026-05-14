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

    double discriminant = b * b - 4 * a * c;

    std::cout << std::fixed << std::setprecision(6); // For consistent output precision

    if (discriminant >= 0) {
        // Semantic error: If 'a' is 0, this will cause division by zero (resulting in Inf/NaN)
        // without explicitly handling it as a linear equation or an error.
        // The problem is about "quadratic equation", implying a != 0.
        // Applying the quadratic formula when a=0 is semantically incorrect.
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        if (discriminant == 0) {
            std::cout << "Real and equal roots: x1 = x2 = " << root1 << std::endl;
        } else {
            std::cout << "Real and distinct roots: x1 = " << root1 << ", x2 = " << root2 << std::endl;
        }
    } else {
        // Complex roots
        // Semantic error: If 'a' is 0, this will also cause division by zero.
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "Complex roots: x1 = " << realPart << " + " << imaginaryPart << "i, x2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }

    return 0;
}