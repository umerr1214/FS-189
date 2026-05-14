#include <iostream>

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Default constructor
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor with SEMANTIC ERROR:
    // Parameters 'real' and 'imaginary' shadow member variables.
    // The assignments 'real = real;' and 'imaginary = imaginary;' assign
    // the parameter to itself, leaving the member variables uninitialized
    // (or default-initialized to 0 if the class were a POD type in global scope,
    // but for stack objects, they will contain garbage values).
    ComplexNumber(double real, double imaginary) {
        real = real;         // This assigns the parameter 'real' to itself, not the member variable
        imaginary = imaginary; // This assigns the parameter 'imaginary' to itself, not the member variable
    }

    void print() {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    ComplexNumber c1; // Expected: 0 + 0i
    ComplexNumber c2(3.0, 4.0); // Expected: 3 + 4i, but will print garbage values due to semantic error
    ComplexNumber c3(-1.5, 2.5); // Expected: -1.5 + 2.5i, but will print garbage values

    std::cout << "c1: ";
    c1.print();
    std::cout << "c2: ";
    c2.print();
    std::cout << "c3: ";
    c3.print();

    return 0;
}