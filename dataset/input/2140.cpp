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

    Fraction operator*(const Fraction& other) const {
        int new_num = numerator * other.numerator;
        int new_den = denominator * other.denominator;
        return Fraction(new_num, new_den);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    Fraction f1(1, 2);
    Fraction f2(2, 4); 
    Fraction f3(3, 5);
    Fraction f4(10, 9);

    std::cout << "f1: " << f1 << std::endl;
    std::cout << "f2: " << f2 << std::endl;
    std::cout << "f3: " << f3 << std::endl;
    std::cout << "f4: " << f4 << std::endl;

    Fraction result1 = f1 * f2;
    std::cout << "f1 * f2 = " << result1 << std::endl;

    Fraction result2 = f3 * f4;
    std::cout << "f3 * f4 = " << result2 << std::endl;
    
    Fraction f_zero(0, 5);
    Fraction result3 = f_zero * f1;
    std::cout << "0/5 * 1/2 = " << result3 << std::endl;

    return 0;
}