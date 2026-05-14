#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

class ComplexNumber {
public:
    double real;
    double imaginary;

    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Robustness Issue:
    // This operator modifies the current object instead of returning a new,
    // negated copy. This violates the expectation of unary minus being
    // a non-mutating operation and the problem statement "return a new ComplexNumber".
    // Also, it's not marked 'const' because it modifies 'this'.
    ComplexNumber operator-() {
        this->real = -this->real;
        this->imaginary = -this->imaginary;
        return *this; // Returns the modified current object
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
    ComplexNumber c2 = -c1; // c1 is modified to -3.0 - 4.0i, c2 also becomes -3.0 - 4.0i
    c2.print();
    std::cout << std::endl;

    // Test case 2
    ComplexNumber c3(-1.0, 2.5);
    ComplexNumber c4 = -c3; // c3 is modified to 1.0 - 2.5i, c4 also becomes 1.0 - 2.5i
    c4.print();
    std::cout << std::endl;

    // Test case 3
    ComplexNumber c5(0.0, -7.0);
    ComplexNumber c6 = -c5; // c5 is modified to 0.0 + 7.0i, c6 also becomes 0.0 + 7.0i
    c6.print();
    std::cout << std::endl;

    return 0;
}