#include <iostream>

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Default constructor
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor with LOGICAL ERROR: real and imaginary parts are swapped
    ComplexNumber(double r, double i) : real(i), imaginary(r) {}

    void print() {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    ComplexNumber c1; // Expected: 0 + 0i
    ComplexNumber c2(3.0, 4.0); // Expected: 3 + 4i, but due to logical error will be 4 + 3i
    ComplexNumber c3(-1.5, 2.5); // Expected: -1.5 + 2.5i, but due to logical error will be 2.5 + -1.5i

    std::cout << "c1: ";
    c1.print();
    std::cout << "c2: ";
    c2.print();
    std::cout << "c3: ";
    c3.print();

    return 0;
}