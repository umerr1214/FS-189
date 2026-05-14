#include <iostream>
#include <numeric> // For std::gcd in C++17
#include <cmath>   // For std::abs

class Fraction {
public:
    int numerator;
    int denominator;

    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // Handle division by zero: set denominator to 1 for simplicity
            denominator = 1;
        }
        simplify();
    }

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        // Use std::abs for GCD to handle negative numbers correctly
        int common = std::gcd(std::abs(numerator), std::abs(denominator));
        numerator /= common;
        denominator /= common;
        // Ensure denominator is always positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Overload * operator to multiply two Fraction objects
    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den); // Simplification happens in constructor
    }

    // Friend function to allow easy printing of Fraction objects
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // Test cases
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 * f2; // Expected: 3/8
    std::cout << f1 << " * " << f2 << " = " << f3 << std::endl;

    Fraction f4(2, 3);
    Fraction f5(3, 2);
    Fraction f6 = f4 * f5; // Expected: 1/1
    std::cout << f4 << " * " << f5 << " = " << f6 << std::endl;

    Fraction f7(-1, 2);
    Fraction f8(1, -2);
    Fraction f9 = f7 * f8; // Expected: 1/4
    std::cout << f7 << " * " << f8 << " = " << f9 << std::endl;

    Fraction f10(0, 5);
    Fraction f11(7, 8);
    Fraction f12 = f10 * f11; // Expected: 0/1
    std::cout << f10 << " * " << f11 << " = " << f12 << std::endl;

    return 0;
}