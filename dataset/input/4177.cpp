#include <iostream>
#include <cmath>
#include <iomanip> // For std::fixed, std::setprecision
#include <string> // For std::string

// Function containing the core logic, accepting istream and ostream for testability
void solve_quadratic_equation(std::istream& in, std::ostream& out) {
    double a, b, c;

    out << "Enter coefficients a, b, and c: ";
    in >> a >> b >> c;

    double discriminant = b * b - 4 * a * c;

    out << std::fixed << std::setprecision(2);

    // Robustness Issue: Does not handle the case where 'a' is zero,
    // which would lead to division by zero (2*a) and incorrect NaN/Inf results.
    // It assumes a quadratic equation even if 'a' is zero.
    if (discriminant > 0) {
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        // Ensure root1 >= root2 for consistent output comparison
        if (root1 < root2) std::swap(root1, root2);
        out << "Roots are real and distinct. Root 1 = " << root1 << ", Root 2 = " << root2 << std::endl;
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        out << "Roots are real and equal. Root 1 = " << root << ", Root 2 = " << root << std::endl;
    } else { // discriminant < 0
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        out << "Roots are complex. Root 1 = " << realPart << " + " << imaginaryPart << "i, Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }
}

int main() {
    solve_quadratic_equation(std::cin, std::cout);
    return 0;
}