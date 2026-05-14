#include <iostream>
#include <string>
#include <cmath> // For std::abs

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend declaration for operator<<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Robustness Issue:
// The implementation strictly follows the format (real + imaginaryi)
// even when 'imaginary' is negative or zero, leading to outputs like
// (3 + -5i) instead of (3 - 5i), or (3 + 0i) instead of (3).
// While technically adhering to the literal format string, it
// results in a less robust and less user-friendly presentation for
// common mathematical conventions.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real << " + " << c.imag << "i)";
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