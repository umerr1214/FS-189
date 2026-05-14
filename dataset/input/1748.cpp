#include <iostream>

class Fraction {
private:
    int num; // Using 'num' instead of 'numerator' for brevity
    int den; // Using 'den' instead of 'denominator' for brevity

public:
    // Constructor does not use a member initializer list (readability/efficiency)
    // Parameter names are short (readability)
    Fraction(int n_val, int d_val) {
        num = n_val;
        den = d_val; 
        // No validation for denominator == 0, but not the primary focus of this error type.
    }

    // Friend declaration for the overloaded operator<<
    // Takes Fraction by value (inefficient copy) and not const (readability)
    friend std::ostream& operator<<(std::ostream& os, Fraction f); 
};

// Overload the << operator to print Fraction objects
// Takes Fraction by value, causing an unnecessary copy (efficiency issue).
// Does not use 'const' for the Fraction parameter, which is bad practice as the function doesn't modify 'f' (readability issue).
std::ostream& operator<<(std::ostream& os, Fraction f) {
    os << f.num << "/" << f.den;
    return os;
}

int main() {
    // Test cases for the fraction class
    Fraction myFraction(5, 8);
    std::cout << "My Fraction: " << myFraction << std::endl;

    Fraction anotherFraction(2, 3);
    std::cout << "Another Fraction: " << anotherFraction << std::endl;

    return 0;
}