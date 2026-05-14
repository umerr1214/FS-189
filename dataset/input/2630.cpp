#include <iostream>
#include <string>
#include <sstream> // For std::stringstream
#include <cmath>   // For std::abs

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

// Overload the stream insertion operator as a non-member friend function
// This version is correct in its output but has readability/efficiency issues:
// - It uses std::stringstream, which is less efficient than direct printing for simple cases.
// - The logic for constructing the string is overly verbose and could be more concise.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    std::stringstream ss;
    ss << "(";

    if (c.real == 0.0 && c.imaginary == 0.0) {
        ss << "0";
    } else if (c.real == 0.0) { // Only imaginary part
        if (c.imaginary == 1.0) {
            ss << "i";
        } else if (c.imaginary == -1.0) {
            ss << "-i";
        } else {
            ss << c.imaginary << "i";
        }
    } else if (c.imaginary == 0.0) { // Only real part
        ss << c.real;
    } else { // Both real and imaginary non-zero
        ss << c.real;
        if (c.imaginary > 0) {
            ss << " + ";
        } else { // c.imaginary < 0
            ss << " - ";
        }
        if (std::abs(c.imaginary) == 1.0) {
            ss << "i";
        } else {
            ss << std::abs(c.imaginary) << "i";
        }
    }
    ss << ")";
    return os << ss.str(); // Less efficient due to stringstream and string copy
}

int main() {
    std::cout << "Testing ComplexNumber stream insertion (Readability/Efficiency Issue):\n";

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