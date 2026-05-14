#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cmath> // For fabs, though not strictly used in this specific buggy version

class Complex {
public:
    double real;
    double imaginary;

    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}
};

// Robustness Issue: Does not handle edge cases for real/imaginary parts (e.g., zero, one, or negative one)
// in a user-friendly manner. For instance, it prints '3 + 0i' instead of '3', '0 + 4i' instead of '4i',
// '3 + 1i' instead of '3 + i', and '5 + -2i' instead of '5 - 2i'.
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << c.real;
    // Always print the imaginary part, even if 0.
    // Always print the sign and magnitude, even if 1 or -1.
    if (c.imaginary >= 0) { // Includes c.imaginary == 0
        os << " + " << c.imaginary << "i";
    } else { // c.imaginary < 0
        os << " + " << c.imaginary << "i"; // Prints "X + -Yi"
    }
    return os;
}

// Test driver
std::string run_test_cases() {
    std::stringstream ss_output;
    std::vector<Complex> complexes = {
        Complex(3, 4),    // Expected: "3 + 4i"
        Complex(5, -2),   // Expected: "5 - 2i"
        Complex(3, 0),    // Expected: "3"
        Complex(0, 4),    // Expected: "4i"
        Complex(0, 0),    // Expected: "0"
        Complex(3, 1),    // Expected: "3 + i"
        Complex(3, -1),   // Expected: "3 - i"
        Complex(0, 1),    // Expected: "i"
        Complex(0, -1)    // Expected: "-i"
    };

    for (const auto& c : complexes) {
        ss_output << c << "\n";
    }
    return ss_output.str();
}

int main() {
    std::cout << run_test_cases();
    return 0;
}