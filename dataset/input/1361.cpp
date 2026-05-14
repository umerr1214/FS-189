#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Declare the non-member operator+ as a friend to allow access to private members
    friend ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void print() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
        std::cout << std::endl;
    }
};

// Overload binary + operator (LOGICAL ERROR: performs subtraction instead of addition)
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    // This should be c1.real + c2.real and c1.imaginary + c2.imaginary
    return ComplexNumber(c1.real - c2.real, c1.imaginary - c2.imaginary); // Logical error
}

int main() {
    ComplexNumber c1(10.0, 5.0);
    ComplexNumber c2(3.0, 2.0);
    ComplexNumber c3 = c1 + c2; // Expected: 13 + 7i, Actual: 7 + 3i
    std::cout << "c1: "; c1.print();
    std::cout << "c2: "; c2.print();
    std::cout << "c1 + c2: "; c3.print();

    ComplexNumber c4(1.0, 1.0);
    ComplexNumber c5(1.0, 1.0);
    ComplexNumber c6 = c4 + c5; // Expected: 2 + 2i, Actual: 0 + 0i
    std::cout << "c4: "; c4.print();
    std::cout << "c5: "; c5.print();
    std::cout << "c4 + c5: "; c6.print();

    return 0;
}