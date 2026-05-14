#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Method to display the complex number
    void display() const {
        std::cout << std::fixed << std::setprecision(1) << "(" << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i)";
        } else {
            std::cout << " - " << -imaginary << "i)";
        }
    }
};

// Overload the binary + operator for ComplexNumber objects
// This implementation contains a logical error: it swaps real and imaginary parts of the second operand
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    // Logical error: Adds c2's imaginary part to c1's real part,
    // and c2's real part to c1's imaginary part.
    return ComplexNumber(c1.real + c2.imaginary, c1.imaginary + c2.real);
}

// Overload the << operator for easy printing
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << std::fixed << std::setprecision(1) << "(" << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i)";
    } else {
        os << " - " << -c.imaginary << "i)";
    }
    return os;
}

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber sum = c1 + c2;
    std::cout << "Sum: " << sum << std::endl; // Expected: (4.0 + 6.0i), Actual: (5.0 + 5.0i)

    ComplexNumber c3(5.0, -1.0);
    ComplexNumber c4(-2.0, 3.0);
    ComplexNumber sum2 = c3 + c4;
    std::cout << "Sum: " << sum2 << std::endl; // Expected: (3.0 + 2.0i), Actual: (8.0 - 3.0i)

    return 0;
}