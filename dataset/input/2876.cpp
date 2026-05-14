#include <iostream>
#include <string>
#include <cmath> // For std::abs
#include <sstream> // For std::stringstream
#include <iomanip> // For std::fixed, std::setprecision

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend declaration for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Readability / Efficiency Issue:
// This implementation correctly formats the complex number according to
// conventional mathematical representation (e.g., (3 - 5i) for (3, -5),
// (3) for (3, 0), (5i) for (0, 5)).
// However, it uses std::stringstream to build the output string, which
// is less efficient than directly writing to the std::ostream.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    std::stringstream ss;
    ss.precision(15); // Match main's precision for double output consistency
    ss << std::fixed;

    ss << "(";
    bool real_printed = false;

    // Handle real part
    if (c.real != 0.0 || c.imag == 0.0) { // Print real if non-zero, or if it's a purely real number (e.g., (3) or (0))
        ss << c.real;
        real_printed = true;
    }

    // Handle imaginary part
    if (c.imag != 0.0) {
        if (real_printed) { // If real part was printed, add +/-
            if (c.imag > 0) {
                ss << " + ";
            } else { // c.imag < 0
                ss << " - ";
            }
            ss << std::abs(c.imag) << "i";
        } else { // Purely imaginary number (e.g., (5i))
            ss << c.imag << "i";
        }
    } else if (!real_printed) { // Case for Complex(0,0) -> (0)
        ss << "0";
    }

    ss << ")";
    return os << ss.str();
}

int main() {
    std::cout.precision(15); // Ensure consistent double output for comparison
    std::cout << std::fixed;

    Complex c1(3, 5);
    Complex c2(3, -5);
    Complex c3(3, 0);
    Complex c4(0, 5);
    Complex c5(0, -5);
    Complex c6(0, 0);
    Complex c7(-3, 5);
    Complex c8(-3, -5);

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    std::cout << c5 << std::endl;
    std::cout << c6 << std::endl;
    std::cout << c7 << std::endl;
    std::cout << c8 << std::endl;

    return 0;
}