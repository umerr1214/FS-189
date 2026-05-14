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

        // LOGICAL ERROR: Not ensuring denominator is always positive.
        // If denominator becomes negative after simplification, it should be flipped
        // along with the numerator to maintain a canonical representation (e.g., 1/-2 should be -1/2).
        // The correct logic (commented out below) is missing.
        /*
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        */
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

    // Friend declaration for operator*
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
};

// Overload the binary * operator as a non-member (friend) function
Fraction operator*(const Fraction& f1, const Fraction& f2) {
    int num = f1.numerator * f2.numerator;
    int den = f1.denominator * f2.denominator;
    Fraction result(num, den); // Constructor will call simplify (with the bug)
    return result;
}

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);
    Fraction f3 = f1 * f2;
    f1.print(); std::cout << " * "; f2.print(); std::cout << " = "; f3.print(); std::cout << std::endl; // Expected: 3/8

    Fraction f4(2, 3);
    Fraction f5(3, 2);
    Fraction f6 = f4 * f5;
    f4.print(); std::cout << " * "; f5.print(); std::cout << " = "; f6.print(); std::cout << std::endl; // Expected: 1/1

    Fraction f7(0, 5);
    Fraction f8(10, 2);
    Fraction f9 = f7 * f8;
    f7.print(); std::cout << " * "; f8.print(); std::cout << " = "; f9.print(); std::cout << std::endl; // Expected: 0/1

    // Test case to expose the logical error: negative denominator
    Fraction f10(1, -2); // Should be simplified to -1/2 by convention
    f10.print(); std::cout << std::endl; // Actual output: 1/-2 (Incorrect canonical form)

    Fraction f11(-1, 2);
    Fraction f12(1, -2);
    Fraction f13 = f11 * f12; // Expected: (-1/2) * (-1/2) = 1/4
    f11.print(); std::cout << " * "; f12.print(); std::cout << " = "; f13.print(); std::cout << std::endl; // Actual output: -1/2 * 1/-2 = -1/-4 (Incorrect canonical form)

    return 0;
}