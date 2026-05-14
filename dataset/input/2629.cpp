#include <iostream>
#include <string>
#include <cmath> // For std::abs, though not used optimally here

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Friend declaration for the overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);

    // Getters for testing/internal use if needed, though not strictly required by operator<<
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

// Overload the stream insertion operator as a non-member friend function
// This version has a robustness issue: it prints "(real + -imaginaryi)" for negative imaginary parts
// and "(real + 0i)" for zero imaginary parts, which is not user-friendly.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << "(" << c.real;
    // Robustness issue: Always prints '+', then the signed imaginary part,
    // and '0i' even if imaginary is zero.
    // It also prints "+ -abs(imaginary)i" for negative imaginary.
    os << " + " << c.imaginary << "i";
    os << ")";
    return os;
}

int main() {
    std::cout << "Testing ComplexNumber stream insertion (Robustness Issue):\n";

    // Test cases
    ComplexNumber c1(3, 4);    // Positive imaginary
    ComplexNumber c2(5, -2);   // Negative imaginary
    ComplexNumber c3(0, 7);    // Zero real, positive imaginary
    ComplexNumber c4(-1, 0);   // Negative real, zero imaginary
    ComplexNumber c5(0, 0);    // Both zero
    ComplexNumber c6(2, 1);    // Imaginary part is 1
    ComplexNumber c7(-3, -1);  // Negative real, imaginary part is -1

    std::cout << c1 << std::endl; // Expected: (3 + 4i)
    std::cout << c2 << std::endl; // Expected: (5 + -2i) - Robustness issue: should be (5 - 2i)
    std::cout << c3 << std::endl; // Expected: (0 + 7i) - Robustness issue: should be (7i)
    std::cout << c4 << std::endl; // Expected: (-1 + 0i) - Robustness issue: should be (-1)
    std::cout << c5 << std::endl; // Expected: (0 + 0i) - Robustness issue: should be (0)
    std::cout << c6 << std::endl; // Expected: (2 + 1i)
    std::cout << c7 << std::endl; // Expected: (-3 + -1i) - Robustness issue: should be (-3 - i)

    return 0;
}