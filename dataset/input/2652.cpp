#include <iostream>
#include <string> // Required for std::boolalpha

class ComplexNumber {
public:
    double real;
    double imag;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Semantic Error: operator== implemented as a member function.
    // The question explicitly asked for a non-member function.
    bool operator==(const ComplexNumber& other) const {
        return (real == other.real) && (imag == other.imag);
    }
}; // Correct semicolon

// No non-member operator== here, as the semantic error is defining it as a member.

int main() {
    std::cout << std::boolalpha; // Print true/false instead of 1/0

    // Test case 1: Identical complex numbers
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(1.0, 2.0);
    std::cout << "Test 1: " << c1.real << "+" << c1.imag << "i == " << c2.real << "+" << c2.imag << "i -> " << (c1 == c2) << " (Expected: true)" << std::endl;

    // Test case 2: Different imaginary parts
    ComplexNumber c3(1.0, 2.0);
    ComplexNumber c4(1.0, 3.0);
    std::cout << "Test 2: " << c3.real << "+" << c3.imag << "i == " << c4.real << "+" << c4.imag << "i -> " << (c3 == c4) << " (Expected: false)" << std::endl;
    
    // Test case 3: Different real parts
    ComplexNumber c5(1.0, 2.0);
    ComplexNumber c6(3.0, 2.0);
    std::cout << "Test 3: " << c5.real << "+" << c5.imag << "i == " << c6.real << "+" << c6.imag << "i -> " << (c5 == c6) << " (Expected: false)" << std::endl;

    // Test case 4: Completely different
    ComplexNumber c7(1.0, 2.0);
    ComplexNumber c8(3.0, 4.0);
    std::cout << "Test 4: " << c7.real << "+" << c7.imag << "i == " << c8.real << "+" << c8.imag << "i -> " << (c7 == c8) << " (Expected: false)" << std::endl;

    return 0;
}