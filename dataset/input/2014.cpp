#include <iostream>

class ComplexNumber {
public:
    double real;
    double imaginary;

    // Default constructor
    ComplexNumber() : real(0.0), imaginary(0.0) {}

    // Parameterized constructor
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    void print() {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    ComplexNumber c1;
    ComplexNumber c2(3.0, 4.0);

    std::cout << "c1: ";
    c1.print();
    std::cout << "c2: ";
    c2.print();

    return 0;
}