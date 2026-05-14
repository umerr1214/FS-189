#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) {
        if (denominator == 0) {
            denominator = 1;
        }
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // SEMANTIC ERROR: The multiplication operator modifies the left-hand operand (`this`)
    // instead of returning a new Fraction object without altering the operands.
    // This violates the expected behavior of a binary multiplication operator.
    Fraction operator*(const Fraction& other) { // Note: method is not const-qualified
        this->numerator *= other.numerator;     // Modifies the current object
        this->denominator *= other.denominator; // Modifies the current object
        return *this; // Returns a copy of the modified current object
    }
};

int main() {
    int n1, d1, n2, d2;
    // Test cases for: 1/2 * 3/4, 2/3 * 5/7, 0/5 * 1/2, -1/2 * 3/4
    // Input format: n1 d1 n2 d2
    while (std::cin >> n1 >> d1 >> n2 >> d2) {
        Fraction f1(n1, d1); // Example: f1 = 1/2
        Fraction f2(n2, d2); // Example: f2 = 3/4
        Fraction f3 = f1 * f2; // This will set f1 to 3/8, and f3 will be 3/8.
                               // The output for f3 will be correct, but f1's state is mutated.
        std::cout << f3.getNumerator() << "/" << f3.getDenominator() << std::endl;
    }
    return 0;
}