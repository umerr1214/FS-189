#include <iostream>
#include <sstream>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Overload + operator incorrectly performs subtraction
    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real - other.real, imaginary - other.imaginary); // Logical error: should be '+'
    }
};

void run_test(double r1, double i1, double r2, double i2) {
    ComplexNumber c1(r1, i1);
    ComplexNumber c2(r2, i2);
    ComplexNumber c3 = c1 + c2;

    std::ostringstream oss;
    oss << c3.getReal() << " " << c3.getImaginary();
    std::cout << oss.str() << std::endl;
}

int main() {
    run_test(1.0, 2.0, 3.0, 4.0);
    run_test(5.0, -1.0, 2.5, 3.0);
    run_test(-10.0, 0.0, 5.0, -5.0);
    return 0;
}