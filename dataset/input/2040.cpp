#include <iostream>
#include <string>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    // Semantic Error: Declares operator<< to return std::ostream by value instead of std::ostream& by reference.
    friend std::ostream operator<<(std::ostream& os, const ComplexNumber& cn);
};

// Semantic Error: The operator returns std::ostream by value, not by reference.
// While it might compile and print correctly for single insertions, this is semantically
// incorrect for stream operators, can prevent proper chaining, and is inefficient.
std::ostream operator<<(std::ostream& os, const ComplexNumber& cn) {
    os << cn.real;
    if (cn.imaginary >= 0) {
        os << " + " << cn.imaginary << "i";
    } else {
        os << " - " << -cn.imaginary << "i";
    }
    return os; // Returns a copy of the ostream
}

int main() {
    ComplexNumber c1(3.0, 4.5);
    ComplexNumber c2(2.0, -1.5);
    ComplexNumber c3(0.0, 7.0);
    ComplexNumber c4(5.0, 0.0);
    ComplexNumber c5(-1.0, -2.0);
    ComplexNumber c6(0.0, 0.0);

    std::cout << "c1: " << c1 << std::endl;
    std::cout << "c2: " << c2 << std::endl;
    std::cout << "c3: " << c3 << std::endl;
    std::cout << "c4: " << c4 << std::endl;
    std::cout << "c5: " << c5 << std::endl;
    std::cout << "c6: " << c6 << std::endl;

    // This chaining might work in simple cases, but it operates on temporary ostream objects
    // due to the return-by-value, which is semantically incorrect for stream operators.
    std::cout << "Chained output: " << c1 << " and " << c2 << std::endl;

    return 0;
}