#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

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
} // SYNTAX ERROR: Missing semicolon after class definition

// Overload binary + operator
// This function needs to be a friend to access private members directly.
// Even if it were a friend, the missing semicolon above would prevent compilation.
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
    return ComplexNumber(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

int main() {
    ComplexNumber c1(1.0, 2.0);
    ComplexNumber c2(3.0, 4.0);
    ComplexNumber c3 = c1 + c2;
    c3.print();
    return 0;
}