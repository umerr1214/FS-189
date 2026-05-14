#include <iostream>
#include <string>

class Complex {
private:
    double real;
    double imaginary;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getters (const-correct)
    double getReal() const {
        return real;
    }

    double getImaginary() const {
        return imaginary;
    }

    // Friend declaration for the binary + operator
    // Allows the operator to access private members of Complex objects
    friend Complex operator+(const Complex& c1, const Complex& c2);

    // Friend declaration for the output stream operator
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Overload the binary + operator as a non-member friend function
// Takes two const references to Complex objects and returns a new Complex object by value.
// This is the idiomatic and efficient way for binary arithmetic operators.
Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imaginary + c2.imaginary);
}

// Overload the output stream operator as a non-member friend function
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real;
    if (c.imaginary >= 0) {
        os << " + " << c.imaginary << "i)";
    } else {
        os << " - " << -c.imaginary << "i)";
    }
    return os;
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(3.5, -4.0);
    Complex c3(0.0, 0.0);
    Complex c4(-1.0, -1.0);

    // Perform additions
    Complex sum1 = c1 + c2;
    Complex sum2 = c3 + c4;
    Complex sum3 = c1 + c3;

    // Print results
    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c1 + c2: " << sum1 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c3 + c4: " << sum2 << std::endl;
    std::cout << "c1 + c3: " << sum3 << std::endl;

    return 0;
}