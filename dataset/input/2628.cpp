#include <iostream>
#include <string>
// #include <cmath> // Not used in this semantic error implementation

class ComplexNumber {
private:
    double real;
    double imag;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend std::ostream& operator<<(std::ostream& os, const ComplexNumber& c);
};

// Semantic error: The operator prints in a (real, imag) format,
// which fundamentally deviates from the requested user-friendly algebraic format (e.g., (3 + 4i)).
// It compiles and runs, but the meaning/intent of the output is incorrect.
std::ostream& operator<<(std::ostream& os, const ComplexNumber& c) {
    os << "(" << c.real << ", " << c.imag << ")";
    return os;
}

int main() {
    ComplexNumber c1(3, 4);
    ComplexNumber c2(5, -2);
    ComplexNumber c3(0, 7);
    ComplexNumber c4(-6, 0);
    ComplexNumber c5(0, 0);
    ComplexNumber c6(-1, -1);

    std::cout << "c1: " << c1 << std::endl; // Expected: (3 + 4i) -> Actual: (3, 4)
    std::cout << "c2: " << c2 << std::endl; // Expected: (5 - 2i) -> Actual: (5, -2)
    std::cout << "c3: " << c3 << std::endl; // Expected: (0 + 7i) -> Actual: (0, 7)
    std::cout << "c4: " << c4 << std::endl; // Expected: (-6 + 0i) -> Actual: (-6, 0)
    std::cout << "c5: " << c5 << std::endl; // Expected: (0 + 0i) -> Actual: (0, 0)
    std::cout << "c6: " << c6 << std::endl; // Expected: (-1 - 1i) -> Actual: (-1, -1)

    return 0;
}