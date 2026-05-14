#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

// Design a ComplexNumber class with real and imaginary parts (both double).
// Implement a constructor that takes two arguments for real and imaginary,
// and a default constructor that initializes both to 0.0.

class ComplexNumber {
private:
    // Readability Issue: Member variable names 'r' and 'i' are not descriptive.
    double r;
    double i;

public:
    // Default constructor: Initializes both parts to 0.0
    // Readability/Efficiency Issue: Members initialized in constructor body instead of initializer list.
    // While less impactful for primitive types like double, it's generally less efficient and less idiomatic C++.
    ComplexNumber() {
        r = 0.0;
        i = 0.0;
    }

    // Parameterized constructor: Takes two doubles for real and imaginary parts
    // Readability/Efficiency Issue: Members initialized in constructor body instead of initializer list.
    ComplexNumber(double x, double y) { // Readability Issue: Parameter names 'x' and 'y' are not descriptive.
        r = x;
        i = y;
    }

    // Public getters to access private members for testing
    double getReal() { return r; }
    double getImaginary() { return i; }
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