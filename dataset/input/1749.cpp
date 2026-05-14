#include <iostream>
#include <stdexcept> // Required for std::invalid_argument

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor uses a member initializer list and performs validation/normalization.
    Fraction(int num, int den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        // Normalize sign: ensure denominator is always positive.
        // If denominator is negative, flip signs of both numerator and denominator.
        if (this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
    }

    // Friend declaration for the overloaded operator<<
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

// Overload the << operator to print Fraction objects
// Takes const Fraction& by reference (efficient and correct) and returns std::ostream&.
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main() {
    // Test valid fractions
    try {
        Fraction f1(3, 4);
        std::cout << "Fraction 1: " << f1 << std::endl; // Expected: 3/4

        Fraction f2(5, -8); // Test sign normalization: 5/-8 should become -5/8
        std::cout << "Fraction 2: " << f2 << std::endl; // Expected: -5/8

        Fraction f3(0, 7);
        std::cout << "Fraction 3: " << f3 << std::endl; // Expected: 0/7
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Test robustness for denominator being zero (should throw an exception)
    try {
        Fraction f_invalid(1, 0); // This should throw an exception
        std::cout << "Fraction Invalid: " << f_invalid << std::endl; // This line should not be reached
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl; // Expected: Error: Denominator cannot be zero.
    }

    return 0;
}