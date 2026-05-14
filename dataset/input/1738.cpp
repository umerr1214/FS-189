#include <iostream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Getter methods for testing
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overload + operator
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary) // Missing semicolon here
    }

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

int main() {
    ComplexNumber c1(2.5, 3.0);
    ComplexNumber c2(1.5, -2.0);
    ComplexNumber c3 = c1 + c2;

    std::cout << "c1: "; c1.print();
    std::cout << "c2: "; c2.print();
    std::cout << "c3 (c1 + c2): "; c3.print(); // Expected: 4.0 + 1.0i

    ComplexNumber c4(0.0, 0.0);
    ComplexNumber c5(5.0, 7.0);
    ComplexNumber c6 = c4 + c5;
    std::cout << "c6 (c4 + c5): "; c6.print(); // Expected: 5.0 + 7.0i

    ComplexNumber c7(-1.0, -1.0);
    ComplexNumber c8(1.0, 1.0);
    ComplexNumber c9 = c7 + c8;
    std::cout << "c9 (c7 + c8): "; c9.print(); // Expected: 0.0 + 0.0i

    return 0;
}