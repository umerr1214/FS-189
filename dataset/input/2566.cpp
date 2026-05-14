#include <iostream>
#include <string>
#include <sstream>
#include <cmath> // For std::abs in tests
#include <iomanip> // For std::fixed, std::setprecision

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Overload unary minus operator
    ComplexNumber operator-() const {
        return ComplexNumber(-real, -imag);
    }

    // For printing
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << std::fixed << std::setprecision(1); // For consistent output formatting
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << -c.imag << "i";
        }
        return os;
    }

    // For comparison in tests
    bool operator==(const ComplexNumber& other) const {
        const double EPSILON = 1e-9;
        return std::abs(real - other.real) < EPSILON && std::abs(imag - other.imag) < EPSILON;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    std::cout << "Testing unary minus operator:" << std::endl;

    // Test Case 1: Positive real, negative imaginary
    ComplexNumber c1(5.0, -3.0);
    ComplexNumber res1 = -c1;
    ComplexNumber expected1(-5.0, 3.0);
    std::cout << "Input: " << c1 << ", Result: " << res1 << ", Expected: " << expected1;
    if (res1 == expected1) {
        std::cout << " (PASS)" << std::endl;
    } else {
        std::cout << " (FAIL)" << std::endl;
    }

    // Test Case 2: Negative real, positive imaginary
    ComplexNumber c2(-1.0, 2.5);
    ComplexNumber res2 = -c2;
    ComplexNumber expected2(1.0, -2.5);
    std::cout << "Input: " << c2 << ", Result: " << res2 << ", Expected: " << expected2;
    if (res2 == expected2) {
        std::cout << " (PASS)" << std::endl;
    } else {
        std::cout << " (FAIL)" << std::endl;
    }

    // Test Case 3: Zero
    ComplexNumber c3(0.0, 0.0);
    ComplexNumber res3 = -c3;
    ComplexNumber expected3(0.0, 0.0);
    std::cout << "Input: " << c3 << ", Result: " << res3 << ", Expected: " << expected3;
    if (res3 == expected3) {
        std::cout << " (PASS)" << std::endl;
    } else {
        std::cout << " (FAIL)" << std::endl;
    }

    // Test Case 4: Only real part
    ComplexNumber c4(10.0, 0.0);
    ComplexNumber res4 = -c4;
    ComplexNumber expected4(-10.0, 0.0);
    std::cout << "Input: " << c4 << ", Result: " << res4 << ", Expected: " << expected4;
    if (res4 == expected4) {
        std::cout << " (PASS)" << std::endl;
    } else {
        std::cout << " (FAIL)" << std::endl;
    }

    // Test Case 5: Only imaginary part
    ComplexNumber c5(0.0, -7.0);
    ComplexNumber res5 = -c5;
    ComplexNumber expected5(0.0, 7.0);
    std::cout << "Input: " << c5 << ", Result: " << res5 << ", Expected: " << expected5;
    if (res5 == expected5) {
        std::cout << " (PASS)" << std::endl;
    } else {
        std::cout << " (FAIL)" << std::endl;
    }

    return 0;
}