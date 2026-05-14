#include <iostream>
#include <numeric> // For std::abs, std::swap
#include <cmath>   // For std::abs

class Fraction {
public:
    int numerator;
    int denominator;

    // Custom GCD implementation (for C++ versions before C++17)
    int custom_gcd(int a, int b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b) {
            a %= b;
            std::swap(a, b);
        }
        return a;
    }

    // Constructor
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // In a real application, throw an exception or handle more robustly
            denominator = 1; // Prevent division by zero, default to 1
        }
        // Ensure denominator is positive, adjust numerator sign if needed
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        simplify(); // Simplify on construction
    }

    // Simplify method
    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int common_divisor = custom_gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

    // Overload the == operator
    bool operator==(const Fraction& other) const {
        // Fractions are simplified on construction, so direct comparison is fine
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    // For outputting fractions
    void print() const {
        std::cout << numerator << "/" << denominator;
    }
} // Missing semicolon here, causing a syntax error

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 4);
    Fraction f3(1, 3);
    Fraction f4(2, 6);
    Fraction f5(3, 5);
    Fraction f6(0, 5); // Represents 0/1

    std::cout << "f1 (1/2) == f2 (2/4): " << (f1 == f2 ? "true" : "false") << std::endl; // Expected: true
    std::cout << "f1 (1/2) == f3 (1/3): " << (f1 == f3 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "f3 (1/3) == f4 (2/6): " << (f3 == f4 ? "true" : "false") << std::endl; // Expected: true
    std::cout << "f1 (1/2) == f5 (3/5): " << (f1 == f5 ? "true" : "false") << std::endl; // Expected: false
    std::cout << "f6 (0/5) == Fraction(0,1): " << (f6 == Fraction(0,1) ? "true" : "false") << std::endl; // Expected: true

    return 0;
}