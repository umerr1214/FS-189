#include <iostream>
#include <string>
// #include <cmath> // Not used in this logical error implementation

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Logical error: Always prints '+' sign, even if imaginary part is negative
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << "(" << c.real;
    // This logic will print "(5 + -2i)" instead of "(5 - 2i)"
    os << " + " << c.imag << "i)";
    return os;
}

int main() {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(5, -2);
    ComplexNumber c3(0, 7);
    ComplexNumber c4(-6, 0);
    ComplexNumber c5(0, 0);
    ComplexNumber c6(-1, -1);

    std::cout << "c1: " << c1 << std::endl; // Expected: (3 + 4i)
    std::cout << "c2: " << c2 << std::endl; // Expected: (5 - 2i) -> Actual: (5 + -2i)
    std::cout << "c3: " << c3 << std::endl; // Expected: (0 + 7i)
    std::cout << "c4: " << c4 << std::endl; // Expected: (-6 + 0i)
    std::cout << "c5: " << c5 << std::endl; // Expected: (0 + 0i)
    std::cout << "c6: " << c6 << std::endl; // Expected: (-1 - 1i) -> Actual: (-1 + -1i)

    return 0;
}