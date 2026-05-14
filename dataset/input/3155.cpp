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

    // LOGICAL ERROR: Only the real part is negated, the imaginary part is returned unchanged.
    ComplexNumber operator-() const {
        return ComplexNumber(-real, imaginary); // Should be -imaginary
    }
};

int main() {
    ComplexNumber c1(3.5, -2.0);
    ComplexNumber negated_c1 = -c1;
    std::cout << "Original: " << c1.toString() << std::endl; // Expected: 3.5 - 2.0i
    std::cout << "Negated (expected -3.5 + 2.0i): " << negated_c1.toString() << std::endl; // Actual: -3.5 - 2.0i

    ComplexNumber c2(-1.0, 4.0);
    ComplexNumber negated_c2 = -c2;
    std::cout << "Original: " << c2.toString() << std::endl; // Expected: -1.0 + 4.0i
    std::cout << "Negated (expected 1.0 - 4.0i): " << negated_c2.toString() << std::endl; // Actual: 1.0 + 4.0i

    ComplexNumber c3(0.0, 0.0);
    ComplexNumber negated_c3 = -c3;
    std::cout << "Original: " << c3.toString() << std::endl; // Expected: 0.0 + 0.0i
    std::cout << "Negated (expected 0.0 + 0.0i): " << negated_c3.toString() << std::endl; // Actual: 0.0 + 0.0i

    return 0;
}