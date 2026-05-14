#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ComplexNumber {
public:
    double r_val; // Poor variable name for real part
    double i_val; // Poor variable name for imaginary part

    // Parameterized constructor with unnecessary 'this->'
    ComplexNumber(double r, double i) {
        this->r_val = r;
        this->i_val = i;
    }

    // Default constructor, also uses poor names and 'this->'
    ComplexNumber() {
        this->r_val = 0.0;
        this->i_val = 0.0;
    }

    // Member function overload for binary + operator.
    // While functional, it's less idiomatic than a non-member function for binary operators
    // and the implementation is slightly verbose.
    ComplexNumber operator+(const ComplexNumber& other) const;

    // Utility method to get a string representation for output.
    // Uses unnecessary 'this->' and lacks comments.
    std::string toString() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(2);
        if (this->i_val >= 0) {
            ss << this->r_val << " + " << this->i_val << "i";
        } else {
            ss << this->r_val << " - " << -this->i_val << "i";
        }
        return ss.str();
    }
};

// Definition of the overloaded + operator (member function).
// No comments, uses member variables with poor names.
// Creates a temporary object explicitly, which while often optimized by compilers
// (RVO), is less direct than constructing the returned object in place.
ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
    ComplexNumber temp_result; // Creates a temporary object
    temp_result.r_val = this->r_val + other.r_val; // Redundant this->
    temp_result.i_val = this->i_val + other.i_val; // Redundant this->
    return temp_result; // Returns the temporary
}

// Driver code to demonstrate functionality and test cases
int main() {
    // Test Case 1: Standard addition
    ComplexNumber cnum1(2.5, 3.0);
    ComplexNumber cnum2(1.0, -1.5);
    ComplexNumber cnum3 = cnum1 + cnum2; // Uses member operator+
    std::cout << "Test Case 1: (" << cnum1.toString() << ") + (" << cnum2.toString() << ") = " << cnum3.toString() << std::endl;

    // Test Case 2: Addition with zero
    ComplexNumber cnum4(0.0, 0.0);
    ComplexNumber cnum5 = cnum1 + cnum4;
    std::cout << "Test Case 2: (" << cnum1.toString() << ") + (" << cnum4.toString() << ") = " << cnum5.toString() << std::endl;

    // Test Case 3: Addition with negative parts
    ComplexNumber cnum6(-5.0, -2.0);
    ComplexNumber cnum7(3.0, 4.0);
    ComplexNumber cnum8 = cnum6 + cnum7;
    std::cout << "Test Case 3: (" << cnum6.toString() << ") + (" << cnum7.toString() << ") = " << cnum8.toString() << std::endl;

    // Test Case 4: Chained addition
    ComplexNumber cnum9(1.0, 1.0);
    ComplexNumber cnum10(2.0, 2.0);
    ComplexNumber cnum11(3.0, 3.0);
    ComplexNumber cnum12 = cnum9 + cnum10 + cnum11; // (cnum9 + cnum10) + cnum11
    std::cout << "Test Case 4: (" << cnum9.toString() << ") + (" << cnum10.toString() << ") + (" << cnum11.toString() << ") = " << cnum12.toString() << std::endl;

    return 0;
}