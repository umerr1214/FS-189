#include <iostream>
#include <numeric> // Not used, demonstrating lack of std::gcd usage
#include <cmath>   // For std::abs if I were to use it, but I won't for robust issue

class Fraction {
public:
    long long numerator;
    long long denominator;

    Fraction(long long num = 0, long long den = 1) : numerator(num), denominator(den) {
        // Robustness Issue 1: No check for zero denominator in constructor.
        // It's allowed, and operations might fail or produce undefined behavior.
        // Robustness Issue 2: No simplification in constructor.
        // Robustness Issue 3: Denominator can be negative, leading to non-standard representation.
    }

    // Overload the * operator
    Fraction operator*(const Fraction& other) const {
        // Robustness Issue 4: Potential for very large intermediate numbers
        // if fractions aren't simplified, increasing risk of overflow if not long long.
        // (long long mitigates but doesn't eliminate for extreme cases)
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    void print() const {
        if (denominator == 0) {
            std::cout << "Undefined" << std::endl; // Robustness: print handles the invalid state
        } else {
            std::cout << numerator << "/" << denominator << std::endl;
        }
    }
};

int main() {
    Fraction f1(1, 2); Fraction f2(3, 4); Fraction f3 = f1 * f2; f3.print();
    Fraction f4(5, 10); Fraction f5(2, 3); Fraction f6 = f4 * f5; f6.print();
    Fraction f7(2, -3); Fraction f8(1, 2); Fraction f9 = f7 * f8; f9.print();
    Fraction f10(0, 5); Fraction f11(7, 8); Fraction f12 = f10 * f11; f12.print();
    Fraction f13(5, 0); f13.print();
    Fraction f14(1000000, 2000000); Fraction f15(3000000, 4000000); Fraction f16 = f14 * f15; f16.print();
    
    return 0;
}