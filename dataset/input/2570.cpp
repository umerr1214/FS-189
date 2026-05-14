#include <iostream>
#include <string>
#include <sstream>
#include <cmath> // Required for std::abs

class ComplexNumber {
private:
    double real;
    double imag;

public:
    // Constructor
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Getter for real part
    double getReal() const { return real; }
    // Getter for imaginary part
    double getImag() const { return imag; }

    // Overload the unary - operator (Readability/Efficiency Issue)
    ComplexNumber operator-() const {
        // This implementation is correct but less concise and potentially less efficient
        // than directly constructing the return object. It involves default construction
        // followed by member-wise assignment.
        ComplexNumber negated_complex; // Default construction
        negated_complex.real = -this->real; // Assign real part
        negated_complex.imag = -this->imag; // Assign imaginary part
        return negated_complex; // Return the new object by value
    }

    // Friend function to allow easy printing of ComplexNumber objects
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
        os << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "i";
        } else {
            os << " - " << std::abs(c.imag) << "i";
        }
        return os;
    }
};

int main() {
    // Test cases
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(-1.0, -4.5);
    ComplexNumber c3(0.0, 0.0);
    ComplexNumber c4(5.0, 0.0);
    ComplexNumber c5(0.0, 7.2);

    // Applying the unary minus operator
    ComplexNumber neg_c1 = -c1;
    ComplexNumber neg_c2 = -c2;
    ComplexNumber neg_c3 = -c3;
    ComplexNumber neg_c4 = -c4;
    ComplexNumber neg_c5 = -c5;

    std::cout << neg_c1 << std::endl;
    std::cout << neg_c2 << std::endl;
    std::cout << neg_c3 << std::endl;
    std::cout << neg_c4 << std::endl;
    std::cout << neg_c5 << std::endl;

    return 0;
}