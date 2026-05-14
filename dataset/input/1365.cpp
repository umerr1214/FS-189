#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    // Constructor with default arguments
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getter methods for private members (const-correct)
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Friend declarations for non-member operators to access private members
    friend ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Overload binary + operator as a non-member function
// Takes operands by const reference for efficiency and returns a new ComplexNumber object.
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    return ComplexNumber(lhs.real + rhs.real, lhs.imaginary + rhs.imaginary);
}

// Overload stream insertion operator for easy and readable printing
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << std::fixed << std::setprecision(2); // Format output to 2 decimal places
    os << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i";
    } else {
        // For negative imaginary parts, print a minus sign followed by the positive magnitude
        os << " - " << -c.imaginary << "i";
    }
    return os;
}

// Driver code
int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3(-0.5, 1.5);
    ComplexNumber c4(2.5, -3.5);
    ComplexNumber c5(5.0, 0.0); // Purely real number
    ComplexNumber c6(0.0, -7.0); // Purely imaginary number

    // Test Case 1: Addition of two complex numbers with positive parts
    ComplexNumber sum1 = c1 + c2;
    std::cout << sum1 << std::endl;

    // Test Case 2: Addition with mixed signs, resulting in a negative imaginary part
    ComplexNumber sum2 = c3 + c4;
    std::cout << sum2 << std::endl;

    // Test Case 3: Chained addition of multiple complex numbers
    ComplexNumber sum3 = c1 + c3 + c5;
    std::cout << sum3 << std::endl;

    // Test Case 4: Addition involving purely real and purely imaginary numbers
    ComplexNumber sum4 = c5 + c6;
    std::cout << sum4 << std::endl;

    return 0;
}