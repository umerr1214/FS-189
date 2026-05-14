#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>   // For fabs

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
};

// Readability/Efficiency Issue:
// 1. Passes Complex object by value (inefficient copy).
// 2. The conditional logic for formatting the output is overly complex and could be simplified for better readability.
std::ostream& operator<<(std::ostream& os, Complex c) { // Pass by value - efficiency issue
    bool real_part_printed = false;

    if (c.real != 0.0 || (c.real == 0.0 && c.imaginary == 0.0)) { // Print real part if non-zero OR if imaginary is zero (to print "0" for Complex(0,0))
        os << c.real;
        real_part_printed = true;
    }

    if (c.imaginary != 0.0) {
        if (real_part_printed && c.imaginary > 0) {
            os << " + ";
        } else if (real_part_printed && c.imaginary < 0) {
            os << " - ";
        }
        // If real_part_printed is false, and imaginary is not zero, this is like "0 + 4i" -> "4i"
        // If real_part_printed is true, and imaginary is 0, this block is skipped.

        double abs_imaginary = std::fabs(c.imaginary); // Use abs for printing magnitude after sign
        if (abs_imaginary == 1.0) { // Handle "i" and "-i"
            os << "i";
        } else {
            if (!real_part_printed && c.imaginary < 0) { // For cases like Complex(0, -2) -> "-2i"
                os << "-";
            }
            os << abs_imaginary << "i";
        }
    } else if (!real_part_printed && c.real == 0.0) { // Case for Complex(0,0) specifically if real part was not printed
        os << "0"; // This condition is redundant given the first if, but kept for complexity
    }

    return os;
}

// Test driver
std::string run_test_cases() {
    std::stringstream ss_output;
    std::vector<Complex> complexes = {
        Complex(3, 4),
        Complex(5, -2),
        Complex(3, 0),
        Complex(0, 4),
        Complex(0, 0),
        Complex(3, 1),
        Complex(3, -1),
        Complex(0, 1),
        Complex(0, -1)
    };

    for (const auto& c : complexes) {
        ss_output << c << "\n";
    }
    return ss_output.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}