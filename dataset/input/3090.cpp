#include <iostream>
#include <numeric> // For std::gcd in C++17
#include <cmath>   // For std::abs

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function for GCD
    int calculateGCD(int a, int b) const {
        return std::gcd(a, b);
    }

    void simplify() {
        if (denominator == 0) return;
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int common_divisor = calculateGCD(std::abs(numerator), std::abs(denominator));
        numerator /= common_divisor;
        denominator /= common_divisor;

        // Ensure denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero. Setting to 1." << std::endl;
            this->denominator = 1;
        }
        simplify();
    }

    void print() const {
        std::cout << numerator << "/" << denominator;
    }

    // SEMANTIC ERROR: The binary '*' operator is overloaded as a MEMBER function
    // instead of a non-member (friend) function, as explicitly required by the question.
    // While this compiles and works for Fraction * Fraction, it violates the design
    // specification for operator overloading, which typically prefers non-member for
    // binary arithmetic operators to maintain symmetry (e.g., if one operand was an int).
    Fraction operator*(const Fraction& other) const {
        int num = this->numerator * other.numerator;
        int den = this->denominator * other.denominator;
        Fraction result(num, den); // Constructor will simplify
        return result;
    }
};

// No global operator* is defined here, as it's now a member function.

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 * f2; // This calls f1.operator*(f2)

    f1.print();
    std::cout << " * ";
    f2.print();
    std::cout << " = ";
    f3.print();
    std::cout << std::endl;

    Fraction f4(2, 3);
    Fraction f5(3, 2);
    Fraction f6 = f4 * f5;
    f4.print();
    std::cout << " * ";
    f5.print();
    std::cout << " = ";
    f6.print();
    std::cout << std::endl;

    Fraction f7(0, 5);
    Fraction f8(10, 2);
    Fraction f9 = f7 * f8;
    f7.print();
    std::cout << " * ";
    f8.print();
    std::cout << " = ";
    f9.print();
    std::cout << std::endl;

    return 0;
}