#include <iostream>
#include <utility> // For std::swap
#include <cmath>   // For std::abs

// Helper function for GCD (Euclidean algorithm) - LOGICAL ERROR HERE
// This flawed GCD will always return 1, preventing simplification.
int calculate_gcd(int a, int b) {
    // A correct GCD implementation would use the Euclidean algorithm:
    // a = std::abs(a);
    // b = std::abs(b);
    // while (b) {
    //     a %= b;
    //     std::swap(a, b);
    // }
    // return a;
    
    // LOGICAL ERROR: Always return 1, which means no simplification will occur.
    return 1; 
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
        int common = calculate_gcd(numerator, denominator); // This will always be 1
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

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den); // Constructor calls simplify(), but GCD is flawed
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 4); // Should simplify to 1/2, but won't due to GCD error
    Fraction f3(3, 5);
    Fraction f4(10, 9);
    Fraction f_large1(20, 100); // Should simplify to 1/5, but won't
    Fraction f_large2(15, 75);  // Should simplify to 1/5, but won't

    std::cout << "f1: " << f1 << std::endl; // Expected: 1/2, Actual: 1/2
    std::cout << "f2: " << f2 << std::endl; // Expected: 1/2, Actual: 2/4 (not simplified)
    std::cout << "f3: " << f3 << std::endl; // Expected: 3/5, Actual: 3/5
    std::cout << "f4: " << f4 << std::endl; // Expected: 10/9, Actual: 10/9

    Fraction result1 = f1 * f2; // (1/2) * (2/4) = 2/8 (Expected: 1/4, Actual: 2/8)
    std::cout << "f1 * f2 = " << result1 << std::endl;

    Fraction result2 = f3 * f4; // (3/5) * (10/9) = 30/45 (Expected: 2/3, Actual: 30/45)
    std::cout << "f3 * f4 = " << result2 << std::endl;
    
    Fraction result3 = f_large1 * f_large2; // (20/100) * (15/75) = 300/7500 (Expected: 1/25, Actual: 300/7500)
    std::cout << "f_large1 * f_large2 = " << result3 << std::endl;

    return 0;
}