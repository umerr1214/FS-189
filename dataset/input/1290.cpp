#include <iostream>
#include <cmath> // For std::abs

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // A copy constructor can be added to demonstrate the semantic issue more clearly,
    // though not strictly required for the error category.
    // Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {
    //     std::cout << "Complex object copied!" << std::endl;
    // }
};

// Semantic Error: Passing Complex object by value instead of const reference.
// This causes an unnecessary copy of the Complex object every time the operator is called,
// which is inefficient and semantically incorrect for an output operator that should not modify its operand.
std::ostream& operator<<(std::ostream& os, Complex c) { // 'Complex c' instead of 'const Complex& c'
    if (c.imaginary == 0) {
        os << c.real;
    } else if (c.real == 0) {
        os << c.imaginary << "i";
    } else {
        os << c.real;
        if (c.imaginary > 0) {
            os << " + " << c.imaginary << "i";
        } else {
            os << " - " << std::abs(c.imaginary) << "i";
        }
    }
    return os;
}

int main() {
    Complex c1(3, 4);
    Complex c2(5, -2);
    Complex c3(0, 7);
    Complex c4(6, 0);

    std::cout << c1 << std::endl; // c1 is copied to the operator's parameter
    std::cout << c2 << std::endl; // c2 is copied
    std::cout << c3 << std::endl; // c3 is copied
    std::cout << c4 << std::endl; // c4 is copied

    return 0;
}