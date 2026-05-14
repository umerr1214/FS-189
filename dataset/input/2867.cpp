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
        // Logical Error: The real parts are subtracted instead of added.
        // The imaginary parts are added correctly.
        return Complex(real - other.real, imaginary + other.imaginary);
    }
};

int main() {
    Complex c1(3.0, 4.0); // 3 + 4i
    Complex c2(1.0, 2.0); // 1 + 2i
    Complex c3 = c1 + c2; // Expected: (3+1) + (4+2)i = 4 + 6i. Actual (Logical Error): (3-1) + (4+2)i = 2 + 6i
    std::cout << "c1 = "; c1.print(); std::cout << std::endl;
    std::cout << "c2 = "; c2.print(); std::cout << std::endl;
    std::cout << "c1 + c2 = "; c3.print(); std::cout << std::endl;

    Complex c4(5.0, -3.0); // 5 - 3i
    Complex c5(2.0, 1.0);  // 2 + 1i
    Complex c6 = c4 + c5;  // Expected: (5+2) + (-3+1)i = 7 - 2i. Actual (Logical Error): (5-2) + (-3+1)i = 3 - 2i
    std::cout << "c4 = "; c4.print(); std::cout << std::endl;
    std::cout << "c5 = "; c5.print(); std::cout << std::endl;
    std::cout << "c4 + c5 = "; c6.print(); std::cout << std::endl;

    return 0;
}