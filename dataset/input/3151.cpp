#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Robustness Issue: Default constructor leaves members uninitialized.
    // If a ComplexNumber object is created using this constructor
    // (e.g., ComplexNumber c;) and then its real or imaginary parts
    // are accessed before explicit assignment, they will contain
    // garbage values, leading to undefined behavior.
    ComplexNumber() {
        // 'real' and 'imaginary' are NOT initialized here.
        // For local variables, this means they will have indeterminate values.
    }

    // Parameterized constructor
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // A utility method to get a string representation for output
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

// Overload the binary + operator as a non-member function.
// Parameters are passed by const reference to avoid unnecessary copies.
// Returns a new ComplexNumber object by value.
ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
    return ComplexNumber(a.real + b.real, a.imaginary + b.imaginary);
}

// Driver code to demonstrate functionality and test cases
int main() {
    // Test Case 1: Standard addition of two complex numbers
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(1.0, -1.5);
    ComplexNumber c3 = c1 + c2;
    std::cout << "Test Case 1: (" << c1.toString() << ") + (" << c2.toString() << ") = " << c3.toString() << std::endl;

    // Test Case 2: Addition with a zero complex number (explicitly initialized)
    ComplexNumber c4(0.0, 0.0);
    ComplexNumber c5 = c1 + c4;
    std::cout << "Test Case 2: (" << c1.toString() << ") + (" << c4.toString() << ") = " << c5.toString() << std::endl;

    // Test Case 3: Robustness Issue Demonstration
    // c6 is default-constructed, its members are uninitialized (garbage)
    ComplexNumber c6; // 'real' and 'imaginary' are uninitialized
    std::cout << "Test Case 3 (Robustness Issue): Default-constructed c6: " << c6.toString() << std::endl;

    // Adding c6 to another number will use its uninitialized values,
    // leading to undefined behavior and unpredictable results.
    ComplexNumber c7(5.0, 5.0);
    ComplexNumber c8 = c6 + c7; // This operation uses uninitialized values from c6
    std::cout << "Test Case 3 (Robustness Issue): (" << c6.toString() << ") + (" << c7.toString() << ") = " << c8.toString() << std::endl;

    // Test Case 4: Addition with negative imaginary parts
    ComplexNumber c9(10.0, -7.0);
    ComplexNumber c10(-3.0, 2.0);
    ComplexNumber c11 = c9 + c10;
    std::cout << "Test Case 4: (" << c9.toString() << ") + (" << c10.toString() << ") = " << c11.toString() << std::endl;

    return 0;
}