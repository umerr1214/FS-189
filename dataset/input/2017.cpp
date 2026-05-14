#include <iostream>
#include <iomanip> // Required for std::fixed and std::setprecision

// Design a ComplexNumber class with real and imaginary parts (both double).
// Implement a constructor that takes two arguments for real and imaginary,
// and a default constructor that initializes both to 0.0.

class ComplexNumber {
public:
    // Robustness Issue: Member variables 'real' and 'imaginary' are public.
    // This violates encapsulation, allowing direct external modification and
    // making the class less robust against misuse and harder to maintain
    // or extend while preserving data integrity.
    double real;
    double imaginary;

    // Default constructor: Initializes both parts to 0.0
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor: Takes two doubles for real and imaginary parts
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}
};

int main() {
    // Set output precision for consistent double representation
    std::cout << std::fixed << std::setprecision(1);

    // Test Case 1: Default constructor
    ComplexNumber c1;
    std::cout << "Test 1 - Default: Real: " << c1.real << ", Imaginary: " << c1.imaginary << std::endl;

    // Test Case 2: Parameterized constructor with positive real, negative imaginary
    ComplexNumber c2(3.5, -2.1);
    std::cout << "Test 2 - Param (3.5, -2.1): Real: " << c2.real << ", Imaginary: " << c2.imaginary << std::endl;

    // Test Case 3: Parameterized constructor with zero real, positive imaginary
    ComplexNumber c3(0.0, 7.0);
    std::cout << "Test 3 - Param (0.0, 7.0): Real: " << c3.real << ", Imaginary: " << c3.imaginary << std::endl;

    // Test Case 4: Parameterized constructor with negative real, zero imaginary
    ComplexNumber c4(-1.0, 0.0);
    std::cout << "Test 4 - Param (-1.0, 0.0): Real: " << c4.real << ", Imaginary: " << c4.imaginary << std::endl;

    return 0;
}