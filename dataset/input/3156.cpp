#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    std::string toString() const {
        std::stringstream ss;
        ss << std::fixed << std::setprecision(1);
        ss << real;
        if (imaginary >= 0) {
            ss << " + " << imaginary << "i";
        } else {
            ss << " - " << -imaginary << "i";
        }
        return ss.str();
    }

    // SEMANTIC ERROR: This operator modifies the 'this' object directly instead of
    // returning a new, negated ComplexNumber. Unary '-' should not have side effects
    // on its operand, similar to how -5 does not change the value of 5.
    // The 'const' keyword is also removed, which is necessary to allow modification of 'this'.
    ComplexNumber operator-() { // Should be 'ComplexNumber operator-() const' and return a new object
        real = -real;
        imaginary = -imaginary;
        return *this; // Returns the modified current object
    }
};

int main() {
    ComplexNumber c1(3.5, -2.0);
    std::cout << "Original c1: " << c1.toString() << std::endl; // Expected: 3.5 - 2.0i
    ComplexNumber negated_c1 = -c1;
    std::cout << "Negated_c1: " << negated_c1.toString() << std::endl; // Correct output for negated_c1 (-3.5 + 2.0i)
    std::cout << "c1 after negation: " << c1.toString() << std::endl; // ACTUAL: -3.5 + 2.0i (c1 itself was modified, which is a semantic error)

    ComplexNumber c2(-1.0, 4.0);
    std::cout << "Original c2: " << c2.toString() << std::endl; // Expected: -1.0 + 4.0i
    ComplexNumber negated_c2 = -c2;
    std::cout << "Negated_c2: " << negated_c2.toString() << std::endl; // Correct output for negated_c2 (1.0 - 4.0i)
    std::cout << "c2 after negation: " << c2.toString() << std::endl; // ACTUAL: 1.0 - 4.0i (c2 itself was modified)

    return 0;
}