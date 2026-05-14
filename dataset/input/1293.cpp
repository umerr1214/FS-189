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

// Correct Version: Handles all edge cases gracefully, is efficient (pass by const reference), and readable.
std::ostream& operator<<(std::ostream& os, const Complex& c) { // Pass by const reference - efficient
    if (c.real == 0.0 && c.imaginary == 0.0) {
        os << "0";
    } else if (c.imaginary == 0.0) {
        os << c.real;
    } else if (c.real == 0.0) {
        if (c.imaginary == 1.0) {
            os << "i";
        } else if (c.imaginary == -1.0) {
            os << "-i";
        } else {
            os << c.imaginary << "i";
        }
    } else { // Both real and imaginary parts are non-zero
        os << c.real;
        if (c.imaginary > 0) {
            os << " + ";
            if (c.imaginary == 1.0) {
                os << "i";
            } else {
                os << c.imaginary << "i";
            }
        } else { // c.imaginary < 0
            os << " - ";
            if (c.imaginary == -1.0) {
                os << "i";
            } else {
                os << std::fabs(c.imaginary) << "i"; // Print magnitude after '-'
            }
        }
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