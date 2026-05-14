#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Constructor does not validate denominator, allowing it to be zero.
    // This is a robustness issue as 1/0 is an invalid mathematical fraction.
    Fraction(int num, int den) {
        numerator = num;
        denominator = den; 
    }

    // Friend declaration for the overloaded operator<<
    friend std::ostream& operator<<(std::ostream& os, const Fraction& f);
};

// Overload the << operator to print Fraction objects
// It simply prints the stored values, including potentially invalid ones like N/0.
std::ostream& operator<<(std::ostream& os, const Fraction& f) {
    os << f.numerator << "/" << f.denominator;
    return os;
}

int main() {
    // Test case demonstrating the robustness issue: denominator is 0
    // The program creates an invalid fraction without error handling.
    Fraction f1(1, 0); 
    std::cout << "Fraction 1: " << f1 << std::endl; // Outputs 1/0

    // Another valid fraction for comparison
    Fraction f2(3, 4);
    std::cout << "Fraction 2: " << f2 << std::endl;

    return 0;
}