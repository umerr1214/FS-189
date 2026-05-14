#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
private:
    double real;      // Stores the real part of the complex number
    double imaginary; // Stores the imaginary part of the complex number

public:
    // Default constructor: Initializes real and imaginary parts to 0.0
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor: Initializes with given real and imaginary values
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Getter for the real part (const-qualified as it does not modify the object)
    double getReal() const {
        return real;
    }

    // Getter for the imaginary part (const-qualified as it does not modify the object)
    double getImaginary() const {
        return imaginary;
    }

    // Utility method to get a string representation of the complex number for output.
    // Const-qualified as it does not modify the object.
    std::string toString() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2); // Format output to 2 decimal places
        if (imaginary >= 0) {
            ss << real << " + " << imaginary << "i";
        } else {
            ss << real << " - " << -imaginary << "i";
        }
        return ss.str();
    }
};

// Overload the binary + operator as a non-member, non-friend function.
// This approach is generally preferred for arithmetic operators for symmetry
// and allows for implicit conversions on both operands if constructors support them.
// Parameters are passed by const reference to avoid unnecessary copies.
// Returns a new ComplexNumber object by value, leveraging Return Value Optimization (RVO).
ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.getReal() + b.getReal(), a.getImaginary() + b.getImaginary());
}

// Overload the stream insertion operator (operator<<) for easy printing of ComplexNumber objects.
// This allows `std::cout << myComplexNumber;` syntax.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << c.toString();
    return os;
}

// Driver code to demonstrate functionality and test cases
int main() {
    // Test Case 1: Standard addition of two complex numbers
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(1.0, -1.5);
    ComplexNumber c3 = c1 + c2;
    std::cout << "Test Case 1: (" << c1 << ") + (" << c2 << ") = " << c3 << std::endl; // Using overloaded operator<<

    // Test Case 2: Addition with a zero complex number (using default constructor)
    ComplexNumber c4; // c4 is 0.0 + 0.0i
    ComplexNumber c5 = c1 + c4;
    std::cout << "Test Case 2: (" << c1 << ") + (" << c4 << ") = " << c5 << std::endl;

    // Test Case 3: Addition with negative real and imaginary parts
    ComplexNumber c6(-5.0, -2.0);
    ComplexNumber c7(3.0, 4.0);
    ComplexNumber c8 = c6 + c7;
    std::cout << "Test Case 3: (" << c6 << ") + (" << c7 << ") = " << c8 << std::endl;

    // Test Case 4: Chained addition demonstrating operator associativity
    ComplexNumber c9(1.0, 1.0);
    ComplexNumber c10(2.0, 2.0);
    ComplexNumber c11(3.0, 3.0);
    ComplexNumber c12 = c9 + c10 + c11; // Evaluates as (c9 + c10) + c11
    std::cout << "Test Case 4: (" << c9 << ") + (" << c10 << ") + (" << c11 << ") = " << c12 << std::endl;

    // Test Case 5: Addition with fractional parts
    ComplexNumber c13(0.12, 0.34);
    ComplexNumber c14(0.56, -0.78);
    ComplexNumber c15 = c13 + c14;
    std::cout << "Test Case 5: (" << c13 << ") + (" << c14 << ") = " << c15 << std::endl;

    return 0;
}