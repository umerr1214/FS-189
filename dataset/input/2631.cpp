#include <iostream>
#include <string>
#include <cmath> // For std::abs

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);

    // Getters are not strictly needed for operator<< but can be useful
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

// Overload the stream insertion operator as a non-member friend function
// This version is correct, efficient, and user-friendly.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << "(";

    if (c.real == 0.0 && c.imaginary == 0.0) {
        os << "0";
    } else if (c.real == 0.0) { // Only imaginary part (e.g., (4i), (i), (-i))
        if (c.imaginary == 1.0) {
            os << "i";
        } else if (c.imaginary == -1.0) {
            os << "-i";
        } else {
            os << c.imaginary << "i";
        }
    } else if (c.imaginary == 0.0) { // Only real part (e.g., (3))
        os << c.real;
    } else { // Both real and imaginary non-zero (e.g., (3 + 4i), (5 - 2i), (2 + i))
        os << c.real;
        if (c.imaginary > 0) {
            os << " + ";
        } else { // c.imaginary < 0
            os << " - ";
        }
        if (std::abs(c.imaginary) == 1.0) {
            os << "i"; // For (2 + i) instead of (2 + 1i)
        } else {
            os << std::abs(c.imaginary) << "i";
        }
    }
    os << ")";
    return os;
}

int main() {
    std::cout << "Testing ComplexNumber stream insertion (Correct Version):\n";

    // Test cases
    ComplexNumber c1(3, 4);    // Positive imaginary
    ComplexNumber c2(5, -2);   // Negative imaginary
    ComplexNumber c3(0, 7);    // Zero real, positive imaginary
    ComplexNumber c4(-1, 0);   // Negative real, zero imaginary
    ComplexNumber c5(0, 0);    // Both zero
    ComplexNumber c6(2, 1);    // Imaginary part is 1
    ComplexNumber c7(-3, -1);  // Negative real, imaginary part is -1
    ComplexNumber c8(0, 1);    // Pure imaginary 'i'
    ComplexNumber c9(0, -1);   // Pure imaginary '-i'

    std::cout << c1 << std::endl; // Expected: (3 + 4i)
    std::cout << c2 << std::endl; // Expected: (5 - 2i)
    std::cout << c3 << std::endl; // Expected: (7i)
    std::cout << c4 << std::endl; // Expected: (-1)
    std::cout << c5 << std::endl; // Expected: (0)
    std::cout << c6 << std::endl; // Expected: (2 + i)
    std::cout << c7 << std::endl; // Expected: (-3 - i)
    std::cout << c8 << std::endl; // Expected: (i)
    std::cout << c9 << std::endl; // Expected: (-i)

    return 0;
}