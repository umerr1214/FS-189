#include <iostream>
#include <string>
#include <numeric> // For std::gcd in C++17, or implement one
#include <cmath>   // For std::abs
#include <utility> // For std::swap

// Custom GCD implementation (for robustness, not necessarily efficient)
int custom_gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor: Does NOT validate denominator or simplify
    // Robustness issue: Allows denominator to be 0, creating an invalid fraction state.
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        // No validation for denominator == 0
        // No simplification or normalization here
    }

    // Overload multiplication operator
    // Robustness issue: Does NOT simplify the result.
    // This can lead to numerators/denominators growing excessively large,
    // potentially causing integer overflow for complex calculations.
    Fraction operator*(const Fraction& other) const {
        int newNum = numerator * other.numerator;
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen); // Returns unsimplified fraction
    }

    // Method to simplify the fraction (exists but not called by operator* or constructor)
    // If denominator is 0, it won't crash but won't simplify either,
    // leaving the fraction in an invalid state.
    void simplify() {
        if (denominator == 0) {
            // Cannot simplify if denominator is 0, but doesn't crash here.
            return;
        }
        if (numerator == 0) {
            denominator = 1; // 0/x simplifies to 0/1
            return;
        }

        int common = custom_gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // Normalize sign: ensure denominator is always positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Method to print the fraction
    // Prints the fraction as is, without simplifying the object itself.
    // If the fraction is 1/0, it will print "1/0".
    void print() {
        std::cout << numerator << "/" << denominator;
    }

    // Accessors (for completeness, not directly used by driver for output)
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

int main() {
    // The driver will create Fraction objects and call operator* and print.
    // Example usage for demonstration:
    // Fraction f1(1, 2);
    // Fraction f2(2, 3);
    // Fraction result = f1 * f2;
    // result.print(); // Expected: 2/6 (unsimplified)
    // std::cout << std::endl;

    // Fraction invalid_f(5, 0);
    // invalid_f.print(); // Expected: 5/0 (invalid state printed)
    // std::cout << std::endl;

    return 0;
}