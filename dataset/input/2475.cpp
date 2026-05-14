#include <iostream>
#include <numeric>   // For std::gcd (C++17) - or custom if not available
#include <cmath>     // For std::abs
#include <stdexcept> // For std::runtime_error
#include <utility>   // For std::swap

// Helper function to calculate Greatest Common Divisor (GCD)
// Ensures positive result for simplification
long long calculateGcd(long long a, long long b) {
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
    long long numerator_;
    long long denominator_;

    // Private helper to simplify the fraction to its lowest terms
    // and ensure the denominator is always positive.
    void simplify() {
        if (denominator_ == 0) {
            // This state should ideally be prevented by constructor/setters
            // If reached, it's an internal error or a logic flaw.
            // For now, we'll let the constructor handle this via exception.
            return;
        }
        if (numerator_ == 0) {
            denominator_ = 1; // Normalize 0/X to 0/1
            return;
        }

        long long common_divisor = calculateGcd(numerator_, denominator_);
        numerator_ /= common_divisor;
        denominator_ /= common_divisor;

        // Ensure denominator is always positive.
        // If denominator is negative, move the sign to the numerator.
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }
    }

public:
    // Constructor
    Fraction(long long num = 0, long long den = 1) : numerator_(num), denominator_(den) {
        if (denominator_ == 0) {
            throw std::runtime_error("Fraction: Denominator cannot be zero.");
        }
        simplify(); // Simplify upon construction
    }

    // Getter methods for read-only access
    long long getNumerator() const { return numerator_; }
    long long getDenominator() const { return denominator_; }

    // Overload the * operator to multiply two Fraction objects
    // Returns a new Fraction object.
    // Uses const reference for efficiency and correctness.
    Fraction operator*(const Fraction& other) const {
        // Multiply numerators and denominators
        long long result_num = numerator_ * other.numerator_;
        long long result_den = denominator_ * other.denominator_;

        // The constructor of the returned Fraction will handle simplification
        // and sign normalization automatically.
        return Fraction(result_num, result_den);
    }

    // Method to print the fraction to standard output
    void print() const {
        std::cout << numerator_ << "/" << denominator_ << std::endl;
    }
};

int main() {
    // Comprehensive test cases for the Fraction class
    try {
        Fraction f1(1, 2); Fraction f2(3, 4); Fraction f3 = f1 * f2; f3.print();
        Fraction f4(5, 10); Fraction f5(2, 3); Fraction f6 = f4 * f5; f6.print();
        Fraction f7(2, -3); Fraction f8(1, 2); Fraction f9 = f7 * f8; f9.print();
        Fraction f10(0, 5); Fraction f11(7, 8); Fraction f12 = f10 * f11; f12.print();
        Fraction f13(-1, 3); Fraction f14(-2, 5); Fraction f15 = f13 * f14; f15.print();
        Fraction f16(123456789, 987654321); Fraction f17(246813579, 753951824); Fraction f18 = f16 * f17; f18.print();
        Fraction f19(5); Fraction f20(2, 7); Fraction f21 = f19 * f20; f21.print();
        // Uncomment the line below to test exception handling for zero denominator
        // Fraction f_error(5, 0); f_error.print(); 

    } catch (const std::runtime_error& e) {
        std::cerr << "Caught Error: " << e.what() << std::endl;
    }
    return 0;
}