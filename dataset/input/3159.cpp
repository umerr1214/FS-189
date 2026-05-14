#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Correct implementation:
    // Overloads the unary - operator to return a new ComplexNumber object
    // with both real and imaginary parts negated.
    // The operator is marked `const` as it does not modify the original object.
    ComplexNumber operator-() const {
        return ComplexNumber(-real, -imaginary);
    }

    void print() const {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << real;
        if (imaginary >= 0) {
            std::cout << " + " << imaginary << "i";
        } else {
            std::cout << " - " << -imaginary << "i";
        }
    }
};

int main() {
    // Test case 1
    ComplexNumber c1(3.0, 4.0);
    ComplexNumber c2 = -c1;
    c2.print();
    std::cout << std::endl;

    // Test case 2
    ComplexNumber c3(-1.0, 2.5);
    ComplexNumber c4 = -c3;
    c4.print();
    std::cout << std::endl;

    // Test case 3
    ComplexNumber c5(0.0, -7.0);
    ComplexNumber c6 = -c5;
    c6.print();
    std::cout << std::endl;

    return 0;
}