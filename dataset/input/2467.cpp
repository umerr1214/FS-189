#include <iostream>

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Robustness Issue: operator+ is not declared const.
    // It should be: ComplexNumber operator+(const ComplexNumber& other) const { ... }
    // Omitting 'const' here means this operator cannot be called on const ComplexNumber objects.
    ComplexNumber operator+(const ComplexNumber& other) {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // operator<< is correctly implemented as a friend function.
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.real;
        if (c.imaginary >= 0) {
            os << " + " << c.imaginary << "i";
        } else {
            os << " - " << -c.imaginary << "i";
        }
        return os;
    }
};

int main() {
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber c2(1.5, -2.5);
    ComplexNumber c3 = c1 + c2;

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << c3 << std::endl;

    ComplexNumber c4(0.5, 1.0);
    ComplexNumber c5(-2.0, 0.0);
    ComplexNumber c6 = c4 + c5;
    std::cout << "c4 + c5: " << c6 << std::endl;

    // Example of what would fail to compile due to the missing 'const' in operator+:
    // const ComplexNumber const_c1(1.0, 1.0);
    // const ComplexNumber const_c2(2.0, 2.0);
    // ComplexNumber const_sum = const_c1 + const_c2; // Compiler error: 'this' argument has type 'const ComplexNumber', but function is not const

    return 0;
}