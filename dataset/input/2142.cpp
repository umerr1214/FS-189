#include <iostream>
#include <utility> // For std::swap
#include <cmath>   // For std::abs

// Helper function for GCD (Euclidean algorithm)
int calculate_gcd(int a, int b) {
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

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int common = calculate_gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            denominator = 1;
            numerator = 0;
        }
        simplify();
    }

    // Overload the binary * operator - SEMANTIC ERROR HERE
    // This operator modifies the 'this' object (left-hand operand) and returns a reference to it.
    // Binary multiplication operators are semantically expected to be non-mutating
    // and return a new object by value, without altering their operands.
    Fraction& operator*(const Fraction& other) { // Changed to non-const member and returns reference
        numerator = numerator * other.numerator;
        denominator = denominator * other.denominator;
        simplify(); // Simplify the modified 'this' object
        return *this; // Return reference to the modified object
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

int main() {
    Fraction f1(1, 2); // f1 = 1/2
    Fraction f2(2, 4); // f2 = 1/2
    Fraction f3(3, 5); // f3 = 3/5
    Fraction f4(10, 9); // f4 = 10/9

    std::cout << "Initial f1: " << f1 << std::endl; // 1/2
    std::cout << "Initial f2: " << f2 << std::endl; // 1/2

    // Test case 1: f1 * f2. The result is numerically correct, but f1 is modified.
    Fraction result1 = f1 * f2;
    std::cout << "f1 * f2 = " << result1 << std::endl; // Expected: 1/4. Actual: 1/4.
    std::cout << "f1 after operation: " << f1 << std::endl; // Expected to remain 1/2. Actual: 1/4 (f1 was modified!)

    std::cout << "Initial f3: " << f3 << std::endl; // 3/5
    std::cout << "Initial f4: " << f4 << std::endl; // 10/9
    
    // Test case 2: f3 * f4. The result is numerically correct, but f3 is modified.
    Fraction result2 = f3 * f4;
    std::cout << "f3 * f4 = " << result2 << std::endl; // Expected: 2/3. Actual: 2/3.
    std::cout << "f3 after operation: " << f3 << std::endl; // Expected to remain 3/5. Actual: 2/3 (f3 was modified!)

    Fraction f_zero(0, 5); // 0/1
    Fraction f_one(1, 1);  // 1/1
    std::cout << "Initial f_zero: " << f_zero << std::endl; // 0/1
    std::cout << "Initial f_one: " << f_one << std::endl;   // 1/1

    // Test case 3: f_zero * f_one. The result is numerically correct, and f_zero is modified (to the same value).
    Fraction result3 = f_zero * f_one;
    std::cout << "f_zero * f_one = " << result3 << std::endl; // Expected: 0/1. Actual: 0/1.
    std::cout << "f_zero after operation: " << f_zero << std::endl; // Expected to remain 0/1. Actual: 0/1. (Correct value, but object was mutated)

    return 0;
}