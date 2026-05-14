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

    // Readability/Efficiency Issue: Repetitive calculations and less efficient pow for square root
    if (a == 0) { // This part correctly handles the linear case
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
        double discriminant_val = b * b - 4 * a * c; // Calculate discriminant once
        
        // Redundant calculations of (2*a) and using pow instead of sqrt
        if (discriminant_val > 0) {
            double common_denominator = 2 * a; // Calculate 2*a once
            double sqrt_of_discriminant = std::pow(discriminant_val, 0.5); // Using pow instead of std::sqrt

            double root_one = (-b + sqrt_of_discriminant) / common_denominator;
            double root_two = (-b - sqrt_of_discriminant) / common_denominator;

            // Ensure root1 >= root2 for consistent output comparison
            if (root_one < root_two) std::swap(root_one, root_two);
            out << "Roots are real and distinct. Root 1 = " << root_one << ", Root 2 = " << root_two << std::endl;
        } else if (discriminant_val == 0) {
            double common_denominator = 2 * a; // Calculated again
            double single_root = -b / common_denominator;
            out << "Roots are real and equal. Root 1 = " << single_root << ", Root 2 = " << single_root << std::endl;
        } else { // discriminant_val < 0
            double common_denominator = 2 * a; // Calculated again
            double real_part_val = -b / common_denominator;
            double imag_part_val = std::pow(-discriminant_val, 0.5) / common_denominator; // Using pow again

            out << "Roots are complex. Root 1 = " << real_part_val << " + " << imag_part_val << "i, Root 2 = " << real_part_val << " - " << imag_part_val << "i" << std::endl;
        }
    }
}

int main() {
    solve_quadratic_equation(std::cin, std::cout);
    return 0;
}