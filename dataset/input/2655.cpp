#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> // Required for std::abs for robust floating-point comparison

// Define the ComplexNumber class
class ComplexNumber {
public:
    double real;
    double imag;

    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
};

// A small constant for floating-point comparison tolerance (epsilon)
const double EPSILON = 1e-9;

// Overload the equality operator (==) as a non-member function
// This is the correct and robust version, using epsilon for floating-point comparison.
bool operator==(const ComplexNumber& c1, const ComplexNumber& c2) {
    return std::abs(c1.real - c2.real) < EPSILON &&
           std::abs(c1.imag - c2.imag) < EPSILON;
}

int main() {
    std::stringstream ss;
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(1.0, 2.0);
    ComplexNumber c3(3.0, 4.0);
    ComplexNumber c4(0.1 + 0.2, 0.3); // Mathematically (0.3, 0.3)
    ComplexNumber c5(0.3, 0.3);
    ComplexNumber c6(5.0, -2.5);
    ComplexNumber c7(5.0, -2.5);
    ComplexNumber c8(0.0, 0.0);
    ComplexNumber c9(0.0, 0.0);
    ComplexNumber c10(1e-10, 1e-10); // Very small but non-zero
    ComplexNumber c11(0.0, 0.0);

    ss << (c1 == c2 ? "true" : "false") << std::endl;
    ss << (c1 == c3 ? "true" : "false") << std::endl;
    ss << (c4 == c5 ? "true" : "false") << std::endl; // Expecting true due to epsilon comparison
    ss << (c6 == c7 ? "true" : "false") << std::endl;
    ss << (c8 == c9 ? "true" : "false") << std::endl;
    ss << (c10 == c11 ? "true" : "false") << std::endl; // Expecting true due to epsilon comparison

    std::cout << ss.str();

    return 0;
}