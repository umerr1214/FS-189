#include <iostream>
#include <string>
#include <numeric> // For std::gcd (C++17)
#include <cmath>   // For std::abs
#include <stdexcept> // For std::invalid_argument
#include <utility> // For std::swap

// Helper function for GCD (using std::gcd for C++17, or a robust custom one)
// If not C++17, a custom robust GCD:
int find_gcd(int a, int b) {
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

    // Private helper to simplify the fraction
    void simplify() {
        if (numerator == 0) {
            denominator = 1; // 0/x simplifies to 0/1
            return;
        }

        // Use std::gcd if available (C++17), otherwise custom_gcd
        int common = find_gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // Normalize sign: ensure denominator is always positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Constructor: Validates denominator, simplifies, and normalizes
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify(); // Simplify and normalize on construction
    }

    // Overload multiplication operator (returns a new, simplified Fraction)
    Fraction operator*(const Fraction& other) const {
        // Calculate new numerator and denominator
        int newNum = numerator * other.numerator;
        int newDen = denominator * other.denominator;
        // Construct a new Fraction, which will automatically simplify
        return Fraction(newNum, newDen);
    }

    // Accessors with const correctness
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Overload the stream insertion operator for easy printing
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
};

int main() {
    // The driver will create Fraction objects and call operator* and print using operator<<.
    // Example usage:
    // Fraction f1(1, 2);
    // Fraction f2(2, 3);
    // Fraction result = f1 * f2;
    // std::cout << result << std::endl; // Expected: 1/3
    //
    // try {
    //     Fraction f_invalid(1, 0); // Should throw
    // } catch (const std::invalid_argument& e) {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    // }
    return 0;
}