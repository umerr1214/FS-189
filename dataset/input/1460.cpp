#include <iostream>
#include <string>
#include <numeric> // For std::gcd in C++17, or custom gcd
#include <cmath>   // For std::abs
#include <utility> // For std::swap

// Inefficient GCD implementation (subtraction-based Euclidean algorithm)
// This is less efficient than the modulo-based version for large numbers.
int get_gcd(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (a != b) { // Inefficient loop
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

class Fraction {
private:
    int n; // Poor variable name for numerator
    int d; // Poor variable name for denominator

public:
    // Constructor: Simplifies and normalizes, but uses inefficient GCD
    Fraction(int num = 0, int den = 1) : n(num), d(den) {
        if (d == 0) {
            std::cerr << "Error: Denominator cannot be zero. Setting to 1." << std::endl;
            d = 1; // Correctly handles zero denominator, but prints to cerr
        }
        simplify_me(); // Calls the simplification method
    }

    // Member function to simplify the fraction
    void simplify_me() { // Poor function name
        if (n == 0) {
            d = 1;
            return;
        }
        int common = get_gcd(n, d); // Uses inefficient GCD
        n /= common;
        d /= common;

        // Normalize sign: ensure denominator is always positive
        if (d < 0) {
            n = -n;
            d = -d;
        }
    }

    // Overload multiplication operator
    // Lacks const correctness for the 'other' parameter
    Fraction operator*(Fraction other) { // `other` should ideally be `const Fraction&`
        int res_n = n * other.n; // Poor variable names
        int res_d = d * other.d;
        Fraction res(res_n, res_d); // Creates a new fraction
        res.simplify_me(); // Simplifies the result
        return res;
    }

    // Method to print the fraction
    // No const correctness for print method
    void print() {
        std::cout << n << "/" << d;
    }

    // Accessors - lack const correctness
    int getNum() { return n; } // Poor name, no const
    int getDen() { return d; } // Poor name, no const
};

int main() {
    // The driver will create Fraction objects and call operator* and print.
    // Example usage:
    // Fraction f1(1, 2);
    // Fraction f2(2, 3);
    // Fraction result = f1 * f2;
    // result.print(); // Expected: 1/3 (simplified)
    // std::cout << std::endl;
    return 0;
}