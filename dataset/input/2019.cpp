#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

// Design a ComplexNumber class with real and imaginary parts (both double).
// Implement a constructor that takes two arguments for real and imaginary,
// and a default constructor that initializes both to 0.0.

class ComplexNumber {
private:
    double real;      // Private member for the real part
    double imaginary; // Private member for the imaginary part

public:
    // Default constructor: Initializes both parts to 0.0 using an initializer list (best practice)
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor: Takes two doubles for real and imaginary parts
    // Uses an initializer list (best practice) and descriptive parameter names
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Constant getters: Provide read-only access to private members (best practice for encapsulation)
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }
};

int main() {
    // Set output precision for consistent double representation
    std::cout << std::fixed << std::setprecision(1);

    // Test Case 1: Default constructor
    ComplexNumber c1;
    std::cout << "Test 1 - Default: Real: " << c1.getReal() << ", Imaginary: " << c1.getImaginary() << std::endl;

    // Test Case 2: Parameterized constructor with positive real, negative imaginary
    ComplexNumber c2(3.5, -2.1);
    std::cout << "Test 2 - Param (3.5, -2.1): Real: " << c2.getReal() << ", Imaginary: " << c2.getImaginary() << std::endl;

    // Test Case 3: Parameterized constructor with zero real, positive imaginary
    ComplexNumber c3(0.0, 7.0);
    std::cout << "Test 3 - Param (0.0, 7.0): Real: " << c3.getReal() << ", Imaginary: " << c3.getImaginary() << std::endl;

    // Test Case 4: Parameterized constructor with negative real, zero imaginary
    ComplexNumber c4(-1.0, 0.0);
    std::cout << "Test 4 - Param (-1.0, 0.0): Real: " << c4.getReal() << ", Imaginary: " << c4.getImaginary() << std::endl;

    return 0;
}