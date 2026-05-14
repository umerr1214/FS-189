#include <iostream>
#include <cmath> // For std::abs

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
};

// Logical Error: Always prints '+' for the imaginary part, even if it's negative.
// For example, 5 - 2i will be printed as 5 + 2i.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.imaginary == 0) {
        os << c.real;
    } else if (c.real == 0) {
        os << c.imaginary << "i"; // This case handles 0 real correctly (e.g., "7i" or "-7i")
    } else {
        os << c.real;
        // The logical error is here: always printing '+' before std::abs(c.imaginary)
        // instead of checking if c.imaginary is positive or negative.
        os << " + " << std::abs(c.imaginary) << "i";
    }
    return os;
}

int main() {
    Complex c1(3, 4);    // Expected: 3 + 4i, Actual: 3 + 4i (Correct)
    Complex c2(5, -2);   // Expected: 5 - 2i, Actual: 5 + 2i (Incorrect)
    Complex c3(0, 7);    // Expected: 7i, Actual: 7i (Correct)
    Complex c4(6, 0);    // Expected: 6, Actual: 6 (Correct)
    Complex c5(-1, -1);  // Expected: -1 - 1i, Actual: -1 + 1i (Incorrect)
    Complex c6(0, 0);    // Expected: 0, Actual: 0 (Correct)
    Complex c7(1, 1);    // Expected: 1 + 1i, Actual: 1 + 1i (Correct)
    Complex c8(1, -1);   // Expected: 1 - 1i, Actual: 1 + 1i (Incorrect)
    Complex c9(-1, 1);   // Expected: -1 + 1i, Actual: -1 + 1i (Correct)

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;
    std::cout << c3 << std::endl;
    std::cout << c4 << std::endl;
    std::cout << c5 << std::endl;
    std::cout << c6 << std::endl;
    std::cout << c7 << std::endl;
    std::cout << c8 << std::endl;
    std::cout << c9 << std::endl;

    return 0;
}