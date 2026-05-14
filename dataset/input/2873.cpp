#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    double getReal() const { return real; }
    double getImag() const { return imag; }

    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Operator overload definition with a logical error
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    // Logical error: Missing the '+' operator between real and imaginary parts
    // The format should be (real + imaginaryi), but it prints (real imaginaryi)
    os << "(" << c.real << " " << c.imag << "i)";
    return os;
}

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, -2.5);
    Complex c3(0.0, 0.0);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;

    return 0;
}