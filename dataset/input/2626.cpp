#include <iostream>
#include <string>
#include <cmath> // For std::abs if used in correct implementation

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Friend declaration for operator<<
    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
} // SYNTAX ERROR: Missing semicolon here!

// Definition of the friend operator<< (assuming it would be correct if compiled)
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << "(" << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i)";
    } else {
        os << " - " << std::abs(c.imag) << "i)";
    }
    return os;
}

int main() {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(5, -2);
    ComplexNumber c3(0, 7);
    ComplexNumber c4(-6, 0);
    ComplexNumber c5(0, 0);
    ComplexNumber c6(-1, -1);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c6: " << c6 << std::endl;

    return 0;
}