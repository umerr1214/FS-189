#include <iostream>
#include <cmath>
#include <iomanip> // For std::fixed, std::setprecision
#include <string> // For std::string
#include <algorithm> // For std::swap

// Function containing the core logic, accepting istream and ostream for testability
void solve_quadratic_equation(std::istream& in, std::ostream& out) {
    double a, b, c;

    out << "Enter coefficients a, b, and c: ";
    in >> a >> b >> c;

    out << std::fixed << std::setprecision(2);

    if (a == 0) {
        // Handle the linear equation case: bx + c = 0
        if (b == 0) {
            if (c == 0) {
                out << "Coefficient 'a' is zero. This is a linear equation. Infinite solutions." << std::endl;
            } else {
                out << "Coefficient 'a' is zero. This is a linear equation. No real root." << std::endl;
            }
        } else {
            double root = -c / b;
            out << "Coefficient 'a' is zero. This is a linear equation. Root = " << root << std::endl;
        }
    } else {
        // It's a quadratic equation: ax^2 + bx + c = 0
        double discriminant = b * b - 4 * a * c;
        double two_a = 2 * a; // Calculate 2*a once for efficiency

        if (discriminant > 0) {
            double sqrt_discriminant = std::sqrt(discriminant); // Use std::sqrt
            double root1 = (-b + sqrt_discriminant) / two_a;
            double root2 = (-b - sqrt_discriminant) / two_a;
            // Ensure root1 >= root2 for consistent output
            if (root1 < root2) std::swap(root1, root2);
            out << "Roots are real and distinct. Root 1 = " << root1 << ", Root 2 = " << root2 << std::endl;
        } else if (discriminant == 0) {
            double root = -b / two_a;
            out << "Roots are real and equal. Root 1 = " << root << ", Root 2 = " << root << std::endl;
        } else { // discriminant < 0
            double realPart = -b / two_a;
            double imaginaryPart = std::sqrt(-discriminant) / two_a;
            out << "Roots are complex. Root 1 = " << realPart << " + " << imaginaryPart << "i, Root 2 = " << realPart << " - " << imaginaryPart << "i" << std::endl;
        }
    }
}

int main() {
    solve_quadratic_equation(std::cin, std::cout);
    return 0;
}