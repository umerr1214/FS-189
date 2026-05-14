#include <iostream>
#include <string> // Required for std::boolalpha

class ComplexNumber {
public:
    double real;
    double imag;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
}; // Correct semicolon

// Non-member equality operator with a logical error
bool operator==(const ComplexNumber& c1, const ComplexNumber& c2) {
    // Logical Error: Uses logical OR (||) instead of logical AND (&&)
    // This returns true if *either* the real parts are equal OR the imaginary parts are equal,
    // not if both are identical as required by the question.
    return (c1.real == c2.real) || (c1.imag == c2.imag);
}

int main() {
    std::cout << std::boolalpha; // Print true/false instead of 1/0

    // Test case 1: Identical complex numbers (Correctly returns true by chance)
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(1.0, 2.0);
    std::cout << "Test 1: " << c1.real << "+" << c1.imag << "i == " << c2.real << "+" << c2.imag << "i -> " << (c1 == c2) << " (Expected: true)" << std::endl;

    // Test case 2: Different imaginary parts (Incorrectly returns true)
    ComplexNumber c3(1.0, 2.0);
    ComplexNumber c4(1.0, 3.0);
    std::cout << "Test 2: " << c3.real << "+" << c3.imag << "i == " << c4.real << "+" << c4.imag << "i -> " << (c3 == c4) << " (Expected: false)" << std::endl;
    
    // Test case 3: Different real parts (Incorrectly returns true)
    ComplexNumber c5(1.0, 2.0);
    ComplexNumber c6(3.0, 2.0);
    std::cout << "Test 3: " << c5.real << "+" << c5.imag << "i == " << c6.real << "+" << c6.imag << "i -> " << (c5 == c6) << " (Expected: false)" << std::endl;

    // Test case 4: Completely different (Correctly returns false)
    ComplexNumber c7(1.0, 2.0);
    ComplexNumber c8(3.0, 4.0);
    std::cout << "Test 4: " << c7.real << "+" << c7.imag << "i == " << c8.real << "+" << c8.imag << "i -> " << (c7 == c8) << " (Expected: false)" << std::endl;

    return 0;
}