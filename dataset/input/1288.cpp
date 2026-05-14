#include <iostream>
#include <cmath> // For std::abs

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
} // ERROR: Missing semicolon after class definition.

// The operator<< implementation is logically correct, but the program won't compile due to the syntax error above.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
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

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;

    return 0;
}