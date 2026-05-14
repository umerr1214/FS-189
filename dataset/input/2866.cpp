#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    void print() const {
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
    }

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
} // Syntax Error: Missing semicolon after class definition

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    std::cout << "c1 = "; c1.print(); std::cout << std::endl;
    std::cout << "c2 = "; c2.print(); std::cout << std::endl;
    std::cout << "c1 + c2 = "; c3.print(); std::cout << std::endl // Syntax Error: Missing semicolon
    retun 0; // Syntax Error: Typo 'retun' instead of 'return'
}