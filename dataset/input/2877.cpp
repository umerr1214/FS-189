#include <iostream>
#include <string>
#include <cmath> // For std::abs
#include <iomanip> // For std::fixed, std::setprecision

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend declaration for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Correct Version:
// This implementation correctly formats the complex number according to
// conventional mathematical representation (e.g., (3 - 5i) for (3, -5),
// (3) for (3, 0), (5i) for (0, 5)).
// It directly writes to the std::ostream, which is efficient and idiomatic C++.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    // Preserve stream state for precision and fixed, then restore
    std::ios_base::fmtflags old_flags = os.flags();
    std::streamsize old_prec = os.precision();
    os.precision(15);
    os << std::fixed;

    os << "(";
    bool real_printed = false;

    // Handle real part: print if non-zero, or if it's a purely real number (e.g., (3) or (0))
    if (c.real != 0.0 || c.imag == 0.0) {
        os << c.real;
        real_printed = true;
    }

    // Handle imaginary part
    if (c.imag != 0.0) {
        if (real_printed) { // If real part was printed, add +/-
            if (c.imag > 0) {
                os << " + ";
            } else { // c.imag < 0
                os << " - ";
            }
            os << std::abs(c.imag) << "i";
        } else { // Purely imaginary number (e.g., (5i) or (-5i))
            os << c.imag << "i";
        }
    } else if (!real_printed) { // Special case for Complex(0,0) -> (0)
        os << "0";
    }

    os << ")";

    // Restore stream state
    os.flags(old_flags);
    os.precision(old_prec);
    return os;
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