#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            // Avoid division by zero, set denominator to 1
            denominator = 1;
        }
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }
} // SYNTAX ERROR: Missing semicolon after class definition

int main() {
    int n1, d1, n2, d2;
    // Test cases for: 1/2 * 3/4, 2/3 * 5/7, 0/5 * 1/2, -1/2 * 3/4
    // Input format: n1 d1 n2 d2
    while (std::cin >> n1 >> d1 >> n2 >> d2) {
        Fraction f1(n1, d1);
        Fraction f2(n2, d2);
        Fraction f3 = f1 * f2;
        std::cout << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
    }
    return 0;
}