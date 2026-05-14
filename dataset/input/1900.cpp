#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0.0), imaginary(0.0) {}

    // Constructor taking only real part
    Complex(double r) : real(r), imaginary(0.0) {}

    // Constructor taking both real and imaginary parts
    Complex(double r, double i) : real(r), imaginary(i) {}

    void print() const {
        std::cout << "Complex: " << real << " + " << imaginary << "i" << std::endl;
    }
} // ERROR: Missing semicolon after class definition

int main() {
    Complex c1;
    Complex c2(5.0);
    Complex c3(3.0, 4.0);

    c1.print();
    c2.print();
    c3.print();

    return 0;
}