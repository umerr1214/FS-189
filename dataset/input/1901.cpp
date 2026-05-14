#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Default constructor
    Complex() : real(0.0), imaginary(0.0) {}

    // Constructor taking only real part - LOGICAL ERROR
    // Should initialize imaginary to 0.0, but incorrectly initializes to r
    Complex(double r) : real(r), imaginary(r) {}

    // Constructor taking both real and imaginary parts
    Complex(double r, double i) : real(r), imaginary(i) {}

    void print() const {
        std::cout << "Complex: " << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    Complex c1;
    Complex c2(5.0); // Expected: 5 + 0i, but will output: 5 + 5i due to logical error
    Complex c3(3.0, 4.0);

    c1.print();
    c2.print();
    c3.print();

    return 0;
}