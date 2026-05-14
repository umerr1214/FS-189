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

    // SYNTAX ERROR: 'function' is not a valid keyword for operator overloading.
    // Should be 'operator-()'.
    ComplexNumber function-() const {
        return ComplexNumber(-real, -imaginary);
    }
};

int main() {
    ComplexNumber c1(3.5, -2.0);
    ComplexNumber negated_c1 = -c1; // This line will cause a compilation error due to the invalid operator definition
    std::cout << "Original: " << c1.toString() << std::endl;
    std::cout << "Negated: " << negated_c1.toString() << std::endl;

    ComplexNumber c2(-1.0, 4.0);
    ComplexNumber negated_c2 = -c2;
    std::cout << "Original: " << c2.toString() << std::endl;
    std::cout << "Negated: " << negated_c2.toString() << std::endl;

    return 0;
}